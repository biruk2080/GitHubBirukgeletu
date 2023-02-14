#ifndef LIBRARY_CPP_LIBRARY_H
#define LIBRARY_CPP_LIBRARY_H
#include<string>
#include<ostream>
using namespace std; 
/*
Name Biruk Geletu 
Assignment one 
class: CSS342 
Instructor:  
this class is a library class that store books in array, add, and 
remove books from the library and does other operation 
*/

class Library
{
public:
    // default constractor 
    Library();
    // a constractor accept one parameter 
    explicit Library(string name); 
    // this method accept the name of the book as a parameter and returen true if the books sucessfuly add or return false if not 
    bool AddBook(const string& name);
    // accept the book as a parameter and returen true if the books sucessfuly remove or return false if not 
    bool RemoveBook(const string& name);
    // the methode printout the all books in the library 
    void ListAllBooks() const;
    // this method accept the name of the book as a parameter and return true if the books is exist, return false if not exist. 
    bool IsInLibrary(const string& name) const;
    // this is a friend methode that access the instance of the class and printout the all books in the library. 
    friend std::ostream &operator<<(std::ostream& out, const Library& lib);
private:
   // the name of the library 
   string name; 
   // the maximum size of the array
   static const int MAX = 100;
   // a variable tracking the number of books added in the library 
   int numberOfBooks;
   // a private method that return the index of a book if the book is exist or return -1 if not. 
   int findBook(const string& name) const;
   
   string books[MAX]; 
};
#endif