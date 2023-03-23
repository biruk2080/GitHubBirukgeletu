#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include "account.h"
#include "BST.h"
#include "bank.h"
using namespace std;
Bank::Bank(string fileName)
{
    //Create the ifstream
    ifstream inFile;
    
    //Open it
    inFile.open(fileName);
    
    //If it fails, then don't open
    if (inFile.fail())
    {
        cout << "Error Opening file" << endl;
        exit(1);
    }
    
    //Make the string.
    string transactionList;
    
    //While it is not the end of file...
    while(!inFile.eof())
    {
        //Get each of the line. 
        getline(inFile, transactionList);
        transaction.push(transactionList);
    }
    //Close inFile
    inFile.close();
}

Bank::~Bank(){}
void Bank::transact()
{
    while(!transaction.empty())
    {
        //Split the string into 4 sections.
        //1. The action
        //2. First name
        //3. Last Name
        //4. The amount
        string list[4];
    
        //The act of splitting
        stringstream str(transaction.front());
        for(int i = 0; i < 4; i++)
        {
            //Put them inside of splitArray
            str >> list[i];
        }

        //Set what each of the items inside of the array are.
        string action = list[0];
    
        //Since the action is a char, convert the action to a char.
        char actionChar[action.size() - 1];
        strcpy(actionChar, action.c_str());    
        //Switch Statement for the char.
        switch(actionChar[0])
        {
            case 'O':// if the action is O, open new account and store in BST 
            {
                string firstName = list[1];
                string lastName = list[2];
                //Convert the id to an integer.
                int id = stoi(list[3]);
                //Set everything to the private variables of account.
                acc = new Account(firstName, lastName, id);
                //Insert the account item in the tree.
                bst.Insert(acc);
                break;
            }
            case 'D':
            {
                //Check if there is a fifth element in the id.
                 string idString = list[1];
            // check the id 
            if(idString.size() > 5 || idString.size() < 4)
            {
                cout << "ERROR" << endl;
            }
            // convert string to int 
            int allId = stoi(idString);
            int accountId = allId/10; 
            int fundId = allId%10;
            // check the account is exist or not 
            if (bst.Retrieve(accountId, acc))
            {
                // convert string to int 
                int money = stoi(list[2]);
                stringstream ss;
                string str;
                char mychar = actionChar[0];
                ss << mychar;
                ss >> str;
                string str1 = str + " " + idString + " " + list[2]; 
                //Do the transaction
                acc->transaction(fundId, money, actionChar[0], str1);
            }
                break;
            }
            case 'W':
            {
               string idString = list[1];
            // check the id 
            if(idString.size() > 5 || idString.size() < 4)
            {
                cout << "ERROR" << endl;
            }
            // convert string to int 
            int allId = stoi(idString);
            int accountId = allId/10; 
            int fundId = allId%10;
            // check the account is exist or not 
            if (bst.Retrieve(accountId, acc))
            {
                // convert string to int 
                int money = stoi(list[2]);
                stringstream ss;
                string str;
                char mychar = actionChar[0];
                ss << mychar;
                ss >> str;
                string str1 = str + " " + idString + " " + list[2]; 
                //Do the transaction
                acc->transaction(fundId, money, actionChar[0], str1);
                }
                break;
            }
            case 'T':
            {
                Account* traAccount; 
            string idString = list[1];
            string idStringTransfer = list[3]; 
            // check the id 
            if(idString.size() > 5)
            {
                cout << "ERROR" << endl;
            }
            // convert string to int 
            int allId = stoi(idString);
            int accountId = allId/10; 
            int fundId = allId%10;
            int allTranId = stoi(idStringTransfer);
            int idTraAcc = allTranId/10;
            int idTraFu = allTranId%10;
            // check the existing of the account 
        if(bst.Retrieve(accountId, acc) == false)
        {
            cout << "ERROR: Account " << accountId << " not found. Transferal refused" << endl;
            break;
        }
        if(bst.Retrieve(idTraAcc, traAccount) == false)
        {
            cout << "ERROR: Account " << idTraAcc << " not found. Transferal refused" << endl;
            break;
        }
        // convert the amount to integer 
        int money = stoi(list[2]);
        cout << money << endl; 
        stringstream ss;
        string str;
        char mychar = actionChar[0];
        ss << mychar;
        ss >> str;
        string str1 = str + " " + idString  + " " + list[2] + " " + idStringTransfer;
        acc->transferWithdraw(fundId, acc, money, str1);
        traAccount->transferDeposit(idTraFu, traAccount, money, str1);
        break;
            }
            case 'H':
            {
                 if (list[1].length() == 4)
            {
                int id = stoi(list[1]);
                // retrive the account 
                bst.Retrieve(id, acc);
                cout << "Transaction History for " << acc->getFullName() << " by Fund" << endl;
                acc->displayHistory();
                break;
            }
            else
            {
                if (list[1].length() == 5)
                {
                   string idString = list[1];
                   // convert string to int 
                   int allId = stoi(idString);
                   int accountId = allId/10; 
                   int fundId = allId%10;
                   // retrive the account
                   bst.Retrieve(accountId, acc);
                   cout << "Transaction History for " << acc->getFullName() 
                   << " " << acc->getIndividualFund(fundId)<< endl;
                   acc->displayHistory(fundId);
                }
                
            }
                //Display history
                break;
            }
            default:
            {
                cout << "Must be D, W, T, H!" << endl;
                break;
            }
            
        }
        transaction.pop();
    }
}
void Bank::display() const
{
    //Display the final balance. 
    bst.DisplayTheTree();
}