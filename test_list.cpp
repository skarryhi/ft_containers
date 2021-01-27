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

int main ()
{
  ft::list<std::string> mylist;
  ft::list<std::string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");

  mylist.sort();

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}