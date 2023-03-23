/*
Created by Biruk Geletu on 03/09/2023
University of Washington Bothell 

This is the funds class. This contains 10 funds and is in the array
 This is mostly for the fifth number if the id contains the fifth id.
 Each time the fund is done an action, it is enqueued into the action
 history.
*/
#ifndef FUNDS_H
#define FUNDS_H
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class Funds
{
public:
   // constractor initializes the private members of data 
    Funds(); 
    Funds(string& fund);
    ~Funds();
    
    //This will enqueue the string of actions to the vector of actions.
    void history(string &history);
    
    //This will print out the vector. 
    void print() const;
  
    //This will deposit the money in the fund. Since the fund
    //has the total money, this will update the total money.
    int deposit(int &mon);

    //This will withdraw the money in the fund. Since the fund
    //has the total money, this will update the total money.
    
    int withdraw(int &mon);
    //This will withdraw the money in the fund by withdrawing the
    //original fund account. Since the fund has the total money, 
    //this will update the total money.
     
    bool transferWithdraw(int amount, Funds *&transfer1);
    
   
    //This will deposit the money in the fund by withdrawing the
    //original fund account. Since the fund has the total money, 
    //this will update the total money.
    bool transferDeposit(int amount, Funds *&transfer2);
    
    // setter and getter methods 
    int getBalance() const;
    void setBalance(int mon);
    string getFundType() const;
    void setFundType(string fundN);
private:
    // total ammount of money 
    int balance;
    // fund type 
    string fundType; 
    // list of action 
    vector<string> action; 

};

#endif