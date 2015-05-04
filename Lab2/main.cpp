#include "lab2.h"
#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    // forward_list<int> a;
    
    // a.push_front(2);
    // a.push_front(7);
    // a.push_front(19);
    // a.push_front(22);
    // a.push_front(21);
    
    // cout << primeCount(a) << endl;
    
    
    // List<int> b;
    
    // b.push_back(2);
    // b.push_back(7);
    // b.push_back(19);
    // b.push_back(22);
    // b.push_back(21);
    // b.push_back(68);
    
    // b.display();
    // b.elementSwap(5);
    //b.display();
    
    forward_list<int> c;
    forward_list<int> d;
    
    c.push_front(2);
    c.push_front(7);
    c.push_front(19);
    c.push_front(22);
    c.push_front(21);
    
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    
    printLots(c, d);

    
    return 0;
}