//
// Created by Saturn Karry on 3/24/21.
//

#include "map.hpp"
#include <map>
#include <iostream>

int main() {
    ft::map<int, int> my_map;
    std::map<int, int> def_map;

    def_map.insert(std::make_pair(9, 4));
    my_map.insert(std::make_pair(9, 4));
//    std::cout << my_map._begin->parent->content->first << std::endl;
    def_map.insert(std::make_pair(6, 4));
    my_map.insert(std::make_pair(6, 4));
//    std::cout << my_map._begin->parent->content->first << std::endl;
    def_map.insert(std::make_pair(17, 4));
    my_map.insert(std::make_pair(17, 4));
//    std::cout << my_map._begin->parent->content->first << std::endl;
    def_map.insert(std::make_pair(3, 4));
    my_map.insert(std::make_pair(3, 4));
//    std::cout << my_map._begin->parent->content->first << std::endl;
    def_map.insert(std::make_pair(1, 4));
    my_map.insert(std::make_pair(1, 4));
//    std::cout << my_map._begin->parent->content->first << std::endl;
    def_map.insert(std::make_pair(2, 4));
    my_map.insert(std::make_pair(2, 4));
//    std::cout << my_map._begin->parent->content->first << std::endl;
    def_map.insert(std::make_pair(4, 4));
    my_map.insert(std::make_pair(4, 4));
    def_map.insert(std::make_pair(5, 4));
    my_map.insert(std::make_pair(5, 4));
    def_map.insert(std::make_pair(8, 4));
    my_map.insert(std::make_pair(8, 4));
    def_map.insert(std::make_pair(7, 4));
    my_map.insert(std::make_pair(7, 4));
    def_map.insert(std::make_pair(16, 4));
    my_map.insert(std::make_pair(16, 4));
    def_map.insert(std::make_pair(20, 4));
    my_map.insert(std::make_pair(20, 4));
    def_map.insert(std::make_pair(19, 4));
    my_map.insert(std::make_pair(19, 4));
    def_map.insert(std::make_pair(18, 4));
    my_map.insert(std::make_pair(18, 4));

    ft::map<int, int>::iterator my_it = my_map.begin();
    std::map<int, int>::iterator def_it = def_map.begin();
    while (def_it != def_map.end()) {
        std::cout << "my: " << my_it->first << std::endl;
        std::cout << "def: " << def_it->first << std::endl;
        ++def_it;
        ++my_it;
    }
}

