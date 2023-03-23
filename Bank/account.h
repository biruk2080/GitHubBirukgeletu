/*
Created by Biruk Geletu on 03/09/2023
University of Washington Bothell 

This is the account class. Each account has their own of 10 funds.
Each fund is initialized to 0 and this class does the transaction.
*/
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <stdio.h>
#include <iostream>
#include "funds.h"
using namespace std;
class Account
{
private:
    Funds fundsA[10];
    string firstName;
    string lastName;
    int ID;
    string funds[10] = {"Money Market", "Prime Money Market",
        "Long-Term Bond", "Short-Term Bond", "500 Index Fund",
        "Capital Value Fund", "Growth Equity Fund",
        "Growth Index Fund", "Value Fund","Value Stock Fund"};
    
public:
   
    //This will initialize every private variable to a default value
    Account();
    
    //This is the destructor will destroy the contents of funds.
    ~Account();
    
    //getters and setters.
    string getFullName();
    int getID();
    void setID(int &id);
    
    //This constructor that will set the private variables to the
    //values that are passed in.
    Account(string first, string last, int id);
    
    //This is the used to help the transfer case in the bank.cpp.
    //This will withdraw the amount that needs to be transferred.
   void transferWithdraw(int fifth, Account *&item,int amount, string action);
    
    //This is also used as to help the transfer case in the bank.cpp
    //This will deposit the transferring amount.
    void transferDeposit(int fifth, Account *&item, int amount, string action);
    
    /*
     A switch case of significant size is required to check whether the fifth element 
     of an id corresponds with the funds. The fifth element of the id represents the fund, 
     so a switch case is necessary. The action is represented by a character and our focus 
     is primarily on deposit and withdrawal transactions in the account. To keep track of 
     the fund's history, the action is pushed into a vector.
     */
    void transaction(int &fifth, int& amount, char &arr, string &action);
    
    //Displays the contents of just this account and the funds.
    void displayHistory() const;
    
    //Displays the final history of the entire bank
    void finalHistory() const;
    
    //Displays the contents of an individual fund of this account.
    void displayHistory(int fifth) const;
    
    //Getter just in case if we need to get the fund of the fifth element.
    int getFund(int &index) const;
    
    //Setter that will set the amount of money in a certain account.
    void setFund(int &fifth, int &amount);

    //This is mostly needed for the bank.cpp to just what the fund name is. 
    string getIndividualFund(int fifth);
};

#endif