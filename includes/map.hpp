#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include "vector.hpp"

namespace ft {

    template < class Key, class T, class Compare = std::less<Key>,
            class Alloc = std::allocator<std::pair<const Key, T> > >
    class map {
    public:
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
            bool        color;
            value_type  *content;
        } node;
    private:

        const static bool black = false;
        const static bool red = true;

        typedef typename allocator_type::template rebind<node>::other allocator_rebind_type;
        allocator_rebind_type _allocator_rebind;
        key_compare _compare;
        allocator_type _alloc;
        size_type _size;
        node *_begin;
        node *_end;
        struct Node *_root;

        node  *newEmptyNode() {
            node  *newNode = _allocator_rebind.allocate(1);
            newNode->parent = nullptr;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->content = nullptr;
            newNode->color = black;
            return newNode;
        }

        node *newNode(value_type const& value) {
            node  *newNode = _allocator_rebind.allocate(1);
            newNode->parent = nullptr;
            newNode->left = nullptr;
            newNode->right = nullptr;
            _size == 0 ? newNode->color = black : newNode->color = red;
            newNode->content = _alloc.allocate(1);
            _alloc.construct(newNode->content, value);
            ++_size;
            return newNode;
        }

        void    deleteNode(node * const oldNode) {
            _alloc.destroy(oldNode->content);
            _alloc.deallocate(oldNode->content, 1);
            _allocator_rebind.deallocate(oldNode, 1);
            --_size;
        }

        void    deleteEmptyNode(node * const oldNode) {
            _allocator_rebind.deallocate(oldNode, 1);
        }

        void leftRotate(node *parentNode) {
            node *childNode = parentNode->right;

            if (parentNode->parent) {
                node *grandParent = parentNode->parent;
                childNode->parent = grandParent;
                grandParent->left == parentNode ? grandParent->left = childNode : grandParent->right = childNode;
                if (childNode->left) {
                    node *tail = childNode->left;
                    tail->parent = parentNode;
                    parentNode->right = tail;
                } else {
                    parentNode->right = nullptr;
                }
                childNode->left = parentNode;
                parentNode->parent = childNode;
            } else {
                childNode->parent = nullptr;
                _root = childNode;
                if (childNode->left) {
                    node *tail = childNode->left;
                    tail->parent = parentNode;
                    parentNode->right = tail;
                } else {
                    parentNode->right = nullptr;
                }
                childNode->left = parentNode;
                parentNode->parent = childNode;
            }
            _root == childNode ? childNode->color = black : childNode->color = parentNode->color;
            parentNode->color = red;
        }

        void rightRotate(node *parentNode) {
            node *childNode = parentNode->left;

            if (parentNode->parent) {
                node *grandParent = parentNode->parent;
                childNode->parent = grandParent;
                grandParent->left == parentNode ? grandParent->left = childNode : grandParent->right = childNode;
                if (childNode->right) {
                    node *tail = childNode->right;
                    tail->parent = parentNode;
                    parentNode->left = tail;
                } else {
                    parentNode->left = nullptr;
                }
                childNode->right = parentNode;
                parentNode->parent = childNode;
            } else {
                childNode->parent = nullptr;
                _root = childNode;
                if (childNode->right) {
                    node *tail = childNode->right;
                    tail->parent = parentNode;
                    parentNode->left = tail;
                } else {
                    parentNode->left = nullptr;
                }
                childNode->right = parentNode;
                parentNode->parent = childNode;
            }
            _root == childNode ? childNode->color = black : childNode->color = parentNode->color;
            parentNode->color = red;
        }


        void    swipeColor(node *parentNode) {
                parentNode == _root ? parentNode->color = black : parentNode->color = red;
                parentNode->left->color = black;
                parentNode->right->color = black;
            }

