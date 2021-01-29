#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include <iterator>

namespace ft {
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
    template <typename T, class Alloc = std::allocator<T> >
    class list {
    public:

        //nickname
        class allocator;
        class iterator;
        class const_iterator;
        class reverse_iterator;
        class const_reverse_iterator;
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef size_t  size_type;
        typedef typename allocator_type::reference reference;
        typedef	typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ptrdiff_t difference_type;
        


        //constructors
        explicit list (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0) { startList(); }

        explicit list (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0) {
            startList();
            while (n--) {
                push_back(val);
            }
        }
        template <class InputIterator>
        list (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type(), typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _alloc(alloc), _size(0) {
            startList();
            while (first != last){
                push_back(*first);
                ++first;
            }
        }

        list (const list& x) : _size(0) {
            startList();
            iterator temp(x.begin());
            iterator endList(x.end());
            while (temp != endList) {
                push_back(*temp);
                ++temp;
            }
        }

        list& operator=(const list& x) {
            clear();
            iterator temp(x.begin());
            iterator endList(x.end());
            while (temp != endList) {
                push_back(*temp);
                ++temp;
            }
            return *this;
        }

        ~list() {
            clear();
            // _alloc.deallocate(_end, 1);
            // _allocator_rebind.deallocate(_end, 1);
        }
	
        //Modifiers
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last, typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
            clear();
            while(first != last) {
                push_back(*first);
                ++first;
            }
        }

        void assign (size_type n, const value_type& val) {
            clear();
            while (n) {
                push_back(val);
                --n;
            }
        }

        void push_front (const value_type& val) {
            t_list  *newList = newContentList(val);
            newList->next = _end->next;
            _end->next->prev = newList;
            newList->prev = _end;
            _end->next = newList;
        }

        void pop_front() {
            if (_size) {
                t_list  *newFront = _end->next->next;
                _end->next = newFront;
                deleteList(newFront->prev);
                newFront->prev = _end;
            }
        }

        void     push_back(const value_type& val) {
                t_list  *newList = newContentList(val);
                _end->prev->next = newList;
                newList->prev = _end->prev;
                newList->next = _end;
                _end->prev = newList;
        }

        void pop_back() {
            if (_size) {
                t_list  *newBack = _end->prev->prev;
                _end->prev = newBack;
                deleteList(newBack->next);
                newBack->next = _end;
            }
        }

        iterator insert (iterator position, const value_type& val) {
            t_list *newList = newContentList(val);
            t_list *postPos = position.getElement();
            newList->next = postPos;
            newList->prev = postPos->prev;
            newList->prev->next = newList;
            postPos->prev = newList;
            return iterator(newList);
        }

