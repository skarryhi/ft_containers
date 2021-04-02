//
// Created by Saturn Karry on 4/2/21.
//

#ifndef FT_CONTAINERS_FT_H
#define FT_CONTAINERS_FT_H

namespace ft {
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
}
#endif //FT_CONTAINERS_FT_H
