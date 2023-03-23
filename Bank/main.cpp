#include <iostream>
#include "bank.h"
#include "account.h"
#include <assert.h>
#include <sstream>
int main()
{
    Bank bank("BankTransIn.txt");
    bank.transact();
    cout << "Processing Done. Final Balance." << endl;
    bank.display();
    return 0; 
}