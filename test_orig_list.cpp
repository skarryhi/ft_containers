#include <list>
#include <iostream>
#include <string>

int     main() {
    std::list<int> test(4, 7);
    std::list<int>::const_iterator begin = test.begin();
    std::list<int>::const_iterator end = --test.end();
    while (begin != end) {
        std::cout << *begin << std::endl;
        std::cout << *end << std::endl;
        ++begin;
    }
    std::cout << test.max_size() << std::endl;
    std::cout << std::numeric_limits<char>::max() << std::endl;
    std::cout << (size_t)(-1) / sizeof(char) / 2 << std::endl;
    std::cout << *test.begin() << std::endl;
    std::cout << test.front() << std::endl;
    return 0;
}