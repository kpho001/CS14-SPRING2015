//Karen Pho
//SID: 861103904
//May 12, 2015
//Approach:

#ifndef _LAB5_H
#define _LAB5_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>

using namespace std;

#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST {
    class Node { // binary tree node
    public:
        Value value;
        Node* left;
        Node* right;
        bool selected;
        bool visited;
        
        Node( const Value v = Value() )
            : value(v), left(nil), right(nil), selected(false), visited(false)
        {}
        
        Value& content() { return value; }
        
        bool isInternal() { return left != nil && right != nil; }
        
        bool isExternal() { return left != nil || right != nil; }
        
        bool isLeaf() { return left == nil && right == nil; }
        
        int height() {
        // returns the height of the subtree rooted at this node
            if(this == nil)
            {
                return -1;
            }
            else
            {
                int leftHeight = this->left->height();
                int rightHeight = this->right->height();
                
                return max(leftHeight, rightHeight) + 1;
            }
        }
        
        int size() {
        // returns the size of the subtree rooted at this node,
            if(this == nil)
            {
                return 0;
            }
            else
            {
                int szOfLeftSide = this->left->size();
                int szofRightSide = this->right->size();
                
                cout << "Height of subtree: " << this->height() << endl;
                
                return szOfLeftSide + szofRightSide + 1;
            }
        }
    }; // Node
    
    // const Node* nil; // later nil will point to a sentinel node.
    //Node* root;
    //int count;
    // vector<Value> nodeVal;
    
    public:
        Node* root;
        vector<Value> nodeVal;
        
        BST() : root(nil) {}
        
        int size() {
        // size of the overall tree.
            if(root == nil)
            {
                return 0;
            }
            else
            {
                int sz_left = root->left->size();
                int sz_right = root->right->size();
                
                cout << "Height of the root: " << root->height() << endl;
                cout << "Value of root: ";
                print_node(root);
                return sz_left + sz_right + 1;
            }
            
        }
        
        bool empty() { return size() == 0; }
        
        void print_node( const Node* n ) {
        // Print the node’s value.
            cout << n->value << endl;
        }
    
        bool search ( Value x ) {
        // search for a Value in the BST and return true iff it was found.
            Node* curr = root;
            
            if(curr == nil)
            {
                return false;
            }
            
            if(curr->value == x)
            {
                return true;
            }
            
            if(curr != nil)
            {
                while(curr != nil)
                {
                    if(curr->value == x)
                    {
                        return true;
                    }
                    else if(curr->value < x)
                    {
                        curr = curr->right;
                    }
                    else if(curr->value > x)
                    {
                        curr = curr->left;
                    }
                }
            }
            
            return false;
        }
        
        void preorder()const {
        // Traverse and print the tree one Value per line in preorder.
            preorder(root);
        }
        
        void preorder(Node* curr) const
        {   //helper function
            if(curr == nil)
            {
                return;
            }
            else
            {
                cout << curr->value << endl;
                postorder(curr->left);
                postorder(curr->right);
            }
        }
        
        void postorder()const {
        // Traverse and print the tree one Value per line in postorder.
            postorder(root);
        }
        
        void postorder(Node* curr) const
        {   //helper function
            if(curr == nil)
            {
                return;
            }
            else
            {
                postorder(curr->left);
                postorder(curr->right);
                cout << curr->value << endl;
            }
        }
        
        void inorder()const {
        // Traverse and print the tree one Value per line in inorder.
            inorder(root);
        }
        
        void inorder(Node* curr) const
        {   //helper function
            if(curr == nil)
            {
                return;
            }
            else
            {
                inorder(curr->left);
                cout << curr->value << endl;
                inorder(curr->right);
            }
        }
        
        Value& operator[] (int n) {
        // returns reference to the value field of the n-th Node.
            helpFunction(root);
            return nodeVal.at(n);
        }
        
        void helpFunction(Node* curr)
        {
            if(curr == nil)
            {
                return;
            }
            else
            {
                helpFunction(curr->left);
                nodeVal.push_back(curr->value);
                helpFunction(curr->right);
            }
            
        }
        
        
        void insert( Value X ) { root = insert( X, root ); }
        
        Node* insert( Value X, Node* T ) {
            // The normal binary-tree insertion procedure ...
            if ( T == nil ) {
                T = new Node( X ); // the only place that T gets updated.
            } else if ( X < T->value ) {
                T->left = insert( X, T->left );
            } else if ( X > T->value ) {
                T->right = insert( X, T->right );
            } else {
                T->value = X;
            }
            // later, rebalancing code will be installed here
    
            return T;
        }
        
        void remove( Value X ) { root = remove( X, root ); }
        
        Node* remove( Value X, Node*& T ) {
        // The normal binary-tree removal procedure ...
        // Weiss’s code is faster but way more intricate.
            if ( T != nil ) {
                if ( X > T->value ) {
                    T->right = remove( X, T->right );
                } else if ( X < T->value ) {
                    T->left = remove( X, T->left );
                } else { // X == T->value
                    if ( T->right != nil ) {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    } else if ( T->left != nil ) {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } else { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
        
            // later, rebalancing code will be installed here
        
            return T;
        }
        
        void okay( ) { okay( root ); }
        
        void okay( Node* T ) {
            // diagnostic code can be installed here
            return;
        }
        
        //---------------------------For Lab 5--------------------------------//
        void minCover()
        {
            if(root == nil)
            {
                cout << "Empty tree" << endl;
                exit(1);
            }
            else
            {
                DFS(root->left);
                DFS(root->right);
                //cout << "hi" << endl;
            }
        }
        
        void DFS(Node* x)
        {
            
            //cout << "1" << endl;
            x->visited = true;
            Node* y = x;
            
            if((y= x->left) != nil)
            {
                //cout << "2" << endl;
                if(y->visited != true)
                {
                    //cout << "3" << endl;
                    DFS(y);
                    
                    if(y->selected != true)
                    {
                        //cout << "4" << endl;
                        x->selected = true;
                    }
                }
            }
            
            if((y = x->right) != nil)
            {
                //cout << "5" << endl;
                if(y->visited == false)
                {
                    //cout << "6" << endl;
                    
                    DFS(y);
                    
                    if(y->selected != true)
                    {
                        //cout << "7" << endl;
                        x->selected = true;
                    }
                }
            }
        }
        
        void displayMinCover()
        {
            cout << "Part 1" << endl;
            // displayMinCover(root);
            int countt = displayMinCover(root);
            cout << endl;
            cout << countt << endl;
        }
        
        int displayMinCover(Node* curr)
        {
            int count = 0;
            
            //cout << "hello" << endl;
            if(curr == nil)
            {
                return 0;
            }
            else
            {
                //displayMinCover(curr->left);
                if(curr->selected == true)
                {
                    ++count;
                    cout << curr->value << " ";
                }
                //displayMinCover(curr->right);
            }
            
            return count + displayMinCover(curr->left) + displayMinCover(curr->right);
        }
        
        
        void findSumPath(Node* n, int sum, int buffer[])
        {
            if(n == nil)
            {
                return;
            }
            
            n->visited = true;
            Node* y = n;
            
            int currSum = sum - n->value;
            
            if(currSum == 0 && n->left == nil && n->right == nil)
            {
                n->selected = true;
                return;
            }
            
            else if(currSum != 0 && n->left == nil && n->right == nil)
            {
                n->selected = false;
                return;
            }
            
            else if((y = n->left) != nil)
            {
                if(y->visited == false)
                {
                    findSumPath(y, currSum, buffer);
                }
            }
            
            else if((y = n->right) != nil)
            {
                if(y->visited == false)
                {
                    findSumPath(y, currSum, buffer);
                }
            }
            
        }

        void displayPath(Node* x)
        {
            if(x == nil)
            {
                cout << "hello" << endl;
                return;
            }
            else
            {
                displayPath(x->left);
                if(x->selected == true)
                {
                    cout << x->value << " ";
                }
                displayPath(x->right);
            }
        }
        
        void vertSum(Node* node, int hd, map<int, int>& m)
        {
            while(node != nil)
            {
                node->left 
            }
        }
        
        
        
        
}; // BST
#endif