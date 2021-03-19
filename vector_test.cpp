//
// Created by Saturn Karry on 3/9/21.
//

#include "gtest/gtest.h"
#include "vector.hpp"
#include <vector>

TEST(ConstructorEmpty, Vector) {
    ft::vector<int> my_vector;

    ASSERT_EQ(my_vector.size(), 0);
    ASSERT_EQ(my_vector.capacity(), 0);
    ASSERT_TRUE(my_vector.empty());
}

TEST(ConstructorNumVal, Vector) {
    ft::vector<int> my_vector(10,9);
    ft::vector<int> my_vector2(10);

    for (size_t i = 0; i < 10; i++) {
        ASSERT_EQ(my_vector[i], 9);
        ASSERT_EQ(my_vector2[i], 0);
    }
}

TEST(ConstructorCopy, Vector) {
    ft::vector<int> my_vector(60, 50);
    ft::vector<int> my_vector2(my_vector);

    ASSERT_EQ(my_vector.size(), my_vector2.size());
    ASSERT_EQ(my_vector.capacity(), my_vector2.capacity());
    for (size_t i = 0; i < 60; i++) {
        ASSERT_EQ(my_vector[i], my_vector2[i]);
    }
}

TEST(ConstructorIterators, Vector) {
    ft::vector<int> my_vector(60, 50);
    ft::vector<int>::iterator it = my_vector.begin();
    ft::vector<int>::iterator ite = my_vector.end();
    ft::vector<int> my_vector2(it, ite);

    ASSERT_EQ(my_vector.size(), my_vector2.size());
    ASSERT_EQ(my_vector.capacity(), my_vector2.capacity());
    for (size_t i = 0; i < 60; i++) {
        ASSERT_EQ(my_vector[i], my_vector2[i]);
    }

    std::vector<int> default_vector(60, 50);
    std::vector<int>::iterator def_it = default_vector.begin();
    std::vector<int>::iterator def_ite = default_vector.end();
    std::vector<int> default_vector2(def_it, def_ite);

    ASSERT_EQ(default_vector.size(), my_vector2.size());
    ASSERT_EQ(default_vector.capacity(), my_vector2.capacity());
    for (size_t i = 0; i < 60; i++) {
        ASSERT_EQ(default_vector[i], default_vector2[i]);
    }
}

TEST(OperatorEquals, Vector) {
    ft::vector<int> my_vector(5, 8);
    ft::vector<int> my_vector2 = my_vector;

    for (size_t i = 0; i < 5; i++)
        ASSERT_EQ(my_vector[i], my_vector2[i]);
    my_vector[2] = 7;
    ASSERT_EQ(my_vector[2], 7);

    std::vector<int> def_vector(5, 8);
    std::vector<int> def_vector2 = def_vector;

    for (size_t i = 0; i < 5; i++)
        ASSERT_EQ(def_vector[i], def_vector2[i]);
    def_vector[2] = 7;
    ASSERT_EQ(def_vector[2], 7);
}

TEST(Size, Vector) {
    std::vector<int> default_vector;
    std::vector<int> default_vector2(32, 4);

    ft::vector<int> my_vector;
    ft::vector<int> my_vector2(32, 4);
ASSERT_EQ(default_vector.size(), my_vector.size());
ASSERT_EQ(default_vector2.size(), my_vector2.size());
}

TEST(Max_size, Vector) {
    std::vector<int> default_vector;

    ft::vector<int> my_vector;
    ASSERT_EQ(default_vector.max_size(), my_vector.max_size());
}

TEST(Resize, Vector) {
    std::vector<int> default_vector(60, 5);
    default_vector.resize(5);
    default_vector.resize(8,100);
    default_vector.resize(12);

    ft::vector<int> my_vector(60, 5);
    my_vector.resize(5);
    my_vector.resize(8,100);
    my_vector.resize(12);

    for (size_t i = 0; i < 12; i++)
        ASSERT_EQ(default_vector[i], my_vector[i]);
    ASSERT_EQ(default_vector.size(), my_vector.size());
}

