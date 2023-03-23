#include  "account.h"
#include "BST.h"
#include <assert.h>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std; 
BST::BST()
{
    // set the root to nullpter 
    root = nullptr; 
}

BST::~BST()
{
    //Call empty because empty is the same thing as a destructor.
    emptyHelper(root);
}
bool BST::isEmpty() const
{
    //If the root is null, then return true, False otherwise.
    if (root == nullptr)
    {
        return true; 
    }
   return false; 
}
bool BST::Insert(Account *acc)
{
    // if the insertion is sucessful, it return true otherwise it return false 
    if (insertHelper(root, acc))
    {
        return true;
    }else {
        return false; 
    }
}
bool BST::insertHelper(Node *root, Account *acc)
{
    // check the root node and add if it is null
    if (root == nullptr)
    {
        root = newNode(acc);
        return true; 
    } else if (root->pAccount->getID() == acc->getID())
    {
        //Convert the id into a string.
        stringstream ss;
        string str;
        int mychar = acc->getID();
        ss << mychar;
        ss >> str;
        cout << "ERROR: This account " + str + " is already open. Transaction refused" << endl; 
        return false; 
    } else if (root->pAccount->getID() < acc->getID())
    {
       //recursive call to the right until it get the right spot to insert the node
       insertHelper(root->right, acc);
       
    } else
    {
        //recursive call to the left until it get the right spot to insert the node
        insertHelper(root->left, acc);
    }
    return false; 
}
bool BST::Retrieve(const int &id, Account* &item) const
{
    //Uses the helper method to retrieve.
    if (retrieveHelper(root, id, item))
    {
        return true;
    }
    else
    {
        //If not set the item to nullptr. 
        item = nullptr;
        return false;
    }
}
bool BST::retrieveHelper(Node *root, const int& id, Account*& item) const
{
    // check the root is not nullptr
    while (root!=nullptr)
    {
        // compare the id and go left or right 
        if (root->pAccount->getID() > id)
        {
            root = root->left;
        }else if (root->pAccount->getID() < id)
        {
            root = root->right;
        }
        else 
        {
            // assign the account to the item  and return true  
            item = root->pAccount;
            return true; 
        }
        
    }
    return false;   
}
void BST::print(Node *root) const
{
    //If the root is null, don't do anything.
    if(root == nullptr)
    {
        return;
    }
    //If the root is pointing to something,
    
        //Do a preorder
        root->pAccount->finalHistory();
        cout << endl;
        
        //Recurse Left
        print(root->left);
        //Recurse Right
        print(root->right);
}
void BST::DisplayTheTree() const
{
    print(root);
}
void BST::Empty()
{
    emptyHelper(root);  
}
void BST::emptyHelper(Node* node)
{
    // check the node is not nullptr
    if (node != nullptr)
    {
        // check the left node is not nullptr and call recursive to the left
        if (node->left != nullptr)
        {
            emptyHelper(node->left);
        }
        // check the right node is not nullptr and call recursive to the right
        if (node->right != nullptr)
        {
            emptyHelper(node->right);
        }
        // delete the node and assign to nullptr 
        delete node;
        node = nullptr;  
    }
}