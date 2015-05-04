//Karen Pho
//SID: 861103904
//May 4, 2015
//Approach: I created 2 more functions in the priority_queue class to help push 
//the pairs into the vector. Then I created a display function to output the vector.
//To keep the tree from extending longer and longer, I've made 'm' and 'n' boundaries
//to make it match the example in the specifications.

#include "lab4.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
//#include <vector>
//#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc > 2)
    {
        cout << "Too many arguments." << endl;
        exit(-1);
    }
    
    if(argc < 2)
    {
        cout << "Too few arguments." << endl;
        exit(-1);
    }
    
    istringstream iss(argv[1]);
    int num;
    
    iss >> num;
    //cout << num << endl;
    
    cout << "preorder: " << endl;
    preOrder(2, 1, num);
    preOrder(3, 1, num);
    
    cout << "postorder: " << endl;
    postOrder(2, 1, num);
    postOrder(3, 1, num);
    
    cout << "ascending order: " << endl;
    priority_queue a;
    a.helpPush(2, 1, num);
    a.helpPush(3, 1, num);
    a.display(num);
    
    
    return 0;
}