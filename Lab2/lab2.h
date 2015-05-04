//Karen Pho
//SID: 861103904
//April 19, 2015

#ifndef _LAB2_H
#define _LAB2_H
#include <iostream>
#include <forward_list>
using namespace std;

template <class T>
class Node
{
    public:
        T data; //data that's stored in Node
        Node<T>* next; //pointer to the next Node
        Node<T>(T data) : data(data), next(0) {}; //constructor
};

//counts how many prime numbers are in the list
int primeCount(forward_list<int> lst);

//checks to see if the element is a prime
bool isPrime(int i);


template <class T>
class List
{
    private:
        Node<T>* head;
        Node<T>* tail;
        
    public:
    
        List<T>()
        {
            head = 0;
            tail = 0;
        }
        
        ~List<T>()
        {
            while(head != 0)
            {
                Node<T>* curr = head;
                head = head->next;
                delete curr;
            }
            
            if(head == 0)
            {
                tail = 0;
            }
            return;
        
        }
        
        void push_back(T value)
        {
            if(tail != 0)
            {
                Node<T>* n = new Node<T>(value);
            
                tail->next = n;
                tail = n;
            }
            else
            {
                Node<T>* n = new Node<T>(value);
                
                tail = n;
                head = n;
            }
        }
        
        //swap two adjacent elements pos and pos+1
        List<T> elementSwap(int pos)
        {
            if(pos == 0)
            {
                Node<T>* curr = head;
                head = curr->next;
                curr->next = head->next;
                head->next = curr;
            }
            else if(pos >= size())
            {
                return *this;
            }
            else if(pos == size() - 1)
            {
                Node<T>* before = head;
                Node<T>* first = head;
                Node<T>* second = head;
                
                for(int i = 1; i < pos - 1; ++i)
                {
                    before = before->next;
                }
                
                for(int j = 1; j < pos; ++j)
                {
                    first = first->next;
                }
                
                for(int k = 1; k < pos + 1; ++k)
                {
                    second = second->next;
                }
                
                before->next = second;
                second->next = first;
                first->next = NULL;
            }
            else
            {
                Node<T>* before = head;
                Node<T>* after = head;
                Node<T>* first = head;
                Node<T>* second = head;
                
                for(int i = 0; i < pos - 1; ++i)
                {
                    before = before->next;
                }
                for(int j = 0; j < pos; ++j)
                {
                    first = first->next;
                }
                for(int k = 0; k < pos + 1; ++k)
                {
                    second = second->next;
                }
                for(int l = 0; l < pos + 2; ++l)
                {
                    after = after->next;
                }
                
                before->next = second;
                first->next = after;
                second->next = first;
                
            }
            
            display();
            
            return *this;
            
        }
        
        int size() const
        {
            int count = 0;
            
            Node<T>* curr;
            
            for(curr = head; curr != 0; curr = curr->next)
            {
                    count++;
            }
            
            return count;
        }
        
        void display() const
        {
            Node<T>* curr;
    
            for(curr = head; curr != 0; curr = curr->next)
            {
                if(curr->next == 0)
                {
                    cout << curr->data;
                }
                else
                {
                    cout << curr->data << " ";
                }
            }
            cout << endl;
        }
};

template<class T>
//copy the list from L to P but in reverse order
void listCopy(forward_list<T> L, forward_list<T>& P)
{
    if(P.empty())
    {
        typename forward_list<T>::iterator it;
        
        for(it = L.begin(); it != L.end(); ++it)
        {
            P.push_front(*it);
        }
    }
    else
    {
        forward_list<T> temp;
        
        typename forward_list<T>::iterator it;
        
        for(it = L.begin(); it != L.end(); ++it)
        {
            temp.push_front(*it);
        }
        
        P.merge(temp);
    }
    
    return;
}

template<class T>
//print the elements in L that are in positions specified by P
//P will have numbers and L can either have chars or numbers 
void printLots(forward_list<T> L, forward_list<int> P)
{
    typename forward_list<T>::iterator it;
    typename forward_list<T>::iterator it2;
    int size = 0;
    
    for(it = L.begin(); it != L.end(); ++it)
    {
        ++size;
    }
    
    for(it2 = P.begin(); it2 != P.end(); ++it2)
    {
        if(*it2 > size)
        {
            return;
        }
        else
        {
            typename forward_list<T>::iterator it3;
            it3 = L.begin();
            for(int i = 0; i < *it2; ++i)
            {
                ++it3;
            }
            cout << *it3 << " ";
        }
    }
    cout << endl; 
    
}

#endif