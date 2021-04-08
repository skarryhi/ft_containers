#include "gtest/gtest.h"
#include "../includes/stack.hpp"
#include <stack>

TEST(Constructor, Stack) {
    std::stack<int> def_stack;
    ft::stack<int> my_stack;

    ASSERT_EQ(def_stack.empty(), my_stack.empty());
    ASSERT_EQ(def_stack.size(), my_stack.size());
}

TEST(Top, Stack) {
    std::stack<int> def_stack;
    std::stack<int> my_stack;

    def_stack.push(10);
    my_stack.push(10);
    def_stack.push(20);
    my_stack.push(20);

    ASSERT_EQ(def_stack.top(), my_stack.top());
}

TEST(Pop, Stack) {
    std::stack<int> def_stack;
    std::stack<int> my_stack;

    for (int i=0; i<5; ++i) {
        def_stack.push(i);
        my_stack.push(i);
    }

    while (!def_stack.empty()) {
        ASSERT_EQ(def_stack.top(), my_stack.top());
        def_stack.pop();
        my_stack.pop();
    }
}

TEST(RelationalOperators, Stack) {
    std::stack<int> default_stack;
    ft::stack<int> my_stack;
    std::stack<int> default_stack2;
    ft::stack<int> my_stack2;
    default_stack2.push(5);
    my_stack2.push(5);

    ASSERT_EQ((default_stack==default_stack2), (my_stack==my_stack2));
    ASSERT_EQ((default_stack!=default_stack2), (my_stack!=my_stack2));
    ASSERT_EQ((default_stack>=default_stack2), (my_stack>=my_stack2));
    ASSERT_EQ((default_stack<=default_stack2), (my_stack<=my_stack2));
    ASSERT_EQ((default_stack>default_stack2), (my_stack>my_stack2));
    ASSERT_EQ((default_stack<default_stack2), (my_stack<my_stack2));
//     while(1) {}
}