        void checkBalancing(node *tmpNode) {
            while (tmpNode) {
                if (tmpNode->right && tmpNode->right != _end && tmpNode->right->color == red) {
                    if (tmpNode->left && tmpNode->left != _begin && tmpNode->left->color == red) {
                        swipeColor(tmpNode);
//                        std::cout << "swipeColor" << std::endl;
                    } else {
                        leftRotate(tmpNode);
//                        std::cout << "leftRotate" << std::endl;
                    }
                }
                else if (tmpNode->left && tmpNode->left != _begin && tmpNode->left->color == red &&
                        tmpNode->left->left && tmpNode->left->left != _begin && tmpNode->left->left->color == red) {
                    rightRotate(tmpNode);
//                    std::cout << "rightRotate" << std::endl;
                }
                tmpNode = tmpNode->parent;
            }
        }

    public:

        explicit map (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type()) : _compare(comp), _alloc(alloc), _size(0) {
            _begin = newEmptyNode();
            _end = newEmptyNode();
            _root = _begin;
            _begin->parent = _end;
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type()) : _compare(comp), _alloc(alloc), _size(0) {
            _begin = newEmptyNode();
            _end = newEmptyNode();
            _root = _begin;
            _begin->parent = _end;
            while (first != last) {
                insert(*first);
                ++first;
            }
        }
        map (const map& x) : _size(0) {
            _begin = newEmptyNode();
            _end = newEmptyNode();
            _root = _begin;
            _begin->parent = _end;
            *this = x;
        }

        ~map() {
            clear();
            deleteEmptyNode(_begin);
            deleteEmptyNode(_end);
        }

        map& operator= (const map& x) {
            clear(); // then clear is will be ready
            _compare = x._compare;
            _alloc = x._alloc;
            insert(x.begin(), x.end());
            return *this;
        }

        bool empty() const { return !_size;}
        size_type size() const { return _size;}
        size_type max_size() const { return -1 / (sizeof(reference) * 2 + sizeof(value_type) * 3);}
        key_compare key_comp() const {return _compare;}
        value_compare value_comp() const {return value_compare(_compare);}

        mapped_type& operator[] (const key_type& k) {
            return insert(std::make_pair(k, mapped_type())).first->second;
        }

        std::pair<iterator,bool>    insert(const value_type& val) {
            map::iterator it = end();
            bool change = false;
            struct Node *tmp = _root;
            if (_size == 0) {
                _root = newNode(val);
                _begin->parent = _root;
                _end->parent = _root;
                _root->left = _begin;
                _root->right = _end;
                it = iterator(_root);
//                std::cout << "add to root ";
            }
            while (it == end()) {
                if (_compare(val.first, tmp->content->first) &&
                    !_compare(tmp->content->first, val.first)) {
                    if (tmp->left == _begin || tmp->left == nullptr) {
                        if (tmp->left == _begin) {
                            tmp->left = newNode(val);
                            _begin->parent = tmp->left;
                            it = iterator(tmp->left);
//                            std::cout << "add to left ";
                            change = true;
                            tmp->left->left = _begin;
                        } else {
                            tmp->left = newNode(val);
                            it = iterator(tmp->left);
//                            std::cout << "add to left ";
                            change = true;
                            tmp->left->left = nullptr;
                        }
                        tmp->left->parent = tmp;
                    } else
                        tmp = tmp->left;
                }
                else if (_compare(tmp->content->first, val.first) &&
                        !_compare(val.first, tmp->content->first)) {
                    if (tmp->right == _end || tmp->right == nullptr) {
                        if (tmp->right == _end) {
                            tmp->right = newNode(val);
                            _end->parent = tmp->right;
                            it = iterator(tmp->right);
//                            std::cout << "add to right ";
                            tmp->right->right = _end;
                            change = true;
                        } else {
                            tmp->right = newNode(val);
                            it = iterator(tmp->right);
//                            std::cout << "add to right ";
                            change = true;
                            tmp->right->right = nullptr;
                        }
                        tmp->right->parent = tmp;
                    } else
                        tmp = tmp->right;
                }
                else
                    it = iterator(tmp);
            }
//            std::cout << it->first << std::endl;
            checkBalancing(it.getNode());
            return std::make_pair(it, change);
        }

