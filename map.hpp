#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include <iterator>

namespace ft {
//    template<bool Cond, class T = void>
//    struct enable_if {
//    };
//    template<class T>
//    struct enable_if<true, T> {
//        typedef T type;
//    };

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
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
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ptrdiff_t difference_type;

//        template <class Key, class T, class Compare, class Alloc>
//        class map<Key,T,Compare,Alloc>::value_compare
//        {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
//            friend class map;
//        protected:
//            Compare comp;
//            value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
//        public:
//            typedef bool result_type;
//            typedef value_type first_argument_type;
//            typedef value_type second_argument_type;
//            bool operator() (const value_type& x, const value_type& y) const
//            {
//                return comp(x.first, y.first);
//            }
//        }

    private:

        typedef struct Stick {
            Stick *left;
            Stick *right;
            Stick *parent;
            pointer content;
        } stick;

        typedef typename allocator_type::template rebind<stick>::other allocator_rebind_type;
        allocator_rebind_type _allocator_rebind;
        allocator_type _alloc;
        size_type _size;
        stick *_begin;
        stick *_end;

        stick  *newStick(stick *parent, const value_type& comp) {
            stick  *newStick = _allocator_rebind.allocate(1);
            newStick->parent = parent;
            newStick->left = nullptr;
            newStick->right = nullptr;
            newStick->content = _alloc.allocate(1);
            _alloc.construct(newStick->content, comp);
            ++_size;
            return newStick;
        }

        void    deleteStick(stick *oldStick) {
            _alloc.desroy(oldStick->content);
            _alloc.deallocate(oldStick->content, 1);
            _alloc.deallocate(oldStick, 1);
            --_size;
        }

    public:

        explicit map (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type()) {

        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
             const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type());
        map (const map& x);

        class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
        private:
            stick *_element;
        public:

            explicit iterator(stick *pointer = nullptr) : _element(pointer) {}

            iterator(iterator const &other) { *this = other; }

            iterator(const_iterator const &other) { *this = other; }

            ~iterator() {}

            iterator &operator=(iterator const &other) {
                _element = other._element;
                return (*this);
            }

            iterator &operator=(const_iterator const &other) {
                _element = other.getElement();
                return (*this);
            }

            bool operator==(iterator const &other) { return other._element == _element; }

            bool operator!=(iterator const &other) { return other._element != _element; }

            iterator &operator--() {
                _element = _element->prev;
                return *this;
            }

            iterator &operator++() {
                _element = _element->next;
                return *this;
            }

            iterator operator++(int) {
                iterator temp(_element);
                operator++();
                return temp;
            }

            iterator operator--(int) {
                iterator temp(_element);
                operator--();
                return temp;
            }

            T &operator*() const { return *_element->content; }

            T *operator->() const { return _element->content; }

            stick *getElement() const { return _element; }
        };
    };
}


#endif