TEST(Capacity , Vector) {
    ft::vector<int> my_vector(9,100);
    std::vector<int> default_vector(9,100);
    ASSERT_EQ(default_vector.capacity(), my_vector.capacity());

    my_vector.push_back(1);
    default_vector.push_back(1);
    ASSERT_EQ(default_vector.capacity(), my_vector.capacity());

}

TEST(Empty, Vector) {
    std::vector<int> default_vector;
    ft::vector<int> my_vector;

    ASSERT_EQ(default_vector.empty(), my_vector.empty());

    std::vector<int> default_vector2(3);
    ft::vector<int> my_vector2(3);

    ASSERT_EQ(default_vector2.empty(), my_vector2.empty());
}

TEST(Reserve, Vector) {
    std::vector<int> default_vector;
    ft::vector<int> my_vector;

    default_vector.reserve(100);
    my_vector.reserve(100);

    ASSERT_EQ(default_vector.capacity(), my_vector.capacity());
}

TEST(Square_parentheses, Vector) {
    std::vector<int> default_vector(5, 8);
    ft::vector<int> my_vector(5, 8);
    std::vector<const int> default_vector2(5, 8);
    ft::vector<const int> my_vector2(5, 8);

    my_vector[4] = 6;
    default_vector[4] = 6;
    for (size_t i = 0; i < 5; i++)
        ASSERT_EQ(default_vector[i], my_vector[i]);

//    my_vector2[4] = 6;  //const values
//    default_vector2[4] = 6;
    for (size_t i = 0; i < 5; i++)
        ASSERT_EQ(default_vector2[i], my_vector2[i]);
}

TEST(At, Vector) {
    int i;
    ft::vector<const int> my_vector(5, 5);

    try {
        i = my_vector.at(8);
    } catch (const std::exception& e) {
        SUCCEED();
    }
}

TEST(Front, Vector) {
    std::vector<int> default_vector(5, 8);
    ft::vector<int> my_vector(5, 8);
    std::vector<const int> default_vector2(5, 8);
    ft::vector<const int> my_vector2(5, 8);

    ASSERT_EQ(default_vector.front(), my_vector.front());
    ASSERT_EQ(default_vector2.front(), my_vector2.front());

}

TEST(Back, Vector) {
    std::vector<int> default_vector(5, 8);
    ft::vector<int> my_vector(5, 8);
    std::vector<const int> default_vector2(5, 8);
    ft::vector<const int> my_vector2(5, 8);

    ASSERT_EQ(default_vector.back(), my_vector.back());
    ASSERT_EQ(default_vector2.back(), my_vector2.back());
}


TEST(Assign, Vector) {
    std::vector<int> def_vector;
    ft::vector<int> my_vector;

    def_vector.assign (7,100);
    my_vector.assign (7,100);

    def_vector.assign (3,100);
    my_vector.assign (3,100);

    ASSERT_EQ(def_vector.capacity(), my_vector.capacity());
    ASSERT_EQ(def_vector.size(), my_vector.size());

    def_vector.assign (43,100);
    my_vector.assign (43,100);

    ASSERT_EQ(def_vector.capacity(), my_vector.capacity());
    ASSERT_EQ(def_vector.size(), my_vector.size());

    std::vector<int> def_vector2;
    std::vector<int> my_vector2;

    std::vector<int>::iterator def_it = def_vector.begin();
    std::vector<int>::iterator def_ite = def_vector.end() - 3;

    ft::vector<int>::iterator my_it = my_vector.begin();
    ft::vector<int>::iterator my_ite = my_vector.end() - 3;

    def_vector.assign (def_it,def_ite);
    my_vector.assign (my_it,my_ite);

    def_vector[5] = 6;
    my_vector[5] = 6;

    ASSERT_EQ(def_vector.capacity(), my_vector.capacity());
    ASSERT_EQ(def_vector.size(), my_vector.size());

    for (size_t i = 0; i < 40; i++) {
        ASSERT_EQ(def_vector[i], my_vector[i]);
    }
}
TEST(Push_back, Vector) {
    std::vector<int> def_vector;
    ft::vector<int> my_vector;

    for (size_t i = 0; i < 10; i++) {
        def_vector.push_back(i);
        my_vector.push_back(i);
        ASSERT_EQ(def_vector.size(), my_vector.size());
    }

    for (size_t i = 0; i < 10; i++) {
        ASSERT_EQ(def_vector[i], my_vector[i]);
        ASSERT_EQ(def_vector.size(), my_vector.size());
        ASSERT_EQ(def_vector.capacity(), my_vector.capacity());
    }
}