        void insert (iterator position, size_type n, const value_type& val) {
            iterator res = position;
            while (n) {
                res = insert(res, val);
                --n;
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
            iterator res = position;
            while (first != last--) {
                insert(res, *last);
            }
        }

        iterator erase (iterator position) {
            t_list *oldList = position.getElement();
            t_list *resList = position.getElement()->next;
            resList->prev = oldList->prev;
            oldList->prev->next = resList;
            deleteList(oldList);
            return iterator(resList);
        }

        iterator erase (iterator first, iterator last) {
            iterator resList;
            while (first != last) {
                resList = erase(first);
                first++;
            }
            return resList;
        }

        void swap (list& x) {
            list    temp(begin(), end());
            this->assign(x.begin(), x.end());
            x.assign(temp.begin(), temp.end());
        }

        void resize (size_type n, value_type val = value_type()) {
            if (n < _size) {
                iterator iter(_end->next);
                while (n++ != _size + 1)
                    ++iter;
                erase(iter, this->end());
            }
            else if (n > _size) {
                n -= _size;
                while (n--)
                    push_back(val);
            }
        }

        void clear() {erase(this->begin(), this->end());}

        //Capacity
        bool empty() const {return !_size;}

        size_type size() const {return _size;}

        size_type max_size() const { return -1 / sizeof(t_list); }

        //Element access

        reference front() {return *_end->next;}

        const_reference front() const {return *_end->next;}

        reference back() {return *_end;}

        const_reference back() const {return *_end;}

        //Operations

        void splice (iterator position, list& x) {
            t_list *last((x.end()).getElement());
            t_list *first((x.begin()).getElement());
            t_list *preLast(last->prev);
            last = preLast;
            while (last != first) {
                preLast = preLast->prev;
                splice(position, x, iterator(last));
                --position;
                last = preLast;
            }
                preLast = preLast->prev;
                splice(position, x, iterator(last));
                --position;
                last = preLast;
        }

        void splice (iterator position, list& x, iterator i) {
            (void)x;
            t_list *posList = position.getElement();
            t_list *changeList = i.getElement();
            changeList->next->prev = changeList->prev;
            changeList->prev->next = changeList->next;
            changeList->next = posList;
            changeList->prev = posList->prev;
            changeList->next->prev = changeList;
            changeList->prev->next = changeList;
        }

        void splice (iterator position, list& x, iterator first, iterator last) {
            t_list *lastElem(last.getElement());
            t_list *firstElem(first.getElement());
            t_list *preLast(lastElem->prev);
            lastElem = preLast;
            while (lastElem != firstElem) {
                preLast = preLast->prev;
                splice(position, x, iterator(lastElem));
                --position;
                lastElem = preLast;
            }
                preLast = preLast->prev;
                splice(position, x, iterator(lastElem));
                --position;
                lastElem = preLast;
        }

        void remove (const value_type& val) {
            t_list *tmp(_end->next);
            t_list *endz(_end);
            t_list *reservNode;
            while (tmp != endNode) {
                reservNode = tmp->next;
                if (*tmp->content == val)
                    erase(iterator(tmp));
                tmp = reservNode;
            }
        }

        template <class Predicate>
        void remove_if (Predicate pred) {
            t_list *tmp(_end->next);
            t_list *endNode(_end);
            t_list *reservNode;
            while (tmp != endNode) {
                reservNode = tmp->next;
                if (pred(*tmp->content))
                    erase(iterator(tmp));
                tmp = reservNode;
            }
        }

        void unique() {
            t_list *first(_end->next);
            t_list *second(_end);
            t_list *tmp;
            while (first != second) {
                tmp = first->next;
                while (tmp != second) {
                    if (*first->content == *tmp->content) {
                        tmp = tmp->next;
                        erase(iterator(tmp->prev));
                    }
                    else
                        tmp = tmp->next;
                }
                first = first->next;
            }
        }

        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred) {
            t_list *first(_end->next);
            t_list *second(_end);
            t_list *tmp;
            while (first != second) {
                tmp = first->next;
                while (tmp != second) {
                    if (binary_pred(*first->content, *tmp->content)) {
                        tmp = tmp->next;
                        erase(iterator(tmp->prev));
                    }
                    else
                        tmp = tmp->next;
                }
                first = first->next;
            }
        }

        void merge (list& x) {
            t_list *first(_end->next);
            t_list *xfirst(x._end->next);
            if (&x != this) {
                while (xfirst != x._end) {
                    if (first == _end || *first->content > *xfirst->content)
                        splice(iterator(first), *this, iterator(xfirst));
                    else
                        first = first->next;
                    xfirst = x._end->next;
                }
            }
        }

        template <class Compare>
        void merge (list& x, Compare comp) {
            t_list *first(_end->next);
            t_list *xfirst(x._end->next);
            if (&x != this) {
                while (xfirst != x._end) {
                    if (first == _end || !comp(*first->content, *xfirst->content))
                        splice(iterator(first), *this, iterator(xfirst));
                    else
                        first = first->next;
                    xfirst = x._end->next;
                }
            }
        }

        void sort() {
            size_t size(this->size());
            t_list *tmp(_end->next);
            t_list *tmpNext(tmp->next);
            while (--size) {
                tmp = _end->next;
                tmpNext = tmp->next;
                while (tmp->next != _end) {
                    if (*tmp->content > *tmpNext->content) {
                        swapList(tmp, tmpNext);
                        tmp = tmpNext->next;
                        tmpNext = tmp->next;
                    }
                    else {
                        tmp = tmp->next;
                        tmpNext = tmpNext->next;
                    }
                }
            }
        }

        template <class Compare>
        void sort (Compare comp) {
            size_t size(this->size());
            t_list *tmp(_end->next);
            t_list *tmpNext(tmp->next);
            while (--size) {
                tmp = _end->next;
                tmpNext = tmp->next;
                while (tmp->next != _end) {
                    if (!comp(*tmp->content, *tmpNext->content)) {
                        swapList(tmp, tmpNext);
                        tmp = tmpNext->next;
                        tmpNext = tmp->next;
                    }
                    else {
                        tmp = tmp->next;
                        tmpNext = tmpNext->next;
                    }
                }
            }
        }

