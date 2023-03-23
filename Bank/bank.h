/*
Created by Biruk Geletu on 03/09/2023
University of Washington Bothell 

This is the main bank class. This will read the txt file and
store each line into a stl queue and judging by the lines
actions, it will execute a transaction.
*/
#ifndef BANK_H
#define BANK_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include "account.h"
#include "BST.h"
class Bank
{
public:
    // it's a constracter that read the file and store in queue as string 
    Bank(string fileName);
    
    ~Bank();
    
    // this method pop up the storing data from the queuse and excute the transaction accordingly  
    void transact();
    // this method display the all account store in the tree 
    void display() const;
private:
// store the transaction 
queue<string> transaction;
// pointer to account object 
Account* acc; 
// referance to BST object 
BST bst;
};
#endif