//Karen Pho
//SID: 861103904
//April 19, 2015

#include "lab2.h"
#include <iostream>
#include <forward_list>
using namespace std;

int primeCount(forward_list<int> lst)
{
    int count = 0;
    
    if(lst.empty()){
        
        return 0;
    }
    else{
        
        if(isPrime(lst.front())){
        
            ++count;
        }
    
        lst.pop_front();
    }

    return count + primeCount(lst);
}

bool isPrime(int i)
{
    for(int k = 2; k < i; ++k){
        if(i % k == 0){
            return false;
        }
    }
    
    return true;
}