        void reverse() {
            size_t size(this->size() / 2);
            t_list *first(_end->next);
            t_list *second(_end->prev);
            int flag(1);
            while (size--) {
                swapList(first, second);
                if (flag--) {
                    second = second->next;
                    first = first->prev;
                }
                else {
                    second = second->prev;
                    first = first->next;
                    flag++;
                }
            }
        }

    private:
        typedef struct      s_list {
            struct s_list   *next;
            struct s_list   *prev;
            value_type      *content;
        }                   t_list;

        typedef typename allocator_type::template rebind<t_list>::other allocator_rebind_type;

        allocator_rebind_type   _allocator_rebind;
        allocator_type          _alloc;
        size_type               _size;
        t_list                  *_end;
        //utils
        void    startList() {
            _end = _allocator_rebind.allocate(1);
            _end->content = _alloc.allocate(1);
            _end->next = _end;
            _end->prev = _end;
        }

        t_list  *newContentList(const value_type& val) {
            t_list  *newList = _allocator_rebind.allocate(1);
            newList->content = _alloc.allocate(1);
            _alloc.construct(newList->content, val);
            ++_size;
            return newList;
        }

        void    deleteList(t_list* const oldList) {
            _alloc.destroy(oldList->content);
            _alloc.deallocate(oldList->content, 1);
            _allocator_rebind.deallocate(oldList, 1);
            --_size;
        }

        void    swapList(t_list *x, t_list *y) {
            t_list *left(x->next);
            t_list *right(y->prev);
            if (left == y) {
                y->next->prev = x;
                y->prev = x->prev;
                x->prev->next = y;
                x->next = y->next;
                x->prev = y;
                y->next = x;
            }
            else {
                y->next->prev = x;
                y->prev = x->prev;
                x->prev->next = y;
                x->next = y->next;
                x->prev = right;
                y->next = left;
                right->next = x;
                left->prev = y;
            }
        }

    public:
        //iterators
        class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
        private:
            t_list  *_element;
        public:

            explicit iterator(t_list *pointer = nullptr) : _element(pointer) {}

            iterator(iterator const& other) {*this = other;}

            iterator(const_iterator const& other) {*this = other;}

            ~iterator() {}

            iterator&    operator=(iterator const& other) {
                _element = other._element;
                return(*this);
            }

            iterator&    operator=(const_iterator const& other) {
                _element = other.getElement();
                return(*this);
            }

            bool        operator==(iterator const& other) {return other._element == _element;}
        
            bool        operator!=(iterator const& other) {return other._element != _element;}

            iterator&   operator--() {
            _element = _element->prev;
            return *this;
            }

            iterator&   operator++() {
                _element = _element->next;
                return *this;
            }

            iterator  operator++(int) {
                iterator temp(_element);
                operator++();
                return temp;
            }

            iterator  operator--(int) {
                iterator temp(_element);
                operator--();
                return temp;
            }

            T&	operator*() const {return *_element->content;}
            T*  operator->() const {return _element->content;}

            t_list*  getElement() const {return _element;}
        };

        iterator begin() {return(iterator(_end->next));}
        iterator end() {return(iterator(_end));}

        class const_iterator : public std::iterator<std::bidirectional_iterator_tag, const value_type> {
        private:
            t_list   *_element;
        public:
            explicit const_iterator(t_list *pointer = nullptr) : _element(pointer) {}

            const_iterator(const_iterator const& other) {*this = other;}

            const_iterator(iterator const& other) {*this = other;}

            ~const_iterator() {}

            const_iterator&    operator=(const_iterator const& other) {
                _element = other._element;
                return(*this);
            }

            const_iterator&    operator=(iterator const& other) {
                _element = other.getElement();
                return(*this);
            }

            bool        operator==(const_iterator const& other) {return other._element == _element;}
        
            bool        operator!=(const_iterator const& other) {return other._element != _element;}

            const_iterator&   operator--() {
            _element = _element->prev;
            return *this;
            }

            const_iterator&   operator++() {
                _element = _element->next;
                return *this;
            }

