//Karen Pho
//SID: 861103904
//April 27, 2015
//This file contains the test cases for the lab

#include <iostream>
#include <stack>
#include "lab3.h"
using namespace std;

int main()
{
    // TwoStackFixed<int> a(11, 5);
    // a.pushStack1(1);
    // a.pushStack1(2);
    // a.pushStack1(3);
    // //a.pushStack1(4);
    
    // a.pushStack2(8);
    // a.pushStack2(7);
    // a.pushStack2(6);
    // a.pushStack2(5);
    // a.pushStack1(44);
    // a.pushStack2(4);
    // //a.pushStack2(9);
    
    // a.popStack1();
    // a.popStack1();
    // a.popStack2();
    // a.pushStack1(4);
    // a.pushStack1(4);
    // a.pushStack1(4);
    // a.pushStack1(4);
    // a.pushStack2(9);
    // a.pushStack2(9);
    // a.pushStack2(9);
    // a.pushStack2(9);
    // a.pushStack2(9);
    
    // TwoStackOptimal<int> b(11);
    // b.pushFlexStack1(1);
    // b.pushFlexStack2(11);
    // b.pushFlexStack1(1);
    // b.pushFlexStack1(1);
    // b.pushFlexStack1(1);
    // b.pushFlexStack1(1);
    // b.pushFlexStack1(1);
    // b.pushFlexStack1(1);
    // b.pushFlexStack1(1);
    // b.pushFlexStack1(1);
    // b.pushFlexStack1(1);
    // b.pushFlexStack2(10);
    // b.popFlexStack1();
    // b.pushFlexStack2(10);
    
    TowerOfHanoi<int> m;
    stack<int> a;
    stack<int> b;
    stack<int> c;
    
    int discs = 15;
    
    m.showTowerStates(discs, a, b, c);
    
    return 0;
}