        iterator insert(iterator position, const value_type& val) {
            map::iterator it;
            node *tmp = position.getNode();
            if (_compare(val.first, position->first) &&
                    !_compare(position->first, val.first)) {
                if (tmp->left == _begin || tmp->left == nullptr) {
                    if (tmp->left == _begin) {
                        tmp->left = newNode(val);
                        _begin->parent = tmp->left;
                        it = iterator(tmp->left);
                        tmp->left->left = _begin;
                    } else {
                        tmp->left = newNode(val);
                        it = iterator(tmp->left);
                        tmp->left->left = nullptr;
                    }
                    tmp->left->parent = tmp;
                }
                else {
                    node *after = tmp->left;
                    tmp->left = newNode(val);
                    after->parent = tmp->left;
                    it = iterator(tmp->left);
                    tmp->left->left = after;
                    tmp->left->parent = tmp;
                }
            }
            else if (_compare(position->first, val.first) &&
                    !_compare(val.first, position->first)) {
                if (tmp->right == _end || tmp->right == nullptr) {
                    if (tmp->right == _end) {
                        tmp->right = newNode(val);
                        _end->parent = tmp->right;
                        it = iterator(tmp->right);
                        tmp->right->right = _end;
                    } else {
                        tmp->right = newNode(val);
                        it = iterator(tmp->right);
                        tmp->right->right = nullptr;
                    }
                    tmp->right->parent = tmp;
                }
                else {
                    node *after = tmp->right;
                    tmp->right = newNode(val);
                    after->parent = tmp->right;
                    it = iterator(tmp->right);
                    tmp->right->right = after;
                    tmp->right->parent = tmp;
                }
            }
            else
                it = iterator(tmp);
            checkBalancing(it.getNode());
            return it;
        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last) {
            while (first != last) {
                insert(*first);
                ++first;
            }
        }

        void erase (iterator position) {
            node *tmp = position.getNode();
            if (position == end())
                return;

            if (tmp->parent) { // if have parent
                if (tmp->parent->right == tmp) { // if left branch
                    if (tmp->right) {
                        tmp->parent->right = tmp->right;
                        tmp->right->parent = tmp->parent;
                        if (tmp->left) {
                            tmp->right->left = tmp->left;
                            tmp->left->parent = tmp->right;
                        }
                    } else if (tmp->left) {
                        tmp->parent->right = tmp->left;
                        tmp->left->parent = tmp->parent;
                    } else
                        tmp->parent->right = nullptr;
                } else if (tmp->parent->left == tmp) { // if right branch
                    if (tmp->left) {
                        tmp->parent->left = tmp->left;
                        tmp->left->parent = tmp->parent;
                        if (tmp->right) {
                            tmp->left->right = tmp->right;
                            tmp->right->parent = tmp->left;
                        }
                    } else if (tmp->right) {
                        tmp->parent->left = tmp->right;
                        tmp->right->parent = tmp->parent;
                    } else
                        tmp->parent->left = nullptr;
                }
            }
            else if (!tmp->parent) { // if have NOT parent(root)
                if (tmp->right == _end) {
                    if (tmp->left == _begin) {
                        _end->parent = nullptr;
                        _begin->parent = _end;
                        _root = _begin;
                    }
                    else {
                        tmp->left->parent = nullptr;
                        node *new_end = tmp->left;
                        while (new_end->right) {
                            new_end = new_end->right;
                        }
                        new_end->right = _end;
                        _end->parent = new_end;
                    }
                }
                else if (tmp->left == _begin) {
                    tmp->right->parent = nullptr;
                    node *new_begin = tmp->right;
                    while (new_begin->left) {
                        new_begin = new_begin->left;
                    }
                    new_begin->left = _begin;
                    _begin->parent = new_begin;
                }
                else { // if we have right adn left branch
                    tmp->right->parent = nullptr;
                    tmp->left->parent = tmp->right;
                    if (tmp->right->left) {
                        node *findpos = tmp->left;
                        while (findpos->right) {
                            findpos = findpos->right;
                        }
                        findpos->right = tmp->right->left;
                        tmp->right->left->parent = findpos;
                    }
                    tmp->right->left = tmp->left;
                }
            }
            deleteNode(tmp);
        }

        size_type erase (const key_type& k) {
            size_type oldSize = size();
            iterator it = find(k);
            erase(it);
            return oldSize - size();
        }

