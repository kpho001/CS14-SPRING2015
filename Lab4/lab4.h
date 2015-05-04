//Karen Pho
//SID: 861103904
//May 4, 2015
//Approach: I created 2 more functions in the priority_queue class to help push 
//the pairs into the vector. Then I created a display function to output the vector.
//To keep the tree from extending longer and longer, I've made 'm' and 'n' boundaries
//to make it match the example in the specifications.

#ifndef _LAB4_H
#define _LAB4_H

#include <iostream>
#include <vector>
#include <algorithm>
//#include <queue>
using namespace std;

typedef pair<int,int> Entry;
class priority_queue {
    public:
        vector<Entry> entries;
        
        Entry& front() { return entries.back(); }
        
        void pop() { entries.pop_back(); }
        
        void push( Entry e ) {
            entries.push_back( e );
            
            for (int i = entries.size() - 1; i != 0; --i) {
                
                if ( entries[i].first + entries[i].second >= entries[i-1].first +
                    entries[i-1].second) break; //replace this comparison 
                // with code for comparing int pairs.
                
                swap(entries[i], entries[i-1]);
            }   
        }
        
        void display(int argVal)
        {
            for(unsigned i = 0; i < entries.size(); ++i)
            {
                if(entries[i].first + entries[i].second < argVal)
                {
                    cout << entries[i].first << ", " << entries[i].second << endl;
                }
            }
        }
        
        void helpPush(int m, int n, int argVal)
        {
            // if statement provides a stopping point to match example
            if(m > 14 || n > 5)
            {
                return;
            }
            
            Entry toPush(m, n);
            push(toPush);
            
            helpPush(2*m - n, m, argVal);
            helpPush(2*m + n, m, argVal);
            helpPush(m + 2*n, n, argVal);
        }
        
};

void preOrder(int m, int n, int argVal)
{
    // if statement provides a stopping point to match example
    if(m > 14 || n > 5)
    {
        return;
    }
    if(m + n < argVal)
    {
        cout << m << ", " << n << endl;
    }
    preOrder(2*m - n, m, argVal);
    preOrder(2*m + n, m, argVal);
    preOrder(m + 2*n, n, argVal);
}

void postOrder(int m, int n, int argVal)
{
    // if statement provides a stopping point to match example
    if(m > 14 || n > 5)
    {
        return;
    }
    postOrder(2*m - n, m, argVal);
    postOrder(2*m + n, m, argVal);
    postOrder(m + 2*n, n, argVal);
    if(m+n < argVal)
    {
        cout << m << ", " << n << endl;
    }
}


#endif