#include"LinkedList.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
    LinkedList<int> myList; 
    int a =1, b = -1, c = 13;
    myList.Insert(&a);
    myList.Insert(&b);
    myList.Insert(&c);
    cout << "start" << endl;
    cout << myList << endl;
    cout << "start" << endl;   
}