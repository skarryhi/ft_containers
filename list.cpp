#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>

template <typename T, class Alloc = allocator<T> >
class list {
private:
    typedef struct     s_list
    {
        struct s_list *next;
        struct s_list *prev;
        T               *content;
    }        t_list;
    t_list              *list;
    
public:
    explicit list (const allocator_type& alloc = allocator_type());
    explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type());
    template <class InputIterator>
    list (InputIterator first, InputIterator last,
         const allocator_type& alloc = allocator_type());
    list (const list& x);
};

#endif