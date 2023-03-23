#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <stdio.h>
#include <iostream>
#include <limits>
#include <stdio.h>
using namespace std;
/*
Name Biruk Geletu 
Assignment four 
class: CSS342 
Date: 02/25/2023
in this clas, i created a Skip List data structure to store integers.
When searching a Skip List, items can be found in O(log n) time. No duplicates are allowed.
*/
class SkipList
{
    /*
     This is the friend function. The purpose of this function is to display the
     private instance variables in this class.
     */
    friend ostream &operator<<(ostream &out, const SkipList &list);
public:
/*
     Description: default SkipList has depth of 1, just one doubly-linked list
     Precondition: The value bring passed in is a integer value and is a valid
     value.
     Postcondition: Creates a doubly linked list with a depth of the number
     passed in.
     */
    explicit SkipList(int depth = 1);
    /*
     Description: Destroys everything in the list and destroys the list.
     Precondition: The object is created. 
     Postcondition: Destroys everything in the list and destroys the object.
     */
    virtual ~SkipList();
    /*
     Description: Adds the value being passed in and orders the list.
     Precondition: The value bring passed in is a integer value and is a valid
     value.
     Postcondition: Return true if successfully added, no duplicates.
     */
    bool Add(int value);
    /*
     Description: Removes the value being passed in.
     Precondition: The value bring passed in is a integer value and is a valid
     value.
     Postcondition: Return true if successfully removed.
     */
    bool Remove(int value);
    // return true if found in SkipList
    bool Contains(int value) const; 
private:
     class SNode
    {
        public:
        /*
         Description: Constructor for SNode
         Precondition: The data bring passed in is a integer value and is a valid
         value.
         Postcondition: Set the data, set all other pointers to nullptr
         */
    explicit SNode(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
        upLevel = nullptr;
        downLevel = nullptr;
    }
    // data for node 
        int data;
        // next node 
        SNode *next;
        // link to the previes node
        SNode *prev;
        // link to the upper node 
        SNode *upLevel;
        // link to lower node 
        SNode *downLevel;
        friend class SkipList;
    };
    // the depth of the skiplist
    int depth;
   //array of depth SNode* objects as frontGuards linking levels
    // if depth = 2, we'd have frontGuards[0] and frontGuards[1]
    SNode **frontGuards;
     // array of depth SNode* objects as rearGuards linking levels
    SNode **rearGuards;
     // given a SNode, place it before the given NextNode
    void addBefore(SNode *newNode, SNode *nextNode);
    //return true 50% of time,
    // each node has a 50% chance of being at higher level
    bool alsoHigher() const;
};
#endif