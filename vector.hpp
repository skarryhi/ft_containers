//
// Created by Saturn Karry on 3/8/21.
//

#ifndef FT_CONTAINERS_VECTOR_H
#define FT_CONTAINERS_VECTOR_H

#include <iostream>
#include <memory>
#include <iterator>

namespace ft {

    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
    template <typename T, class Alloc = std::allocator<T> >

    class vector {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        class allocator;
        typedef typename allocator_type::reference reference;
        typedef	typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        class iterator;
        class const_iterator;
        class reverse_iterator;
        class const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t  size_type;
    private:
        typedef typename allocator_type::template rebind<value_type>::other allocator_rebind_type;

        allocator_rebind_type   _allocator_rebind;
        allocator_type          _alloc;
        size_type               _size;
        size_type 		        _capacity;
        value_type              *_vector;

        value_type *newArr(const value_type& val) {
            value_type  *newArr = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size;  i++)
                _alloc.construct(newArr + i, val);
            return newArr;
        }

        void        addElem(const value_type val) {
            _alloc.construct(_vector + _size, val);
            ++_size;
        }

        void        reserveCapacity(size_type need) {
            value_type  *newArr = _alloc.allocate(need);
            for (size_type i = 0; i < _size;  i++)
                _alloc.construct(newArr + i, *(_vector + i));
            for (size_type i = 0; i < _size;  i++)
                _alloc.destroy(_vector + i);
            if (_capacity)
                _alloc.deallocate(_vector, _capacity);
            _capacity = need;
            _vector = newArr;
        }

        void    deleteElem(size_type position_start, size_type position_end) {
            _size -= position_end - position_start + 1;
            for (size_type i = 0; i < _size;  i++) {
                if (i >= position_start && i <= position_end) {
                    _alloc.destroy(_vector + i);
                    if ((i + position_end - position_start + 1) < _size) {
                        _alloc.construct(_vector + i, *(_vector + (i + position_end - position_start + 1)));
                        _alloc.destroy(_vector + (i + position_end - position_start + 1));
                    }
                }
                if (i > position_end) {
                    _alloc.construct(_vector + i, *(_vector + (i + position_end - position_start + 1)));
                    _alloc.destroy(_vector + (i + position_end - position_start + 1));
                }
            }
        }

        size_type getPosition(iterator const& position) {
            iterator it = begin();
            size_type start = 0;
            while (it != this->end()) {
                if (it == position)
                    break;
                ++start;
                ++it;
            }
            return start;
        }

    public:
        //operators
        reference operator[] (size_type n) { return _vector[n]; }
        const_reference operator[] (size_type n) const {return _vector[n];}

        vector& operator=(const vector& x) { //TODO checking
            clear();
            if (_capacity)
                _alloc.deallocate(_vector, _capacity);
            _capacity = x.capacity();
            _vector = _alloc.allocate(_capacity);
            for (size_type i = 0; i < x._size; i++) {
                addElem(x[i]);
            }
            return *this;
        }

        reference at(size_type n) {
            if (n >= _size)
                throw std::out_of_range("invalid index");
            return _vector[n];
        }

        const_reference at(size_type n) const {
            if (n >= _size)
                throw std::out_of_range("invalid index");
            return _vector[n];
        }

        reference front() {return _vector[0];}

        const_reference front() const {return _vector[0];}

        reference back() {return _vector[_size - 1];}

        const_reference back() const {return _vector[_size - 1];}
        //Capacity

        size_type size() const {return _size;}

        size_type max_size() const { return -1 / sizeof(reference);}

        void resize (size_type n, value_type val = value_type()) {
            if (n > _size) {
                while (n > _capacity)
                    reserveCapacity(_size * 2);
                while (_size < n)
                    addElem(val);
            }
            else
                   deleteElem(n, _size - 1);
        }

        size_type capacity() const {return _capacity;}

        bool empty() const {return _size == 0;}

        void reserve (size_type n) {
            if (n > _capacity) {
                reserveCapacity(n);
            }
        }


        //constructors, destructors
        explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _capacity(0), _vector(
                nullptr) {}

        explicit vector (size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n) {
            _vector = newArr(val);
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type(), typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0): _alloc(alloc), _size(0), _capacity(0) {
            while (first != last) {
                reserveCapacity(_size + 1);
                addElem(*first);
                ++first;
            }
        }

        vector (const vector& x): _alloc(allocator_type()), _capacity(x._capacity), _size(0) {
            _vector = _alloc.allocate(_capacity);
            for (size_type i = 0; i < x._size; i++) {
                addElem(x[i]);
            }
        }

        ~vector() {
            clear();
            if (_capacity)
                _alloc.deallocate(_vector, _capacity);
        }

