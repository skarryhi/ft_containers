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

    ft::map<int, int> my_map2;
    std::map<int, int> def_map2;

    def_map2.insert(std::make_pair(30, 4));
    my_map2.insert(std::make_pair(30, 4));
    def_map2.insert(std::make_pair(0, 4));
    my_map2.insert(std::make_pair(0, 4));

    def_map.insert(def_map2.begin(), def_map2.end());
    my_map.insert(my_map2.begin(), my_map2.end());

    my_it = my_map.begin();
    def_it = def_map.begin();
    while (def_it != def_map.end()) {
        ASSERT_EQ(my_it->first, def_it->first);
        ASSERT_EQ(def_map.size(), my_map.size());
        ++def_it;
        ++my_it;
    }

}

TEST(InsertPosition, Map) {
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

    my_map.insert(my_map.lower_bound(10), std::make_pair(10, 4));
    def_map.insert(def_map.lower_bound(10), std::make_pair(10, 4));

    ft::map<int, int>::iterator my_it = my_map.begin();
    std::map<int, int>::iterator def_it = def_map.begin();
    ASSERT_EQ(my_it->second, def_it->second);
    while (def_it != def_map.end()) {
        ASSERT_EQ(my_it->first, def_it->first);
        ASSERT_EQ(def_map.size(), my_map.size());
        ++def_it;
        ++my_it;
    }
}

TEST(Swap, Map) {

}

TEST(Key_comp, Map) {
    ft::map<char,int> my_map;
    std::map<char,int> def_map;

    ft::map<char,int>::key_compare my_comp = my_map.key_comp();
    std::map<char,int>::key_compare def_comp = def_map.key_comp();

    my_map['a']=100;    def_map['a']=100;
    my_map['b']=200;    def_map['b']=200;
    my_map['c']=300;    def_map['c']=300;

    char my_highest = my_map.rbegin()->first;     // key value of last element
    char def_highest = def_map.rbegin()->first;     // key value of last element

    ft::map<char,int>::iterator my_it = my_map.begin();
    std::map<char,int>::iterator def_it = def_map.begin();
    do {
        ASSERT_EQ(my_it->first, def_it->first);
        ++my_it;
    } while ( my_comp((*def_it++).first, def_highest) );
}

TEST(Value_comp, Map) {
    ft::map<char,int> my_map;
    std::map<char,int> def_map;

    my_map['x']=1001;   def_map['x']=1001;
    my_map['y']=2002;   def_map['y']=2002;
    my_map['z']=3003;   def_map['z']=3003;


    std::pair<char,int> highest = *def_map.rbegin();          // last element

    ft::map<char,int>::iterator my_it = my_map.begin();
    std::map<char,int>::iterator def_it = def_map.begin();
    do {
        ASSERT_EQ(my_it->first, def_it->first);
        ++def_it;
    } while ( my_map.value_comp()(*my_it++, highest) );
}

TEST(Find, Map) {
    ft::map<const char, int> my_map;
    std::map<const char,int> def_map;

    my_map['a']=50;
    my_map['b']=100;
    my_map['c']=150;
    my_map['d']=200;

    def_map['a']=50;
    def_map['b']=100;
    def_map['c']=150;
    def_map['d']=200;

    ASSERT_EQ(my_map.find('a')->second, def_map.find('a')->second);
    ASSERT_EQ(my_map.find('b')->second, def_map.find('b')->second);
    ASSERT_EQ(my_map.find('c')->second, def_map.find('c')->second);
    ASSERT_EQ(my_map.find('d')->second, def_map.find('d')->second);
}

TEST(Count, Map) {
    ft::map<char,int> my_map;
    std::map<char,int> def_map;
    char c;

    my_map ['a']=101;
    my_map ['c']=202;
    my_map ['f']=303;

    def_map ['a']=101;
    def_map ['c']=202;
    def_map ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        ASSERT_EQ(my_map.count(c), def_map.count(c));
    }
}

TEST(Lower_Upper_bound, Map) {
    ft::map<const int,int> my_map;
    std::map<const int,int> def_map;
    ft::map<const int,int>::const_iterator my_it;
    std::map<const int,int>::const_iterator def_it;

    my_map[3]=20;
    my_map[6]=40;
    my_map[9]=80;
    my_map[20]=100;

    def_map[3]=20;
    def_map[6]=40;
    def_map[9]=80;
    def_map[20]=100;

    ASSERT_EQ(my_map.lower_bound(6)->second, def_map.lower_bound(6)->second);
    ASSERT_EQ(my_map.lower_bound(1)->second, def_map.lower_bound(1)->second);
    ASSERT_EQ(my_map.upper_bound(6)->second, def_map.upper_bound(6)->second);
    ASSERT_EQ(my_map.upper_bound(1)->second, def_map.upper_bound(1)->second);
}

TEST(Equal_range, Map) {
    ft::map<char,int> my_map;
    std::map<char,int> def_map;

    my_map['a']=10;
    my_map['b']=20;
    my_map['c']=30;

    def_map['a']=10;
    def_map['b']=20;
    def_map['c']=30;

    std::pair<ft::map<char,int>::const_iterator,ft::map<char,int>::const_iterator> my_ret;
    std::pair<std::map<char,int>::const_iterator,std::map<char,int>::const_iterator> def_ret;
    my_ret = my_map.equal_range('b');
    def_ret = def_map.equal_range('b');
    ASSERT_EQ(my_ret.first->second, def_ret.first->second);
    ASSERT_EQ(my_ret.second->second, def_ret.second->second);
}


TEST(Erase, Map) {
    ft::map<char,int> my_map;
    std::map<char,int> def_map;
    ft::map<char,int>::iterator my_it;
    std::map<char,int>::iterator def_it;

    my_map['a']=10;
    my_map['b']=20;
    my_map['c']=30;
    my_map['d']=40;
    my_map['e']=50;
    my_map['f']=60;

    def_map['a']=10;
    def_map['b']=20;
    def_map['c']=30;
    def_map['d']=40;
    def_map['e']=50;
    def_map['f']=60;

    my_it = my_map.find('b');
    my_map.erase (my_it);
    my_map.erase ('c');
    my_it = my_map.find ('e');
    my_map.erase ( my_it, my_map.end());

    def_it = def_map.find('b');
    def_map.erase (def_it);
    def_map.erase ('c');
    def_it = def_map.find ('e');
    def_map.erase ( def_it, def_map.end() );

    my_it = my_map.begin();
    for (def_it = def_map.begin(); def_it != def_map.end(); ++def_it) {
        ASSERT_EQ(my_it->first, def_it->first);
        ++my_it;
    }
}