#include "gtest/gtest.h"
#include "map.hpp"
#include <map>

TEST(ConstructorEmpty, Map) {
    ft::map<int, int> my_map;
    std::map<int, int> def_map;

    ASSERT_EQ(my_map.size(), def_map.size());
//    ASSERT_EQ(my_map.max_size(), def_map.max_size());
    ASSERT_EQ(my_map.empty(), def_map.empty());
}

TEST(SquareBrackets, Map) {
    ft::map<int, int> my_map;
    std::map<int, int> def_map;

    my_map[2] = 5;
    def_map[2] = 5;
    ASSERT_EQ(my_map.size(), def_map.size());
    ASSERT_EQ(my_map.begin()->second, def_map.begin()->second);
}

TEST(Insert, Map) {
    ft::map<int, int> my_map;
    std::map<int, int> def_map;

    def_map.insert(std::make_pair(9, 4));
    my_map.insert(std::make_pair(9, 4));
    def_map.insert(std::make_pair(6, 4));
    my_map.insert(std::make_pair(6, 4));
    def_map.insert(std::make_pair(17, 4));
    my_map.insert(std::make_pair(17, 4));
    def_map.insert(std::make_pair(3, 4));
    my_map.insert(std::make_pair(3, 4));
    def_map.insert(std::make_pair(1, 4));
    my_map.insert(std::make_pair(1, 4));
    def_map.insert(std::make_pair(2, 4));
    my_map.insert(std::make_pair(2, 4));
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
    ASSERT_EQ(my_it->second, def_it->second);
    while (def_it != def_map.end()) {
        ASSERT_EQ(my_it->first, def_it->first);
        ASSERT_EQ(def_map.size(), my_map.size());
        ++def_it;
        ++my_it;
    }
    while (def_it != def_map.begin()) {
        --def_it;
        --my_it;
        ASSERT_EQ(my_it->first, def_it->first);
        ASSERT_EQ(def_map.size(), my_map.size());
    }


    def_map.insert(std::make_pair(3, 4));
    my_map.insert(std::make_pair(3, 4));
    ASSERT_EQ((def_map.insert(std::make_pair(3, 4))).second,
              (my_map.insert(std::make_pair(3, 4))).second);
}