TEST(Pop_back, Vector) {
    std::vector<int> def_vector;
    ft::vector<int> my_vector;

    for (size_t i = 0; i < 40; i++) {
        def_vector.push_back(i);
        my_vector.push_back(i);
    }

    def_vector.pop_back();
    my_vector.pop_back();
    for (size_t i = 0; i < 39; i++) {
        ASSERT_EQ(def_vector[i], my_vector[i]);
    }
    ASSERT_EQ(def_vector.size(), my_vector.size());
    ASSERT_EQ(def_vector.capacity(), my_vector.capacity());

}

//TEST(Insert, Vector) {
//    ft::vector<int> my_vector;
//    std::vector<int> def_vector;
//
//    for (int i=1; i<=10; i++) my_vector.push_back(i);
//    for (int i=1; i<=10; i++) def_vector.push_back(i);
//
////    ft::vector<int>::iterator my_it = my_vector.insert (my_vector.begin() + 2, 200 );
////    std::vector<int>::iterator def_it = def_vector.insert ( def_vector.begin() + 2, 200 );
////    my_vector.insert (my_it, 200 );
////    def_vector.insert ( def_it, 200 );
////    for (size_t i = 0; i < 10; i++) {
////        ASSERT_EQ(def_vector[i], my_vector[i]);
////    }
////    ASSERT_EQ(my_vector.size(), def_vector.size());
////    ASSERT_EQ(my_vector.capacity(), def_vector.capacity());
////
////    my_vector.insert (my_vector.begin(),2,300);
////    def_vector.insert (def_vector.begin(),2,300);
////    ASSERT_EQ(my_vector.size(), def_vector.size());
////    ASSERT_EQ(my_vector.capacity(), def_vector.capacity());
////    for (size_t i = 0; i < def_vector.size(); i++) {
////        ASSERT_EQ(def_vector[i], my_vector[i]);
////    }
////
////    ASSERT_EQ(my_vector.size(), def_vector.size());
////    ASSERT_EQ(my_vector.capacity(), def_vector.capacity());
//
//    ft::vector<int> my_vector2;
//    std::vector<int> def_vector2;
//
//    for (int i=1; i<=10; i++) my_vector2.push_back(i);
//    for (int i=1; i<=10; i++) def_vector2.push_back(i);
//    my_vector.insert (my_vector.begin(),my_vector2.begin(),my_vector2.end());
//    def_vector.insert (def_vector.begin(), def_vector2.begin(),def_vector2.end());
//    for (size_t i = 0; i < def_vector.size(); i++) {
//        ASSERT_EQ(def_vector[i], my_vector[i]);
//    }
//    ASSERT_EQ(my_vector.size(), def_vector.size());
//    ASSERT_EQ(my_vector.capacity(), def_vector.capacity());
//}

TEST(Erase, Vector) {
    ft::vector<int> myvector;
    std::vector<int> defvector;

    for (int i=1; i<=10; i++) myvector.push_back(i);
    for (int i=1; i<=10; i++) defvector.push_back(i);

    myvector.erase (myvector.begin(),myvector.begin()+3);
    defvector.erase (defvector.begin(),defvector.begin()+3);
    for (int i=0; i<defvector.size(); i++) ASSERT_EQ(myvector[i], defvector[i]);;
    ASSERT_EQ(myvector.size(), defvector.size());
    ASSERT_EQ(myvector.capacity(), defvector.capacity());

    myvector.erase (myvector.begin()+3);
    defvector.erase (defvector.begin()+3);
    ASSERT_EQ(myvector.size(), defvector.size());
    ASSERT_EQ(myvector.capacity(), defvector.capacity());
    for (int i=0; i<defvector.size(); i++) ASSERT_EQ(myvector[i], defvector[i]);;

}