        void erase (iterator first, iterator last) {
            vector<iterator> iterators;
            while (first != last) {
                iterators.push_back(first);
                ++first;
            }
            for (size_type i = 0; i < iterators.size(); i++) {
                erase(iterators[i]);
            }
//                while(1){}
        }


        void swap (map& x) {
            map y(x);
            x = *this;
            *this = y;
        }

        void clear() {
            erase(begin(), end());
        }

        iterator find (const key_type& k) {
            iterator it = end();
            node *tmp = _root;
            while (tmp && tmp != _begin && tmp != _end) {
                if (tmp->content->first == k) {
                    it = iterator(tmp);
                    break;
                }
                if (_compare(tmp->content->first, k))
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
            }
            return it;
        }

        const_iterator find (const key_type& k) const {
            const_iterator it = end();
            node *tmp = _root;
            while (tmp && tmp != _begin && tmp != _end) {
                if (tmp->content->first == k) {
                    it = iterator(tmp);
                    break;
                }
                if (_compare(tmp->content->first, k))
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
            }
            return it;
        }

        size_type count (const key_type& k) const {
            return find(k) == end()? 0:1;
        }

        iterator lower_bound (const key_type& k) {
            iterator it = begin();
            while (it != end()) {
                if (_compare(it->first, k))
                    ++it;
                else
                    break;
            }
            return it;
        }

        const_iterator lower_bound (const key_type& k) const {
            const_iterator it = begin();
            while (it != end()) {
                if (_compare(it->first, k))
                    ++it;
                else
                    break;
            }
            return it;
        }

        iterator upper_bound (const key_type& k) {
            iterator it = begin();
            while (it != end()) {
                if (_compare(it->first, k))
                    ++it;
                else if (_compare(k, it->first))
                    break;
                else {
                    ++it;
                    break;
                }
            }
            return it;
        }
        const_iterator upper_bound (const key_type& k) const {
            const_iterator it = begin();
            while (it != end()) {
                if (_compare(it->first, k))
                    ++it;
                else if (_compare(k, it->first))
                    break;
                else {
                    ++it;
                    break;
                }
            }
            return it;
        }

        std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
            return std::make_pair(lower_bound(k), upper_bound(k));
        }

        std::pair<iterator,iterator>             equal_range (const key_type& k) {
            return std::make_pair(lower_bound(k), upper_bound(k));
        }

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
            bool operator==(const_iterator const& other) {return other.getNode() == _node;}
            bool operator!=(const_iterator const& other) {return other.getNode()!= _node;}

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


            value_type &operator*() const { return *_node->content; }
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
                _node = other.getNode();
                return (*this);
            }

            bool operator==(iterator const &other) { return other.getNode() == _node; }
            bool operator!=(iterator const &other) { return other.getNode() != _node; }
            bool operator==(const_iterator const& other) {return other.getNode() == _node;}
            bool operator!=(const_iterator const& other) {return other.getNode()!= _node;}

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


            value_type &operator*() const { return *_node->content; }
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

            bool operator==(reverse_iterator const &other) { return other.getNode() == _node; }
            bool operator!=(reverse_iterator const &other) { return other.getNode() != _node; }
            bool operator==(const_reverse_iterator const& other) {return other.getNode() == _node;}
            bool operator!=(const_reverse_iterator const& other) {return other.getNode()!= _node;}

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


            value_type &operator*() const { return *_node->content; }
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
                _node = other.getNode();
                return(*this);
            }

            bool operator==(reverse_iterator const &other) { return other.getNode() == _node; }
            bool operator!=(reverse_iterator const &other) { return other.getNode() != _node; }
            bool operator==(const_reverse_iterator const& other) {return other.getNode() == _node;}
            bool operator!=(const_reverse_iterator const& other) {return other.getNode()!= _node;}

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


            value_type &operator*() const { return *_node->content; }
            value_type *operator->() const { return _node->content; }
            node *getNode() const { return _node; }
        };
        const_reverse_iterator rbegin() const { return(const_reverse_iterator(_end->parent));}
        const_reverse_iterator rend() const {return(const_reverse_iterator(_begin));}
    };
}


#endif