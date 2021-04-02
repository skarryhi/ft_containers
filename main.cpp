
#include <list>
#include <vector>
//#include <map>
#include <queue>
#include <stack>
#include "includes/map.hpp"
#include "includes/queue.hpp"
#include "includes/stack.hpp"

int main() {
    {
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator it;

        // insert some values:
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        mymap['d']=40;
        mymap['e']=50;
        mymap['f']=60;

        it=mymap.find('b');
        mymap.erase (it);                   // erasing by iterator

        mymap.erase ('c');                  // erasing by key

        it=mymap.find ('e');
        mymap.erase ( it, mymap.end() );    // erasing by range

        // show content:
        for (it=mymap.begin(); it!=mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
    }
    while(1) {}
    return 0;
}
