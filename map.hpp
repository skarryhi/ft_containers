#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include <iterator>

namespace ft {

    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };

    template < class Key, class T, class Compare = std::less<Key>,
            class Alloc = std::allocator<std::pair<const Key, T> > >
    class map {
    public:
        //nickname
        class allocator;
        class pair;
        class iterator;
        class const_iterator;
        class reverse_iterator;
        class const_reverse_iterator;

        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef size_t size_type;
        typedef Alloc allocator_type;
        typedef ptrdiff_t difference_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;

        class value_compare : public std::binary_function<value_type, value_type, bool> {
        public:
            key_compare comp;
            explicit value_compare(key_compare c) : comp(c) {};
            bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); };
        };

        typedef struct Node {
            struct Node *left;
            struct Node *right;
            struct Node *parent;
            value_type *content;
        } node;
        node *_begin;
    private:


        typedef typename allocator_type::template rebind<node>::other allocator_rebind_type;
        allocator_rebind_type _allocator_rebind;
        key_compare _compare;
        allocator_type _alloc;
        size_type _size;
        node *_end;
        struct Node *_root;


        node  *newEmptyNode() {
            node  *newNode = _allocator_rebind.allocate(1);
            newNode->parent = nullptr;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->content = nullptr;
            return newNode;
        }

        node *newNode(value_type const& value) {
            node  *newNode = _allocator_rebind.allocate(1);
            newNode->parent = nullptr;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->content = _alloc.allocate(1);
            _alloc.construct(newNode->content, value);
            ++_size;
            return newNode;
        }

        void    deleteNode(node *oldNode) {
            _alloc.desroy(oldNode->content);
            _alloc.deallocate(oldNode->content, 1);
            _alloc.deallocate(oldNode, 1);
            --_size;
        }

    public:

        explicit map (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type()) : _size(0), _compare(comp), _alloc(alloc) {
            _begin = newEmptyNode();
            _end = newEmptyNode();
            _root = _begin;
        }

//        template <class InputIterator>
//        map (InputIterator first, InputIterator last,
//             const key_compare& comp = key_compare(),
//             const allocator_type& alloc = allocator_type());
//        map (const map& x);

        bool empty() const { return !_size;}
        size_type size() const { return _size;}
        size_type max_size() const { return -1 / sizeof(reference);}// TODO not work

        mapped_type& operator[] (const key_type& k) {
            return insert(std::make_pair(k, mapped_type())).first->second;
        }

        std::pair<iterator,bool>    insert(const value_type& val) {
            map::iterator it = end();
            bool change = false;
            struct Node *tmp = _root;
            if (_root == _begin) {
                _root = newNode(val);
                _begin->parent = _root;
                _end->parent = _root;
                _root->left = _begin;
                _root->right = _end;
                it = iterator(_root);
            }
            while (it == end()) {
                if (_compare(val.first, tmp->content->first)) {
                    if (!_compare(tmp->content->first, val.first)) {
                        if (tmp->left == _begin || tmp->left == nullptr) {
                            if (tmp->left == _begin) {
                                tmp->left = newNode(val);
                                _begin->parent = tmp->left;
                                it = iterator(tmp->left);
                                change = true;
                                tmp->left->left = _begin;
                            } else {
                                tmp->left = newNode(val);
                                it = iterator(tmp->left);
                                change = true;
                                tmp->left->left = nullptr;
                            }
                            tmp->left->parent = tmp;
                        } else
                            tmp = tmp->left;
                    }
                }
                else if (_compare(tmp->content->first, val.first)) {
                    if (!_compare(val.first, tmp->content->first)) {
                        if (tmp->right == _end || tmp->right == nullptr) {
                            if (tmp->right == _end) {
                                tmp->right = newNode(val);
                                _end->parent = tmp->right;
                                it = iterator(tmp->right);
                                tmp->right->right = _end;
                                change = true;
                            } else {
                                tmp->right = newNode(val);
                                it = iterator(tmp->right);
                                change = true;
                                tmp->right->right = nullptr;
                            }
                            tmp->right->parent = tmp;
                        } else
                            tmp = tmp->right;
                    }
                }
                else
                    it = iterator(tmp);
            }
            return std::make_pair(it, change);
        }

