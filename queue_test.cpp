#include "gtest/gtest.h"
#include "queue.hpp"
#include <queue>

TEST(Constructor, Queue) {
    std::queue<int> def_queue;
    ft::queue<int> my_queue;

    ASSERT_EQ(def_queue.empty(), my_queue.empty());
    ASSERT_EQ(def_queue.size(), my_queue.size());
}

TEST(FrontBack, Queue) {
    std::queue<int> def_queue;
    std::queue<int> my_queue;

    def_queue.push(10);
    my_queue.push(10);
    def_queue.push(20);
    my_queue.push(20);

    ASSERT_EQ(def_queue.front(), my_queue.front());
    ASSERT_EQ(def_queue.back(), my_queue.back());
}

TEST(Pop, Queue) {
    std::queue<int> def_queue;
    std::queue<int> my_queue;

    for (int i=0; i<5; ++i) {
        def_queue.push(i);
        my_queue.push(i);
    }

    while (!def_queue.empty()) {
        ASSERT_EQ(def_queue.front(), my_queue.front());
        def_queue.pop();
        my_queue.pop();
    }
}

TEST(RelationalOperators, Queue) {
    std::queue<int> default_queue;
    ft::queue<int> my_queue;
    std::queue<int> default_queue2;
    ft::queue<int> my_queue2;
    default_queue2.push(5);
    my_queue2.push(5);

    ASSERT_EQ((default_queue==default_queue2), (my_queue==my_queue2));
    ASSERT_EQ((default_queue!=default_queue2), (my_queue!=my_queue2));
    ASSERT_EQ((default_queue>=default_queue2), (my_queue>=my_queue2));
    ASSERT_EQ((default_queue<=default_queue2), (my_queue<=my_queue2));
    ASSERT_EQ((default_queue>default_queue2), (my_queue>my_queue2));
    ASSERT_EQ((default_queue<default_queue2), (my_queue<my_queue2));
}