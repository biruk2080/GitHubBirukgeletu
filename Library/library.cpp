#include "library.h"
#include<string>
#include<iostream>
using namespace std; 
// defaukt constractor 
Library::Library()
{
    name=" ";
}
// 
Library::Library(string name)
{
    this->name = name;
    numberOfBooks = 0;
}
bool Library::AddBook(const string& name)
{
    // check the name is empity or the size reach maximum capacity  
    if (name == " " || numberOfBooks == MAX)
    {
        return false;
    }
    // call the findbook methode to check the book is already in library or not  
    int index = findBook(name);
    // if the books exist return false else add the book and return true 
    if(index > 0){
        return false;
    } else {
         books[numberOfBooks] = name;
         numberOfBooks++;
         return true;
    }
}
bool Library::RemoveBook(const string& name)
{
    // check wether the library and the name are empity and return false 
    if (numberOfBooks==0 || name == " ")
    {
        return false;
    }
    // call the findbook method to check wether the book exist or not 
    int index = findBook(name);
    // remove the book if it exist 
    if (index > 0)
    {
        books[index] = books[numberOfBooks-1];
        numberOfBooks--;
        return true;
    }else{
        return false;
    }  
}
bool Library::IsInLibrary(const string& name) const
{
    // check the name is empity or the book is in the library 
     if (name == " "|| findBook(name) < 0 )
    {
        return false;
    } else {
        cout << "The book is already in the library " << endl; 
        return true; 
    }
}
void Library::ListAllBooks() const
{
    // check empty array 
    if (numberOfBooks == 0)
    {
        cout << "There is no book in the Library" << endl;
    }
    // printout all books in the library
    for (int i = 0; i < numberOfBooks; i++)
    {
        cout <<"List of books in the Library: " << endl; 
        cout << books[i] << endl;
    }    
}
int Library::findBook(const string& name) const
{
    // return the index of the book 
   for (int i = 0; i < numberOfBooks; i++)
   {
    if (books[i] == name)
    {
       return i;
    }   
   }
    return -1; 
}
// printout all books in the library
std::ostream &operator<<(std::ostream& out, const Library& lib)
{
    cout <<"List of books in the Library: " << endl; 
    for (int i = 0; i < lib.numberOfBooks; i++)
    {
        out << lib.books[i] << endl;
    }    
    return out;
}