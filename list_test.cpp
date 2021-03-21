//
// Created by Saturn Karry on 3/20/21.
//

#include "gtest/gtest.h"
#include "list.hpp"
#include <list>

TEST(ConstructorEmpty, List) {
    ft::list<int> my_list;

    ASSERT_EQ(my_list.size(), 0);
    ASSERT_TRUE(my_list.empty());
}

TEST(ConstructorNumVal, List) {
    ft::list<int> my_list(10,9);
    ft::list<int> my_list2(10);

    ft::list<int>::iterator it = my_list.begin();
    ft::list<int>::iterator it2 = my_list2.begin();
    for (size_t i = 0; i < 10; i++) {
        ASSERT_EQ(*it, 9);
        ASSERT_EQ(*it2, 0);
        ++it;
        ++it2;
    }
}

TEST(ConstructorCopy, List) {
    ft::list<int> my_list(60, 50);
    ft::list<int> my_list2(my_list);

    ft::list<int>::iterator it = my_list.begin();
    ft::list<int>::iterator it2 = my_list2.begin();
    ASSERT_EQ(my_list.size(), my_list2.size());
    for (size_t i = 0; i < 60; i++) {
        ASSERT_EQ(*it, *it2);
        ++it;
        ++it2;
    }
}

TEST(ConstructorIterators, List) {
    ft::list<int> my_list(60, 50);
    ft::list<int>::iterator it = my_list.begin();
    ft::list<int>::iterator ite = my_list.end();
    ft::list<int> my_list2(it, ite);


    ft::list<int>::iterator it2 = my_list.begin();
    ASSERT_EQ(my_list.size(), my_list2.size());
    for (size_t i = 0; i < 60; i++) {
        ASSERT_EQ(*it2, *it);
        ++it;
        ++it2;
    }

    std::list<int> default_list(60, 50);
    std::list<int>::iterator def_it = default_list.begin();
    std::list<int>::iterator def_ite = default_list.end();
    std::list<int> default_list2(def_it, def_ite);

    std::list<int>::iterator def_it2 = default_list.begin();
    ASSERT_EQ(default_list.size(), my_list2.size());
    for (size_t i = 0; i < 60; i++) {
        ASSERT_EQ(*def_it2, *def_it);
    }
}

TEST(OperatorEquals, List) {
    ft::list<int> my_list(5, 8);
    ft::list<int> my_list2 = my_list;

    ft::list<int>::iterator it = my_list.begin();
    ft::list<int>::iterator it2 = my_list2.begin();
    for (size_t i = 0; i < 5; i++) {
        ASSERT_EQ(*it, *it2);
        ++it;
        ++it2;
    }
}

TEST(Size, List) {
    std::list<int> default_list;
    std::list<int> default_list2(32, 4);

    ft::list<int> my_list;
    ft::list<int> my_list2(32, 4);
    ASSERT_EQ(default_list.size(), my_list.size());
    ASSERT_EQ(default_list2.size(), my_list2.size());
}

TEST(Max_size, List) {
    std::list<int> default_list;

    ft::list<int> my_list;
    ASSERT_EQ(default_list.max_size(), my_list.max_size());
}

TEST(Empty, List) {
    std::list<int> default_list;
    ft::list<int> my_list;

    ASSERT_EQ(default_list.empty(), my_list.empty());

    std::list<int> default_list2(3);
    ft::list<int> my_list2(3);

    ASSERT_EQ(default_list2.empty(), my_list2.empty());
}

TEST(Front, List) {
    std::list<int> default_list(5, 8);
    ft::list<int> my_list(5, 8);
    std::list<const int> default_list2(5, 8);
    ft::list<const int> my_list2(5, 8);

    ASSERT_EQ(default_list.front(), my_list.front());
    ASSERT_EQ(default_list2.front(), my_list2.front());

}

TEST(Back, List) {
    std::list<int> default_list(5, 8);
    ft::list<int> my_list(5, 8);
    std::list<const int> default_list2(5, 8);
    ft::list<const int> my_list2(5, 8);

    ASSERT_EQ(default_list.back(), my_list.back());
    ASSERT_EQ(default_list2.back(), my_list2.back());
}

