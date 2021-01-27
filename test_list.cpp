#include "list.hpp"
#include <iostream>
#include <vector>

// int     main() {
//     ft::list<int> test(4, 7);
//     ft::list<int> test1;
//     ft::list<int>::const_iterator begin = test.begin();
//     ft::list<int>::const_iterator end = --test.end();
//     while (begin != end) {
//         std::cout << *begin << std::endl;
//         std::cout << *end << std::endl;
//         ++begin;
//     }
//     std::cout << test.max_size() << std::endl;
//     return 0;
// }


int main ()
{
  ft::list<int> mylist;

  // set some initial content:
  for (int i=1; i<10; ++i) mylist.push_back(i);

  mylist.resize(5);
  mylist.resize(8,100);
  mylist.resize(12);

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}