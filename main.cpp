
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include "includes/map.hpp"
#include "includes/queue.hpp"
#include "includes/stack.hpp"

int main() {
    ft::map<const int, int> my_map;
    std::map<const int, int> def_map;

    for (int i = 1; i < 10; i++) {
        my_map.insert(std::make_pair(i, i));
//        def_map.insert(std::make_pair(i, i));
    }
    return 0;
}
