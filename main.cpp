
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include "includes/map.hpp"
#include "includes/queue.hpp"
#include "includes/stack.hpp"

int main() {
    ft::map<int, int> my_map;
    std::map<int, int> def_map;

    for (size_t i = 0; i < 100; i++) {
        my_map.insert(std::make_pair(i, i));
        def_map.insert(std::make_pair(i, i));
    }
    return 0;
}
