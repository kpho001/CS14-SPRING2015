//Karen Pho
//SID: 861103904
//April 27, 2015
//This file contains all the functions with templates

#ifndef _LAB_3_H
#define _LAB_3_H
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

template <class T>
class TwoStackFixed
{
    private:
        T arr[80] = {};
        int arr_size = 0;
        int numstack1 = 0;
        int numstack2 = 0;
        int top_of_stack = 0;
        int szStack2 = 0;
        stack <T> stack1;
        stack <T> stack2;
    
    public:
        //constructor that constructs array of ‘size’ length and constructs empty
        //stacks with maxtop specifying the partition of array for stacks.
        TwoStackFixed(int size, int maxtop)
        {
            arr_size = size;
            top_of_stack = maxtop;
            // for(int i = 0; i < size; ++i)
            // {
            //     arr[i] = 0;
            // }
            
            //display();
        }
        
        //to push element into first stack. Display the contents of stack after
        //each push
        void pushStack1(T value)
        {
            if(isEmptyStack1())
            {
                stack1.push(value);
                arr[0] = stack1.top();
                ++numstack1;
            }
            else if(isFullStack1())
            {
                cout << "Sorry but Stack 1 is full. " << endl;
                return;
            }
            else
            {
                stack1.push(value);
                arr[numstack1] = stack1.top();
                ++numstack1;
            }

            display();
        }
        
        //to push element into second stack. Display the contents of stack after 
        //each push
        void pushStack2(T value)
        {
            szStack2 = arr_size - top_of_stack;
            
            if(isEmptyStack2())
            {
                stack2.push(value);
                arr[arr_size - 1] = stack2.top();
                ++numstack2;
            }
            else if(isFullStack2())
            {
                cout << "Sorry but Stack 2 is full. " << endl;
                return;
            }
            else
            {
                stack2.push(value);
                arr[arr_size - (numstack2 + 1)] = stack2.top();
                ++numstack2;
            }
            
            display();
            
        }
        
        //to pop element from first stack. Return the popped element and print
        T popStack1()
        {
            T popped = stack1.top();
            stack1.pop();
            for(int i = 0; i < top_of_stack; ++i)
            {
                if(arr[i] == popped)
                {
                    arr[i] = 0;
                    --numstack1;
                    display();
                    return popped;
                }
            }
            
            return popped;
        }
        
        //to pop element from second stack. Return the popped element and print
        T popStack2()
        {
            T popped = stack2.top();
            stack2.pop();
            for(int i = arr_size - 1; i >= top_of_stack; --i)
            {
                if(arr[i] == popped)
                {
                    arr[i] = 0;
                    --numstack2;
                    display();
                    return popped;
                }
            }
            return popped;
        }
        
        //helper function to check whether first stack is full
        bool isFullStack1()
        {
            if(numstack1 == top_of_stack)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        //helper function to check whether second stack is full
        bool isFullStack2()
        {
            if(numstack2 == szStack2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        //helper function to check whether first stack is empty
        bool isEmptyStack1()
        {
            if(stack1.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        //helper function to check whether second stack is empty
        bool isEmptyStack2()
        {
            if(stack2.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        //to display contents of array
        void display()
        {
            for(int j = 0; j < arr_size; ++j)
            {
                if(arr[j] != 0)
                {
                    cout << arr[j] << " ";
                }
                else if(arr[j] == 0)
                {
                    //cout << "  ";
                }
            }
            cout << endl;
        }
        
};


template <class T>
class TwoStackOptimal
{
    private:
        T arr[80] = {};
        int arr_size = 0;
        int numstack1 = 0;
        int numstack2 = 0;
        stack <T> stack1;
        stack <T> stack2;
        
    public:
        //constructor that constructs array of size and constructs empty stacks
        TwoStackOptimal(int size)
        {
            arr_size = size;
            //display();
        }
        
        //to push element into first stack. Display the contents of stack after each push
        void pushFlexStack1(T value)
        {
            if(isEmptyStack1())
            {
                stack1.push(value);
                arr[0] = stack1.top();
                ++numstack1;
            }
            else if(isFullStack1())
            {
                cout << "Sorry but Stack 1 is full. " << endl;
                return;
            }
            else
            {
                stack1.push(value);
                arr[numstack1] = stack1.top();
                ++numstack1;
            }

            display();
            
        }
        
        //to push element into second stack. Display the contents of stack afte each push
        void pushFlexStack2(T value)
        {
            if(isEmptyStack2())
            {
                stack2.push(value);
                arr[arr_size - 1] = stack2.top();
                ++numstack2;
            }
            else if(isFullStack2())
            {
                cout << "Sorry but Stack 2 is full. " << endl;
                return;
            }
            else
            {
                stack2.push(value);
                arr[arr_size - (numstack2 + 1)] = stack2.top();
                ++numstack2;
            }
            
            display();
        }
        
        //to pop element into first stack. Return the popped element and print
        T popFlexStack1()
        {
            T popped = stack1.top();
            stack1.pop();
            for(int i = numstack1 - 1; i >= 0; --i)
            {
                if(arr[i] == popped)
                {
                    arr[i] = 0;
                    --numstack1;
                    display();
                    return popped;
                }
            }
            return popped;
        }
        
        //to pop element from second stack. Return the popped element and print
        T popFlexStack2()
        {
            T popped = stack2.top();
            stack2.pop();
            for(int i = numstack1; i < arr_size - 1; ++i)
            {
                if(arr[i] == popped)
                {
                    arr[i] = 0;
                    --numstack2;
                    display();
                    return popped;
                }
            }
            return popped;
        }
        
        //helper function to check whether first stack is full
        bool isFullStack1()
        {
            int total = numstack1 + numstack2;
            if(total == arr_size)
            {
                return true;
            }
            else{
                return false;
            }
        }
        
        //helper function to check whether second stack is full
        bool isFullStack2()
        {
            int total = numstack1 + numstack2;
            if(total == arr_size)
            {
                return true;
            }
            else{
                return false;
            }
        }
        
        //helper function to check whether first stack is empty
        bool isEmptyStack1()
        {
            if(stack1.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        //helper function to check whether second stack is empty
        bool isEmptyStack2()
        {
            if(stack2.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        //to display contents of array
        void display()
        {
            for(int j = 0; j < arr_size; ++j)
            {
                if(arr[j] != 0)
                {
                    cout << arr[j] << " ";
                }
                else if(arr[j] == 0)
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    
};

template <class T>
class TowerOfHanoi
{
    public:
        void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
        {
            if (n == 1)
            {
                cout << "Moved " << A.top() << " from peg A to C" << endl;
                C.push(A.top());
                A.pop();
            }
            else
            {
                showTowerStates(n - 1, A, C, B);
                cout << "Moved " << A.top() << " from peg A to B" << endl;
                B.push(A.top());
                A.pop();
                showTowerStates(n - 1, C, B, A);
            }
        }
};

#endif