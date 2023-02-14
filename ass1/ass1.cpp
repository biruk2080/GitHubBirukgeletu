#include"library.h"
#include<string>
#include<cassert>
#include<iostream>
using namespace std; 
void Test1()
{
    Library libs("UWB");
    bool result = libs.RemoveBook("The Odyssey");
    assert(!result);
    libs.ListAllBooks();
    libs.AddBook("Don Quixote");
    libs.AddBook("In Search of Lost Time");
    libs.AddBook("Ulyssey");
    libs.AddBook("The Odyssey");
    libs.ListAllBooks();
    result = libs.IsInLibrary("The Odyssey");
    assert(result);
    result = libs.AddBook("The Odyssey");
    assert(!result);
    result = libs.AddBook(" ");
    assert(!result);
    result = libs.RemoveBook("The Odyssey");
    assert(result);
    result = libs.IsInLibrary("The Odyssey");
    assert(!result);
    result = libs.IsInLibrary(" ");
    assert(!result);
    result = libs.RemoveBook("The Odyssey");
    assert(!result);
    cout << libs << endl; 
}
// void Test2()
// {
//     cout << "+++ Test3 ++++++  edge cases" <<endl;
//     Library lib2("BigLibrary" );
//     for (int i = 0; i < 105; i++)
//     {
//         std::string bookName = "book";

//         lib2.AddBook(bookName);
//     }

// }
void TestAll()
{
    Test1();
    Test2();
    cout << "Successfully completed all tests." << endl; 
}
int main()
{
    TestAll(); 
    return 0;
}