TEST(Assign, List) {
    std::list<int> def_list;
    ft::list<int> my_list;

    def_list.assign (7,100);
    my_list.assign (7,100);

    def_list.assign (3,100);
    my_list.assign (3,100);

    ASSERT_EQ(def_list.size(), my_list.size());

    def_list.assign (43,100);
    my_list.assign (43,100);

    ASSERT_EQ(def_list.size(), my_list.size());

    std::list<int> def_list2;
    std::list<int> my_list2;

    std::list<int>::iterator def_it = def_list.begin();
    std::list<int>::iterator def_ite = def_list.end();

    ft::list<int>::iterator my_it = my_list.begin();
    ft::list<int>::iterator my_ite = my_list.end();

    def_list2.assign (def_it,def_ite);
    my_list2.assign (my_it,my_ite);

    ASSERT_EQ(def_list2.size(), my_list2.size());

    std::list<int>::iterator check_my_it = def_list.begin();
    ft::list<int>::iterator check_def_it = my_list.begin();
    for (size_t i = 0; i < 5; i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
}

TEST(Push_back, List) {
    std::list<int> def_list;
    ft::list<int> my_list;

    for (size_t i = 0; i < 10; i++) {
        def_list.push_back(i);
        my_list.push_back(i);
        ASSERT_EQ(def_list.size(), my_list.size());
    }

    std::list<int>::iterator check_my_it = def_list.begin();
    ft::list<int>::iterator check_def_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

TEST(Pop_back, List) {
    std::list<int> def_list;
    ft::list<int> my_list;

    for (size_t i = 0; i < 40; i++) {
        def_list.push_back(i);
        my_list.push_back(i);
    }

    def_list.pop_back();
    my_list.pop_back();
    std::list<int>::iterator check_my_it = def_list.begin();
    ft::list<int>::iterator check_def_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());

}

TEST(Push_front, List) {
    std::list<int> def_list;
    ft::list<int> my_list;

    for (size_t i = 0; i < 10; i++) {
        def_list.push_front(i);
        my_list.push_front(i);
        ASSERT_EQ(def_list.size(), my_list.size());
    }

    std::list<int>::iterator check_my_it = def_list.begin();
    ft::list<int>::iterator check_def_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

TEST(Pop_front, List) {
    std::list<int> def_list;
    ft::list<int> my_list;

    for (size_t i = 0; i < 40; i++) {
        def_list.push_front(i);
        my_list.push_front(i);
    }

    def_list.pop_front();
    my_list.pop_front();
    std::list<int>::iterator check_my_it = def_list.begin();
    ft::list<int>::iterator check_def_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());

}

TEST(Insert, List) {
    ft::list<int> my_list;
    std::list<int> def_list;

    for (int i=1; i<=10; i++) my_list.push_back(i);
    for (int i=1; i<=10; i++) def_list.push_back(i);

    ft::list<int>::iterator my_it = my_list.insert (my_list.begin(), 200 );
    std::list<int>::iterator def_it = def_list.insert ( def_list.begin(), 200 );
    my_list.insert (my_it, 200 );
    def_list.insert ( def_it, 200 );
    std::list<int>::iterator check_my_it = def_list.begin();
    ft::list<int>::iterator check_def_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(my_list.size(), def_list.size());

    my_list.insert (my_list.begin(),2,300);
    def_list.insert (def_list.begin(),2,300);
    ASSERT_EQ(my_list.size(), def_list.size());
    check_my_it = def_list.begin();
    check_def_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }

    ASSERT_EQ(my_list.size(), def_list.size());

    ft::list<int> my_list2;
    std::list<int> def_list2;

    for (int i=1; i<=10; i++) my_list2.push_back(i);
    for (int i=1; i<=10; i++) def_list2.push_back(i);
    my_list.insert (my_list.begin(),my_list2.begin(),my_list2.end());
    def_list.insert (def_list.begin(), def_list2.begin(),def_list2.end());
    check_my_it = def_list.begin();
    check_def_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(my_list.size(), def_list.size());
}