        //Modifiers
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last, typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
            deleteElem(0, size() - 1);
            while (first != last) {
                if (_size + 1 > _capacity)
                    reserveCapacity(_size + 1);
                addElem(*first);
                ++first;
            }
        }

        void assign (size_type n, const value_type& val) {
            deleteElem(0, size() - 1);
            while (n > 0) {
                if (_size + 1 > _capacity)
                    reserveCapacity(_size + 1);
                addElem(val);
                --n;
            }
        }

        void push_back (const value_type& val) {
            if (_size + 1 > _capacity) {
                if (_capacity == 0)
                    reserveCapacity(1);
                else
                    reserveCapacity(_size * 2);
            }
            addElem(val);
        }

        void pop_back() {
            deleteElem(size() - 1, size() - 1);
        }

        iterator insert (iterator position, const value_type& val) {
            if (_size == _capacity)
                reserveCapacity(_size + 1);
            size_type pos = getPosition(position);
            for (size_type i = 0; i < _size; i++) {
                if (i == pos) {
                    for (size_type j = _size; j > i; j--) {
                        _alloc.construct(_vector + j, *(_vector + j - 1));
                        _alloc.destroy(_vector + j - 1);
                    }
                    _alloc.construct(_vector + i, val);
                    ++_size;
                    break;
                }
            }
            return iterator(_vector + getPosition(position));
        }

        void insert (iterator position, size_type n, const value_type& val) {
            while (n != 0) {
                position = insert(position, val);
                --n;
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
            if (first == last)
                return;
            --last;
            while (first != last) {
                insert(position, *last);
                --last;
            }
            insert(position, *first);
        }

        iterator erase (iterator position) {
            deleteElem(getPosition(position), getPosition(position));
            return iterator(_vector + getPosition(position));
        }

        iterator erase (iterator first, iterator last) {
            deleteElem(getPosition(first), getPosition(last) - 1);
            return iterator(_vector + getPosition(first));
        }

        void swap (vector& x) {
            vector<value_type> tmp(x);
            x = *this;
            *this = tmp;
        }

        void clear() {
            for (size_type i = 0; i < _size;  i++)
                _alloc.destroy(_vector + i);
            _size = 0;
        }


    public:
        //iterators
        class iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
        private:
            value_type              *_element;
        public:
            explicit iterator(value_type *pointer = nullptr) : _element(pointer) {}
            iterator&    operator=(iterator const& other) {_element = other._element; return(*this);}

            iterator(iterator const& other) {*this = other;}
            ~iterator() {}

            iterator&   operator--() {_element -= 1; return *this;}
            iterator&   operator++() { _element += 1; return *this;}
            iterator  operator--(int) {iterator temp(_element); operator--(); return temp;}
            iterator  operator++(int) {iterator temp(_element); operator++(); return temp;}
            iterator  operator+(difference_type val) const {return iterator(_element + val);}
            iterator  operator-(difference_type val) const {return iterator(_element - val);}
            iterator  operator+=(difference_type val) {return iterator(_element += val);}
            iterator  operator-=(difference_type val) {return iterator(_element -= val);}

            bool        operator==(iterator const& other) const {return _element == other._element;}
            bool        operator!=(iterator const& other) const {return _element != other._element;}
            bool        operator>(iterator const& other) const {return _element > other._element;}
            bool        operator>=(iterator const& other) const {return _element >= other._element;}
            bool        operator<(iterator const& other) const {return _element < other._element;}
            bool        operator<=(iterator const& other) const {return _element <= other._element;}

            bool        operator==(const_iterator const& other) const {return _element == other.getElement();}
            bool        operator!=(const_iterator const& other) const {return _element != other.getElement();}
            bool        operator>(const_iterator const& other) const {return _element > other.getElement();}
            bool        operator>=(const_iterator const& other) const {return _element >= other.getElement();}
            bool        operator<(const_iterator const& other) const {return _element < other.getElement();}
            bool        operator<=(const_iterator const& other) const {return _element <= other.getElement();}

            const_reference operator[](const_reference val) const {return _element[val];}
            value_type&	operator*() const {return *_element;}
            value_type*  operator->() const {return _element;}
            value_type *getElement() const {return _element;}
        };
        iterator begin() { return(iterator(_vector));}
        iterator end() {return(iterator(_vector + _size));}


        class const_iterator : public std::iterator<std::random_access_iterator_tag, const value_type> {
        private:
            value_type              *_element;
        public:
            explicit const_iterator(value_type *pointer = nullptr) : _element(pointer) {}
            const_iterator&    operator=(const_iterator const& other) {_element = other._element; return(*this);}
            const_iterator&    operator=(iterator const& other) {_element = other.getElement(); return(*this);}

            const_iterator(const_iterator const& other) {*this = other;}
            const_iterator(iterator const& other) {*this = other;}
            ~const_iterator() {}

            bool        operator==(iterator const& other) const {return _element == other.getElement();}
            bool        operator!=(iterator const& other) const {return _element != other.getElement();}
            bool        operator>(iterator const& other) const {return _element > other.getElement();}
            bool        operator>=(iterator const& other) const {return _element >= other.getElement();}
            bool        operator<(iterator const& other) const {return _element < other.getElement();}
            bool        operator<=(iterator const& other) const {return _element <= other.getElement();}

            bool        operator==(const_iterator const& other) const {return _element == other._element;}
            bool        operator!=(const_iterator const& other) const {return _element != other._element;}
            bool        operator>(const_iterator const& other) const {return _element > other._element;}
            bool        operator>=(const_iterator const& other) const {return _element >= other._element;}
            bool        operator<(const_iterator const& other) const {return _element < other._element;}
            bool        operator<=(const_iterator const& other) const {return _element <= other._element;}

            const_iterator&   operator--() {  _element = _element - 1; return *this;}
            const_iterator&   operator++() {_element = _element + 1; return *this;}
            const_iterator  operator++(int) {iterator temp(_element); operator++(); return temp;}
            const_iterator  operator--(int) {iterator temp(_element); operator--(); return temp;}
            const_iterator  operator+(difference_type val) const {return const_iterator(_element + val);}
            const_iterator  operator-(difference_type val) const {return const_iterator(_element - val);}
            const_iterator  operator+=(difference_type val) {return const_iterator(_element += val);}
            const_iterator  operator-=(difference_type val) {return const_iterator(_element -= val);}

            const_reference operator[](const_reference val) const {return _element[val];}
            value_type	const& operator*() const {return *_element;}
            value_type  const* operator->() const {return _element;}
            value_type *getElement() const {return _element;}
        };
        const_iterator begin() const {return(iterator(*_vector));}
        const_iterator end() const {return(iterator(*(_vector + _size)));}


        class reverse_iterator :  public std::reverse_iterator<iterator> {
        private:
            value_type              *_element;
        public:
            explicit reverse_iterator(value_type *pointer = nullptr) : _element(pointer) {}
            reverse_iterator&    operator=(reverse_iterator const& other) {_element = other._element; return(*this);}

            reverse_iterator(reverse_iterator const& other) {*this = other;}
            ~reverse_iterator() {}

            reverse_iterator&   operator--() {_element += 1; return *this;}
            reverse_iterator&   operator++() { _element -= 1; return *this;}
            reverse_iterator  operator+(difference_type val) const {return reverse_iterator(_element - val);}
            reverse_iterator  operator-(difference_type val) const {return reverse_iterator(_element + val);}
            reverse_iterator  operator+=(difference_type val) {return reverse_iterator(_element -= val);}
            reverse_iterator  operator-=(difference_type val) {return reverse_iterator(_element += val);}

            const_reference operator[](const_reference val) const {return _element[val];}
            value_type&	operator*() const {return *_element;}
            value_type*  operator->() const {return _element;}
            value_type *getElement() const {return _element;}
        };
        reverse_iterator rbegin() {return(reverse_iterator((_vector + (_size - 1))));}
        reverse_iterator rend() {return(reverse_iterator((_vector - 1)));}


        class const_reverse_iterator : public std::reverse_iterator<iterator> {
        private:
            value_type              *_element;
        public:
            explicit const_reverse_iterator(value_type *pointer = nullptr) : _element(pointer) {}
            const_reverse_iterator&    operator=(const_reverse_iterator const& other) {_element = other._element; return(*this);}
            const_reverse_iterator&    operator=(reverse_iterator const& other) {_element = other.getElement(); return(*this);}

            const_reverse_iterator(const_reverse_iterator const& other) {*this = other;}
            const_reverse_iterator(reverse_iterator const& other) {*this = other;}
            ~const_reverse_iterator() {}

            const_reverse_iterator&   operator--() {_element += 1; return *this;}
            const_reverse_iterator&   operator++() { _element -= 1; return *this;}
            const_reverse_iterator  operator+(difference_type val) const {return const_reverse_iterator(_element - val);}
            const_reverse_iterator  operator-(difference_type val) const {return const_reverse_iterator(_element + val);}
            const_reverse_iterator  operator+=(difference_type val) {return const_reverse_iterator(_element -= val);}
            const_reverse_iterator  operator-=(difference_type val) {return const_reverse_iterator(_element += val);}

            const_reference operator[](const_reference val) const {return _element[val];}
            value_type const&	operator*() const {return *_element;}
            value_type const*  operator->() const {return _element;}
            value_type *getElement() const {return _element;}
        };
        const_reverse_iterator rbegin() const {return(const_reverse_iterator(*(_vector + _size - 1)));}
        const_reverse_iterator rend() const {return(const_reverse_iterator(*(_vector - 1)));}
    };
}

#endif //FT_CONTAINERS_VECTOR_H