            const_iterator  operator++(int) {
                iterator temp(_element);
                operator++();
                return temp;
            }

            const_iterator  operator--(int) {
                iterator temp(_element);
                operator--();
                return temp;
            }

            T	const& operator*() const {return *_element->content;}
            T  const* operator->() const {return _element->content;}

            t_list*   getElement() const {return _element;}
        };

        const_iterator begin() const {return(iterator(_end->next));}
        const_iterator end() const {return(iterator(_end));}

        class reverse_iterator : public std::reverse_iterator<iterator> {
        private:
            t_list  *_element;
        public:

            explicit reverse_iterator(t_list *pointer = nullptr) : _element(pointer) {}

            reverse_iterator(reverse_iterator const& other) {*this = other;}

            reverse_iterator(const_reverse_iterator const& other) {*this = other;}

            ~reverse_iterator() {}

            reverse_iterator&    operator=(reverse_iterator const& other) {
                _element = other._element;
                return(*this);
            }

            reverse_iterator&    operator=(const_reverse_iterator const& other) {
                _element = other.getElement();
                return(*this);
            }

            bool        operator==(reverse_iterator const& other) {return other._element == _element;}
        
            bool        operator!=(reverse_iterator const& other) {return other._element != _element;}

            reverse_iterator&   operator--() {
            _element = _element->next;
            return *this;
            }

            reverse_iterator&   operator++() {
                _element = _element->prev;
                return *this;
            }

            reverse_iterator  operator++(int) {
                reverse_iterator temp(_element);
                operator++();
                return temp;
            }

            reverse_iterator  operator--(int) {
                reverse_iterator temp(_element);
                operator--();
                return temp;
            }

            T&	operator*() const {return *_element->content;}
            T*  operator->() const {return _element->content;}

            t_list*  getElement() const {return _element;}
        };

        reverse_iterator rbegin() {return(reverse_iterator(++_end));}
        reverse_iterator rend() {return(reverse_iterator(--_end));}

        class const_reverse_iterator : public std::reverse_iterator<iterator> {
        private:
            t_list  *_element;

        public:

            explicit const_reverse_iterator(t_list *pointer = nullptr) : _element(pointer) {}

            const_reverse_iterator(const_reverse_iterator const& other) {*this = other;}

            const_reverse_iterator(reverse_iterator const& other) {*this = other;}

            ~const_reverse_iterator() {}

            const_reverse_iterator&    operator=(const_reverse_iterator const& other) {
                _element = other._element;
                return(*this);
            }

            const_reverse_iterator&    operator=(reverse_iterator const& other) {
                _element = other.getElement();
                return(*this);
            }

            bool        operator==(const_reverse_iterator const& other) {return other._element == _element;}
        
            bool        operator!=(const_reverse_iterator const& other) {return other._element != _element;}

            const_reverse_iterator&   operator--() {
            _element = _element->next;
            return *this;
            }

            const_reverse_iterator&   operator++() {
                _element = _element->prev;
                return *this;
            }

            const_reverse_iterator  operator++(int) {
                const_reverse_iterator temp(_element);
                operator++();
                return temp;
            }

            const_reverse_iterator  operator--(int) {
                const_reverse_iterator temp(_element);
                operator--();
                return temp;
            }

            T const&	operator*() const {return *_element->content;}
            T const*  operator->() const {return _element->content;}

            t_list*  getElement() const {return _element;}
        };

        const_reverse_iterator rbegin() const {return(const_reverse_iterator(++_end));}
        const_reverse_iterator rend() const {return(const_reverse_iterator(--_end));}


        
            
    };

    template <class T, class Alloc>
    void swap (list<T,Alloc>& x, list<T,Alloc>& y) {
        list<T,Alloc> z(x);
        x = y;
        y = z;
    }

    template <class T, class Alloc>
    bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {return lhs.size() == rhs.size();}
    
    template <class T, class Alloc>
    bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {return lhs.size() != rhs.size();}
    
    template <class T, class Alloc>
    bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {return lhs.size() < rhs.size();}
    
    template <class T, class Alloc>
    bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {return lhs.size() <= rhs.size();}
    
    template <class T, class Alloc>
    bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {return lhs.size() > rhs.size();}
    
    template <class T, class Alloc>
    bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {return lhs.size() >= rhs.size();}
}


#endif