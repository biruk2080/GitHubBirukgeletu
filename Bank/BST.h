/*
Created by Biruk Geletu on 03/09/2023
University of Washington Bothell 

In this class, after reading in the txt file, whenever there is an 'O', 
then it will be inserted into the binary tree. Each node in the binary 
search tree represents an object of Account 
*/
#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <string>
#include <iostream>
#include "account.h"
using namespace std;

class BST
{  
    private:
    // this Node struct has account data, left and right node pointer 
    struct Node
    {
        Account *pAccount;
        Node *right;
        Node *left;
    };
    //Method new node be made.
    struct Node* newNode(Account *item)
    {
        Node *temp = new Node;
        temp->pAccount = item;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    };
    // root node point to the root of BST 
    Node* root;
    // private method that delete BST recursivily 
    void emptyHelper(Node* node); 
    
    // This is the helper for insert the method that add A new node and return true or false.
    bool insertHelper(Node* root, Account *item);
   
   // This is the helper for the retrieve that make sure that if an item is inside of the tree.
   bool retrieveHelper(Node *root, const int& id, Account*& item) const;
public:
  
    // Constructor. All it does is set the root to null.
    BST();
    
    // Destructor. This destroys everything in the binary search tree.
     ~BST();
     
     //This is the insert. If an account is opened, then it is added to the tree.
     bool Insert(Account *acc);
    
    //retrieve object, first parameter is the ID of the account
    //second parameter holds pointer to found object, NULL if not found.
    bool Retrieve(const int &id, Account* &item) const;

    // This displays the contents of the tree.
     void DisplayTheTree() const;
    
    //call the edelete  the all node in the tree .
    void Empty();    
    
    //This checks if the tree is empty or not 
    bool isEmpty() const;
    
    //This will also display the contents of the tree.
    void print(Node *root) const;
};
#endif