TEST(Swap, Vector) {
    std::vector<int> foo (3,100);
    std::vector<int> bar (5,200);
    ft::vector<int> my_foo (3,100);
    ft::vector<int> my_bar (5,200);

    foo.swap(bar);
    my_foo.swap(my_bar);

    for (size_t i = 0; i < foo.size(); i++) {
        ASSERT_EQ(foo[i], my_foo[i]);
    }
    ASSERT_EQ(foo.size(), my_foo.size());
    ASSERT_EQ(foo.capacity(), my_foo.capacity());
    ASSERT_EQ(bar.size(), my_bar.size());
    ASSERT_EQ(bar.capacity(), my_bar.capacity());
}

TEST(Clear, Vector) {
    std::vector<int> def_vector;
    ft::vector<int> my_vector;

    for (size_t i = 0; i < 40; i++) {
        def_vector.push_back(i);
        my_vector.push_back(i);
    }

    def_vector.clear();
    my_vector.clear();

    ASSERT_EQ(def_vector.size(), my_vector.size());
    ASSERT_EQ(def_vector.capacity(), my_vector.capacity());
}

TEST(Iterator, Vector) {
    ft::vector<int> my_vector;
    std::vector<int> default_vector;
    for (size_t i = 0; i < 10; i++) {
        my_vector.push_back(i);
        default_vector.push_back(i);
    }
    ft::vector<int>::iterator it = my_vector.begin();
    std::vector<int>::iterator def_it = default_vector.begin();
    ft::vector<int>::iterator ite = my_vector.end();
    std::vector<int>::iterator def_ite = default_vector.end();
    ASSERT_EQ(*it, *def_it);
    ++it; ++def_it;
    ASSERT_EQ(*it, *def_it);
    it++; def_it++;
    ASSERT_EQ(*it, *def_it);
    --it; --def_it;
    ASSERT_EQ(*it, *def_it);

    ite--; def_ite--;
    ASSERT_EQ(*ite, *def_ite);
    ite = ite - 3; def_ite = def_ite - 3;
    ASSERT_EQ(*ite, *def_ite);
    ite = ite + 2; def_ite = def_ite + 2;
    ASSERT_EQ(*ite, *def_ite);
    ite -= 3; def_ite -= 3;
    ASSERT_EQ(*ite, *def_ite);
    ite += 2; def_ite += 2;
    ASSERT_EQ(*ite, *def_ite);
    ASSERT_EQ(ite[1], def_ite[1]);

    ASSERT_TRUE(it == it);
    ASSERT_FALSE(it != it);
    ASSERT_FALSE(it > it);
    ASSERT_FALSE(it < it);
    ASSERT_TRUE(it <= it);
    ASSERT_TRUE(it >= it);

    ft::vector<int>::const_iterator my_const_it(it);

    ASSERT_TRUE(it == my_const_it);
    ASSERT_FALSE(it != my_const_it);
    ASSERT_FALSE(it > my_const_it);
    ASSERT_FALSE(it < my_const_it);
    ASSERT_TRUE(it <= my_const_it);
    ASSERT_TRUE(it >= my_const_it);
}

