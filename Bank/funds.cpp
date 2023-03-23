#include "funds.h"
#include <iostream>
using namespace std;
Funds::Funds()
{
    fundType = "";
    balance = 0; 
}
Funds::Funds(string& fund)
{
    fundType = fund; 
}

Funds::~Funds(){}
int Funds::getBalance() const
{
    return balance;
}
string Funds::getFundType() const
{
    return fundType;
}
void Funds::setBalance(int mon)
{
    balance = mon;
}
void Funds::setFundType(string fundN)
{
    fundType = fundN;
}
int Funds::deposit(int &mon)
{
    //Add the total amount of money wuith the passed in value.
    return balance += mon;
}
bool Funds::transferWithdraw(int amount, Funds *& transfer1)
{
    //Check if the amount is greater than total. If it is return false
    //and don't withdraw.
    if(amount < balance)
    {
        balance -= amount;
        return true;
    }
    else
    {
        return false;
    }
}
bool Funds::transferDeposit(int amount, Funds *& transfer2)
{
    //Add the total amount of money wuith the passed in value.
    balance += amount;
    return true;
}
int Funds::withdraw(int &mon)
{
    //Check for cases in the withdraw.
    int result = balance - mon;
    if(result < 0 || result > balance)
    {
        return balance;
    }
    else
    {
        //Subtract it.
        balance = result;
        return balance;
    }
    return -1;
}

void Funds::print() const
{
    //Print out the string of a fund
    for(auto i = action.begin(); i != action.end(); i++)
    {
        cout <<"  " <<  *i << endl;
    }
}

void Funds::history(string &history)
{
    //Push the string for the fund.
    action.push_back(history);
}