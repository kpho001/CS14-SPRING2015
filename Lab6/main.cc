// Karen Pho
// SID: 861103904
// Date: May 13, 2015

#include "selectionsort.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <deque>


using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(9);
    vec.push_back(5);
    
    selectionsort(vec);
    
    cout << "testing vector:" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec.at(i) << " ";
    }
    
    cout << endl;
    
    vector< pair<int, int> > v;
    v.push_back(pair<int, int> (1, 1));
    v.push_back(pair<int, int> (9, 1));
    v.push_back(pair<int, int> (1, -1));
    v.push_back(pair<int, int> (3, 1));
    v.push_back(pair<int, int> (-1, 1));
    v.push_back(pair<int, int> (1, 1));
    v.push_back(pair<int, int> (0, 0));
    
    selectionsort(v);
    
    cout << "testing pair:" << endl;
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v.at(i).first << "," << v.at(i).second << " ";
    }
    
    cout << endl;
    
    vector< pair<int, int> > v1;
    v1.push_back(pair<int, int> (-1, 1));
    v1.push_back(pair<int, int> (1, 1));
    v1.push_back(pair<int, int> (9, 1));
    v1.push_back(pair<int, int> (0, 0));
    v1.push_back(pair<int, int> (1, 1));
    v1.push_back(pair<int, int> (3, 1));
    v1.push_back(pair<int, int> (1, -1));
    
    selectionsort(v1);
    
    cout << "testing pair:" << endl;
    for(int i = 0; i < v1.size(); ++i)
    {
        cout << v1.at(i).first << "," << v1.at(i).second << " ";
    }
    
    cout << endl;
    
    return 0;
}
