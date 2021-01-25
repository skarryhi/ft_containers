#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include <iterator>

namespace ft {
    template <typename T, class Alloc = std::allocator<T> >
    class list {
    public:
        class allocator;
        class iterator;
        class const_iterator;
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef size_t  size_type;
        typedef typename allocator_type::reference reference;
        typedef	typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ptrdiff_t difference_type;
        //iterators
        class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
        private:
            value_type  *_element;
        public:
            iterator() : _element(nullptr) {}

            iterator(value_type *pointer) : _element(pointer) {}

            ~iterator() {}

            iterator(iterator const& other) {*this = other;}

            iterator&    operator=(iterator const& other) {
                _element = other._element;
                return(*this);
            } // дописать работу с памятью

        };

        class reverse_iterator : public std::reverse_iterator<iterator> {};


        //constructors
        explicit list (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0) { startList(); }
        explicit list (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n) {
            startList();
            while (n--) {
                push_back(val);
            }
        }
        // template <class InputIterator>
        // list (InputIterator first, InputIterator last,
        //     const allocator_type& alloc = allocator_type());
        // list (const list& x);
        iterator begin() {return(iterator(&this->_begin));}
        iterator end() {return(iterator(&this->_end));}

        void     push_back(const value_type& val) {
            if (_end->next == _end) {
                t_list  *newList = newContentList(val);
                newList->prev = _end;
                newList->next = _end;
                _end->next = newList;
                _end->prev = newList;
            } else {
                t_list  *newList = newContentList(val);
                _end->prev->next = newList;
                newList->prev = _end->prev;
                newList->next = _end;
                _end->prev = newList;
            }
        }
    private:
        typedef struct      s_list
        {
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
            _end = newList();
            _end->next = _end;
            _end->prev = _end;
        }

        t_list  *newList() {
            t_list  *newList = _allocator_rebind.allocate(1);
            newList->content = _alloc.allocate(1);
            _alloc.construct(newList->content, val);
            return newList;
        }

        t_list  *newContentList(const value_type& val) {
            t_list  *newList = _allocator_rebind.allocate(1);
            newList->content = _alloc.allocate(1);
            _alloc.construct(newList->content, val);
            return newList;
        }
    };
}

#endif