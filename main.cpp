//
// Created by Saturn Karry on 3/24/21.
//

#include "map.hpp"
#include <map>
#include <iostream>

int main() {
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    // insert some values:
    mymap['d']=40;
    mymap['e']=50;
    mymap['c']=30;
    mymap['a']=10;
    mymap['b']=20;
    mymap['f']=60;

    it=mymap.find('f');
    mymap.erase (it);                   // erasing by iterator

    mymap.erase ('c');                  // erasing by key

//    it=mymap.find ('e');
//    mymap.erase ( it, mymap.end() );    // erasing by range

    // show content:
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    return 0;
}