TEST(Erase, List) {
    ft::list<int> mylist;
    std::list<int> deflist;

    for (int i=1; i<=10; i++) mylist.push_back(i);
    for (int i=1; i<=10; i++) deflist.push_back(i);

    ft::list<int>::iterator my_it = mylist.begin();
    ++my_it; ++my_it;
    std::list<int>::iterator def_it = deflist.begin();
    ++def_it; ++def_it;
    mylist.erase (mylist.begin(),my_it);
    deflist.erase (deflist.begin(),def_it);
    std::list<int>::iterator check_my_it = deflist.begin();
    ft::list<int>::iterator check_def_it = mylist.begin();
    for (size_t i = 0; i < deflist.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }

    mylist.erase (mylist.begin());
    deflist.erase (deflist.begin());
    ASSERT_EQ(mylist.size(), deflist.size());
    check_my_it = deflist.begin();
    check_def_it = mylist.begin();
    for (size_t i = 0; i < deflist.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
}

TEST(Resize, List) {
    std::list<int> def_list(60, 5);
    ft::list<int> my_list(60, 5);
    def_list.resize(5);
    my_list.resize(5);

    def_list.resize(8,100);
    my_list.resize(8,100);

    def_list.resize(12);
    my_list.resize(12);

    ASSERT_EQ(def_list.size(), my_list.size());

    std::list<int>::iterator check_def_it = def_list.begin();
    ft::list<int>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
}

TEST(Clear, List) {
    std::list<int> def_list;
    ft::list<int> my_list;

    for (size_t i = 0; i < 40; i++) {
        def_list.push_back(i);
        my_list.push_back(i);
    }

    def_list.clear();
    my_list.clear();

    ASSERT_EQ(def_list.size(), my_list.size());
}

TEST(Splise, List) {
    std::list<int> def_list, def_list2;
    ft::list<int> my_list, my_list2;

    for (int i=1; i<=4; ++i) {
        def_list.push_back(i);
        my_list.push_back(i);
    }

    for (int i=1; i<=3; ++i) {
        def_list2.push_back(i * 10);
        my_list2.push_back(i * 10);
    }

    std::list<int>::iterator def_it = def_list.begin();
    ft::list<int>::iterator my_it = my_list.begin();
    ++def_it;
    ++my_it;

    def_list.splice (def_it, def_list2);
    my_list.splice (my_it, my_list2);

    std::list<int>::iterator check_def_it = def_list.begin();
    ft::list<int>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());

    def_list2.splice (def_list2.begin(),def_list, def_it);
    my_list2.splice (my_list2.begin(),my_list, my_it);
    ASSERT_EQ(def_list.size(), my_list.size());
    def_it = def_list.begin();
    my_it = my_list.begin();
    std::advance(def_it,3);           // "it" points now to 30
    std::advance(my_it,3);           // "it" points now to 30

    def_list.splice ( def_list.begin(), def_list, def_it, def_list.end());
    my_list.splice ( my_list.begin(), my_list, my_it, my_list.end());

    check_def_it = def_list2.begin();
    check_my_it = my_list2.begin();
    for (size_t i = 0; i < def_list2.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list2.size(), my_list2.size());
}

