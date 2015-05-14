// Karen Pho
// SID: 861103904
// Date: May 13, 2015

#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

template<typename L>
void selectionsort(L &l){
    typename L::iterator it = l.begin();
    typename L::iterator it1 = l.begin();
    
    for(; it != l.end(); ++it)
    {
        
        for(it1 = it; it1 != l.end(); ++it1)
        {
            if(*it > *it1){
                swap(*it, *it1);
            }
        }
    }
}


#endif