//        iterator insert (iterator position, const value_type& val) {}
//
//        template <class InputIterator>
//        void insert (InputIterator first, InputIterator last) {}

        class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
        private:
            node *_node;
            struct Node *_prev;
            struct Node *_next;
        public:

            explicit iterator(node *pointer = nullptr) : _node(pointer), _prev(nullptr), _next(nullptr) {}
            iterator(iterator const &other) { *this = other; }
            ~iterator() {}

            iterator &operator=(iterator const &other) {
                _node = other._node;
                _prev = other._prev;
                _next = other._next;
                return (*this);
            }

            bool operator==(iterator const &other) { return other._node == _node; }
            bool operator!=(iterator const &other) { return other._node != _node; }
            bool operator==(const_iterator const& other) {return other.getElement() == _node;}
            bool operator!=(const_iterator const& other) {return other.getElement()!= _node;}

            iterator &operator--() {
                if (_node->left) {
                    _next = _node;
                    _node = _node->left;
                    while (_node->right != nullptr)
                        _node = _node->right;
                }
                else {
                    while (_node == _node->parent->left)
                        _node = _node->parent;
                    _node = _node->parent;
                    if (_node == _next)
                        _node = _node->parent;
                }
                return *this;
            }
            iterator &operator++() {
                if (_node->right) {
                    _prev = _node;
                    _node = _node->right;
                    while (_node->left != nullptr)
                        _node = _node->left;
                }
                else {
                    while (_node == _node->parent->right)
                        _node = _node->parent;
                    _node = _node->parent;
                    if (_node == _prev)
                        _node = _node->parent;
                }
                return *this;
            }
            iterator operator++(int) { iterator temp(_node); operator++(); return temp;}
            iterator operator--(int) { iterator temp(_node); operator--(); return temp;}


            value_type &operator*() const { return *_node; }
            value_type *operator->() const { return _node->content; }
            node *getNode() const { return _node; }
        };
        iterator begin() { return(iterator(_begin->parent));}
        iterator end() {return(iterator(_end));}

        class const_iterator : public std::iterator<std::bidirectional_iterator_tag, const value_type> {
        private:
            node *_node;
            struct Node *_prev;
            struct Node *_next;
        public:

            explicit const_iterator(node *pointer = nullptr) : _node(pointer), _prev(nullptr), _next(nullptr) {}
            const_iterator(const_iterator const &other) { *this = other; }
            const_iterator(iterator const& other) {*this = other;}
            ~const_iterator() {}

            const_iterator &operator=(const_iterator const &other) {
                _node = other._node;
                _prev = other._prev;
                _next = other._next;
                return (*this);
            }
            const_iterator&    operator=(iterator const& other) {
                _node = other.getElement();
                return (*this);
            }

            bool operator==(iterator const &other) { return other._node == _node; }
            bool operator!=(iterator const &other) { return other._node != _node; }
            bool operator==(const_iterator const& other) {return other.getElement() == _node;}
            bool operator!=(const_iterator const& other) {return other.getElement()!= _node;}

            const_iterator &operator--() {
                if (_node->left) {
                    _next = _node;
                    _node = _node->left;
                    while (_node->right != nullptr)
                        _node = _node->right;
                }
                else {
                    while (_node == _node->parent->left)
                        _node = _node->parent;
                    _node = _node->parent;
                    if (_node == _next)
                        _node = _node->parent;
                }
                return *this;
            }
            const_iterator &operator++() {
                if (_node->right) {
                    _prev = _node;
                    _node = _node->right;
                    while (_node->left != nullptr)
                        _node = _node->left;
                }
                else {
                    while (_node == _node->parent->right)
                        _node = _node->parent;
                    _node = _node->parent;
                    if (_node == _prev)
                        _node = _node->parent;
                }
                return *this;
            }
            const_iterator operator++(int) { const_iterator temp(_node); operator++(); return temp;}
            const_iterator operator--(int) { const_iterator temp(_node); operator--(); return temp;}


            value_type &operator*() const { return *_node; }
            value_type *operator->() const { return _node->content; }
            node *getNode() const { return _node; }
        };
        const_iterator begin() const { return(const_iterator(_begin->parent));}
        const_iterator end() const {return(const_iterator(_end));}

        class reverse_iterator : public std::reverse_iterator<iterator> {
        private:
            node *_node;
            struct Node *_prev;
            struct Node *_next;
        public:

            explicit reverse_iterator(node *pointer = nullptr) : _node(pointer), _prev(nullptr), _next(nullptr) {}
            reverse_iterator(reverse_iterator const &other) { *this = other; }
            ~reverse_iterator() {}

            reverse_iterator &operator=(reverse_iterator const &other) {
                _node = other._node;
                _prev = other._prev;
                _next = other._next;
                return (*this);
            }

            bool operator==(reverse_iterator const &other) { return other._node == _node; }
            bool operator!=(reverse_iterator const &other) { return other._node != _node; }
            bool operator==(const_reverse_iterator const& other) {return other.getElement() == _node;}
            bool operator!=(const_reverse_iterator const& other) {return other.getElement()!= _node;}

            reverse_iterator &operator--() {
                if (_node->right) {
                    _prev = _node;
                    _node = _node->right;
                    while (_node->left != nullptr)
                        _node = _node->left;
                }
                else {
                    while (_node == _node->parent->right)
                        _node = _node->parent;
                    _node = _node->parent;
                    if (_node == _prev)
                        _node = _node->parent;
                }
                return *this;
            }
            reverse_iterator &operator++() {
                if (_node->left) {
                    _next = _node;
                    _node = _node->left;
                    while (_node->right != nullptr)
                        _node = _node->right;
                }
                else {
                    while (_node == _node->parent->left)
                        _node = _node->parent;
                    _node = _node->parent;
                    if (_node == _next)
                        _node = _node->parent;
                }
                return *this;
            }
            reverse_iterator operator++(int) { reverse_iterator temp(_node); operator++(); return temp;}
            reverse_iterator operator--(int) { reverse_iterator temp(_node); operator--(); return temp;}


            value_type &operator*() const { return *_node; }
            value_type *operator->() const { return _node->content; }
            node *getNode() const { return _node; }
        };
        reverse_iterator rbegin() { return(reverse_iterator(_end->parent));}
        reverse_iterator rend() {return(reverse_iterator(_begin));}

        class const_reverse_iterator : public std::reverse_iterator<iterator> {
        private:
            node *_node;
            struct Node *_prev;
            struct Node *_next;
        public:

            explicit const_reverse_iterator(node *pointer = nullptr) : _node(pointer), _prev(nullptr), _next(nullptr) {}
            const_reverse_iterator(const_reverse_iterator const &other) { *this = other; }
            const_reverse_iterator(reverse_iterator const& other) {*this = other;}
            ~const_reverse_iterator() {}

            const_reverse_iterator &operator=(const_reverse_iterator const &other) {
                _node = other._node;
                _prev = other._prev;
                _next = other._next;
                return (*this);
            }
            const_reverse_iterator&    operator=(reverse_iterator const& other) {
                _node = other.getElement();
                return(*this);
            }

            bool operator==(reverse_iterator const &other) { return other._node == _node; }
            bool operator!=(reverse_iterator const &other) { return other._node != _node; }
            bool operator==(const_reverse_iterator const& other) {return other.getElement() == _node;}
            bool operator!=(const_reverse_iterator const& other) {return other.getElement()!= _node;}

            const_reverse_iterator &operator--() {
                if (_node->right) {
                    _prev = _node;
                    _node = _node->right;
                    while (_node->left != nullptr)
                        _node = _node->left;
                }
                else {
                    while (_node == _node->parent->right)
                        _node = _node->parent;
                    _node = _node->parent;
                    if (_node == _prev)
                        _node = _node->parent;
                }
                return *this;
            }
            const_reverse_iterator &operator++() {
                if (_node->left) {
                    _next = _node;
                    _node = _node->left;
                    while (_node->right != nullptr)
                        _node = _node->right;
                }
                else {
                    while (_node == _node->parent->left)
                        _node = _node->parent;
                    _node = _node->parent;
                    if (_node == _next)
                        _node = _node->parent;
                }
                return *this;
            }
            const_reverse_iterator operator++(int) { const_reverse_iterator temp(_node); operator++(); return temp;}
            const_reverse_iterator operator--(int) { const_reverse_iterator temp(_node); operator--(); return temp;}


            value_type &operator*() const { return *_node; }
            value_type *operator->() const { return _node->content; }
            node *getNode() const { return _node; }
        };
        const_reverse_iterator rbegin() const { return(const_reverse_iterator(_end->parent));}
        const_reverse_iterator rend() const {return(const_reverse_iterator(_begin));}
    };
}


#endif