TEST(Remove, List) {
    int ints[]= {17,89,7,14};
    std::list<int> def_list (ints, ints+4);
    ft::list<int> my_list (ints, ints+4);

    def_list.remove(89);
    my_list.remove(89);

    std::list<int>::iterator check_def_it = def_list.begin();
    ft::list<int>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

bool single_digit (const int& value) { return (value<10); }

TEST(RemoveIf, List) {
    int ints[]= {15,36,7,17,20,39,4,1};
    std::list<int> def_list (ints, ints+7);
    ft::list<int> my_list (ints, ints+7);

    def_list.remove_if (single_digit);;
    my_list.remove_if (single_digit);;

    std::list<int>::iterator check_def_it = def_list.begin();
    ft::list<int>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

TEST(Unique, List) {
    double doubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                         12.77, 73.35, 72.25, 15.3,  72.25 };
    std::list<double> def_list (doubles, doubles+10);
    ft::list<double> my_list (doubles, doubles+10);

    my_list.sort();
    def_list.sort();

    my_list.unique();
    def_list.unique();

    my_list.unique (same_integral_part);
    def_list.unique (same_integral_part);

    std::list<double>::iterator check_def_it = def_list.begin();
    ft::list<double>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

bool mycomparison (double first, double second)
{ return (first>second ); }

TEST(Merge, List) {
    std::list<double> def_list, def_list2;
    ft::list<double> my_list, my_list2;

    def_list.push_back (3.1);
    def_list.push_back (2.2);
    def_list.push_back (2.9);
    my_list.push_back (3.1);
    my_list.push_back (2.2);
    my_list.push_back (2.9);

    def_list2.push_back (3.7);
    def_list2.push_back (7.1);
    def_list2.push_back (1.4);
    my_list2.push_back (3.7);
    my_list2.push_back (7.1);
    my_list2.push_back (1.4);

    def_list.sort();
    def_list2.sort();
    my_list.sort();
    my_list2.sort();


    def_list.merge(def_list2);
    def_list2.push_back (2.1);
    my_list.merge(my_list2);
    my_list2.push_back (2.1);

    std::list<double>::iterator check_def_it = def_list.begin();
    ft::list<double>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());

    my_list.merge(my_list2,mycomparison);
    def_list.merge(def_list2,mycomparison);

    check_def_it = def_list.begin();
    check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

bool compare_nocase (const std::string& first, const std::string& second)
{
    unsigned int i=0;
    while ( (i<first.length()) && (i<second.length()) )
    {
        if (tolower(first[i])<tolower(second[i])) return true;
        else if (tolower(first[i])>tolower(second[i])) return false;
        ++i;
    }
    return ( first.length() < second.length() );
}

TEST(Sort, List) {
    std::list<std::string> def_list;
    def_list.push_back ("one");
    def_list.push_back ("two");
    def_list.push_back ("Three");

    ft::list<std::string> my_list;
    my_list.push_back ("one");
    my_list.push_back ("two");
    my_list.push_back ("Three");

    def_list.sort();
    my_list.sort();

    std::list<std::string>::iterator check_def_it = def_list.begin();
    ft::list<std::string>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());

    def_list.sort(compare_nocase);
    my_list.sort(compare_nocase);

    check_def_it = def_list.begin();
    check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

TEST(Reverse, List) {
    std::list<int> def_list;
    ft::list<int> my_list;

    for (int i=1; i<10; ++i) {
        def_list.push_back(i);
        my_list.push_back(i);
    }

    def_list.reverse();
    my_list.reverse();

    std::list<int>::iterator check_def_it = def_list.begin();
    ft::list<int>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

TEST(SwapLists, List) {
    std::list<int> def_list(3, 100);
    ft::list<int> my_list(3, 100);
    std::list<int> def_list2(5, 200);
    ft::list<int> my_list2(5, 200);

    ft::swap(my_list, my_list2);
    std::swap(def_list, def_list2);

    std::list<int>::iterator check_def_it = def_list.begin();
    ft::list<int>::iterator check_my_it = my_list.begin();
    for (size_t i = 0; i < def_list.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());

    check_def_it = def_list2.begin();
    check_my_it = my_list2.begin();
    for (size_t i = 0; i < def_list2.size(); i++) {
        ASSERT_EQ(*check_my_it, *check_def_it);
        ++check_my_it;
        ++check_def_it;
    }
    ASSERT_EQ(def_list.size(), my_list.size());
}

TEST(RelationalOperators, List) {
    std::list<int> default_list(3, 100);
    ft::list<int> my_list(3, 100);
    std::list<int> default_list2(5, 200);
    ft::list<int> my_list2(5, 200);

    ASSERT_EQ((default_list==default_list2), (my_list==my_list2));
    ASSERT_EQ((default_list!=default_list2), (my_list!=my_list2));
    ASSERT_EQ((default_list>=default_list2), (my_list>=my_list2));
    ASSERT_EQ((default_list<=default_list2), (my_list<=my_list2));
    ASSERT_EQ((default_list>default_list2), (my_list>my_list2));
    ASSERT_EQ((default_list<default_list2), (my_list<my_list2));
}

TEST(Iterator, List) {
    ft::list<int> my_list;
    std::list<int> default_list;
    for (size_t i = 0; i < 10; i++) {
        my_list.push_back(i);
        default_list.push_back(i);
    }
    ft::list<int>::iterator it = my_list.begin();
    std::list<int>::iterator def_it = default_list.begin();
    ft::list<int>::iterator ite = my_list.end();
    std::list<int>::iterator def_ite = default_list.end();
    ASSERT_EQ(*it, *def_it);
    ++it; ++def_it;
    ASSERT_EQ(*it, *def_it);
    it++; def_it++;
    ASSERT_EQ(*it, *def_it);
    --it; --def_it;
    ASSERT_EQ(*it, *def_it);

    ite--; def_ite--;
    ASSERT_EQ(*ite, *def_ite);
    ASSERT_EQ(*ite, *def_ite);

    ASSERT_TRUE(it == it);
    ASSERT_FALSE(it != it);

    ft::list<int>::const_iterator my_const_it(it);

    ASSERT_TRUE(it == my_const_it);
    ASSERT_FALSE(it != my_const_it);
}

TEST(ConstIterator, List) {
    ft::list<int> my_list;
    std::list<int> default_list;
    for (size_t i = 0; i < 10; i++) {
        my_list.push_back(i);
        default_list.push_back(i);
    }
    ft::list<int>::const_iterator it = my_list.begin();
    std::list<int>::const_iterator def_it = default_list.begin();
    ft::list<int>::const_iterator ite = my_list.end();
    std::list<int>::const_iterator def_ite = default_list.end();
    ASSERT_EQ(*it, *def_it);
    ++it; ++def_it;
    ASSERT_EQ(*it, *def_it);
    it++; def_it++;
    ASSERT_EQ(*it, *def_it);
    --it; --def_it;
    ASSERT_EQ(*it, *def_it);

    ite--; def_ite--;
    ASSERT_EQ(*ite, *def_ite);

    ASSERT_EQ(*ite, *def_ite);

    ASSERT_TRUE(it == it);
    ASSERT_FALSE(it != it);

    ft::list<int>::iterator my_not_const_it = my_list.begin();
    it = my_list.begin();

    ASSERT_TRUE(it == my_not_const_it);
    ASSERT_FALSE(it != my_not_const_it);
}


TEST(ReverseIterator, List) {
    ft::list<int> my_list;
    std::list<int> default_list;
    for (size_t i = 0; i < 10; i++) {
        my_list.push_back(i);
        default_list.push_back(i);
    }
    ft::list<int>::reverse_iterator it = my_list.rbegin();
    std::list<int>::reverse_iterator def_it = default_list.rbegin();
    ft::list<int>::reverse_iterator ite = my_list.rend();
    std::list<int>::reverse_iterator def_ite = default_list.rend();
    ASSERT_EQ(*it, *def_it);
    ++it; ++def_it;
    ASSERT_EQ(*it, *def_it);
    --it; --def_it;

    ASSERT_EQ(*it, *def_it);
    --ite;
    --def_ite;
    ASSERT_EQ(*ite, *def_ite);

}

TEST(ConstReverseIterator, List) {
    ft::list<int> my_list;
    std::list<int> default_list;
    for (size_t i = 0; i < 10; i++) {
        my_list.push_back(i);
        default_list.push_back(i);
    }
    ft::list<int>::const_reverse_iterator it = my_list.rbegin();
    std::list<int>::const_reverse_iterator def_it = default_list.rbegin();
    ft::list<int>::const_reverse_iterator ite = my_list.rend();
    std::list<int>::const_reverse_iterator def_ite = default_list.rend();
    ASSERT_EQ(*it, *def_it);
    ++it; ++def_it;
    ASSERT_EQ(*it, *def_it);
    --it; --def_it;
    ASSERT_EQ(*it, *def_it);

    --ite;
    --def_ite;
    ASSERT_EQ(*ite, *def_ite);
}