TEST(ConstIterator, Vector) {
    ft::vector<int> my_vector;
    std::vector<int> default_vector;
    for (size_t i = 0; i < 10; i++) {
        my_vector.push_back(i);
        default_vector.push_back(i);
    }
    ft::vector<int>::const_iterator it = my_vector.begin();
    std::vector<int>::const_iterator def_it = default_vector.begin();
    ft::vector<int>::const_iterator ite = my_vector.end();
    std::vector<int>::const_iterator def_ite = default_vector.end();
    ASSERT_EQ(*it, *def_it);
    ++it; ++def_it;
    ASSERT_EQ(*it, *def_it);
    it++; def_it++;
    ASSERT_EQ(*it, *def_it);
    --it; --def_it;
    ASSERT_EQ(*it, *def_it);

    ite--; def_ite--;
    ASSERT_EQ(*ite, *def_ite);
    ite = ite - 3; def_ite = def_ite - 3;
    ASSERT_EQ(*ite, *def_ite);
    ite = ite + 2; def_ite = def_ite + 2;
    ASSERT_EQ(*ite, *def_ite);
    ite -= 3; def_ite -= 3;
    ASSERT_EQ(*ite, *def_ite);
    ite += 2; def_ite += 2;
    ASSERT_EQ(*ite, *def_ite);
    ASSERT_EQ(ite[0], def_ite[0]);

    ASSERT_TRUE(it == it);
    ASSERT_FALSE(it != it);
    ASSERT_FALSE(it > it);
    ASSERT_FALSE(it < it);
    ASSERT_TRUE(it <= it);
    ASSERT_TRUE(it >= it);

    ft::vector<int>::iterator my_not_const_it = my_vector.begin();
    it = my_vector.begin();

    ASSERT_TRUE(it == my_not_const_it);
    ASSERT_FALSE(it != my_not_const_it);
    ASSERT_FALSE(it > my_not_const_it);
    ASSERT_FALSE(it < my_not_const_it);
    ASSERT_TRUE(it <= my_not_const_it);
    ASSERT_TRUE(it >= my_not_const_it);
}


TEST(ReverseIterator, Vector) {
    ft::vector<int> my_vector;
    std::vector<int> default_vector;
    for (size_t i = 0; i < 10; i++) {
        my_vector.push_back(i);
        default_vector.push_back(i);
    }
    ft::vector<int>::reverse_iterator it = my_vector.rbegin();
    std::vector<int>::reverse_iterator def_it = default_vector.rbegin();
    ft::vector<int>::reverse_iterator ite = my_vector.rend();
    std::vector<int>::reverse_iterator def_ite = default_vector.rend();
    ASSERT_EQ(*it, *def_it);
    ++it; ++def_it;
    ASSERT_EQ(*it, *def_it);
    --it; --def_it;
    ASSERT_EQ(*it, *def_it);

    ite = ite - 3; def_ite = def_ite - 3;
    ASSERT_EQ(*ite, *def_ite);
    ite = ite + 2; def_ite = def_ite + 2;
    ASSERT_EQ(*ite, *def_ite);
    ite -= 3; def_ite -= 3;
    ASSERT_EQ(*ite, *def_ite);
    ite += 2; def_ite += 2;
    ASSERT_EQ(*ite, *def_ite);
    ASSERT_EQ(ite[0], def_ite[0]);

}

TEST(ConstReverseIterator, Vector) {
    ft::vector<int> my_vector;
    std::vector<int> default_vector;
    for (size_t i = 0; i < 10; i++) {
        my_vector.push_back(i);
        default_vector.push_back(i);
    }
    ft::vector<int>::const_reverse_iterator it = my_vector.rbegin();
    std::vector<int>::const_reverse_iterator def_it = default_vector.rbegin();
    ft::vector<int>::const_reverse_iterator ite = my_vector.rend();
    std::vector<int>::const_reverse_iterator def_ite = default_vector.rend();
    ASSERT_EQ(*it, *def_it);
    ++it; ++def_it;
    ASSERT_EQ(*it, *def_it);
    --it; --def_it;
    ASSERT_EQ(*it, *def_it);

    ite = ite - 3; def_ite = def_ite - 3;
    ASSERT_EQ(*ite, *def_ite);
    ite = ite + 2; def_ite = def_ite + 2;
    ASSERT_EQ(*ite, *def_ite);
    ite -= 3; def_ite -= 3;
    ASSERT_EQ(*ite, *def_ite);
    ite += 2; def_ite += 2;
    ASSERT_EQ(*ite, *def_ite);
    ASSERT_EQ(ite[0], def_ite[0]);
}


