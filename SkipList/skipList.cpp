#include "skipList.h"
#include <iostream>
#include <random>
#include <climits>
#include <stdio.h>
SkipList::SkipList(int depth)
{
    // assign the depth of the skiplist 
    this-> depth = depth;
    // create dynamic allocation array of the front and rear guards 
    frontGuards = new SNode*[depth];
    rearGuards = new SNode*[depth];
    //fore each depth create the node and connect with up, down, right and left 
    for (int i = 0; i < depth; i++)
    {
        // create node have min and max 
        SNode* front = new SNode(INT_MIN);
        SNode* rear = new SNode(INT_MAX);
        // assign the front and rear guards to the max and min node
        frontGuards[i] = front;
        rearGuards[i] = rear; 
        // connect the next and the previes of the two guards 
        frontGuards[i]->next = rearGuards[i];
        rearGuards[i]->prev = frontGuards[i]; 
        // connect the up and down of front guards 
        frontGuards[i]->upLevel = frontGuards[i+1];
        frontGuards[i]->downLevel = frontGuards[i-1];
        // connect the up and down of rear guards 
        rearGuards[i]->upLevel = rearGuards[i+1];
        rearGuards[i]->downLevel = rearGuards[i-1];
    }   
}
SkipList::~SkipList()
{
     //For each level...
    for(int i = 0; i < depth; i++)
    {
        //...Delete the node inside the array...
        SNode* temp = frontGuards[i]; 
        //Save the next node after current.
        SNode* current = temp->next;
        //Set every pointer to null
        temp->next = nullptr;
        temp->prev = nullptr;
        temp->downLevel = nullptr;
        temp->upLevel = nullptr;
        //Then delete temp.
        delete temp;
        //... then delete the nodes in between.
        while(current->next != nullptr)
        {
            SNode* temp = current->next;
            current->next = temp->next;
            //Then delete temp.
            delete temp;
            //Set every pointer to null
            temp->next = nullptr;
            temp->prev = nullptr;
            temp->downLevel = nullptr;
            temp->upLevel = nullptr; 
        }
        //Once it exits, the current is the rearGuard array.
        //Delete that.
        rearGuards[i]->next = nullptr;
        rearGuards[i]->upLevel = nullptr;
        rearGuards[i]->downLevel = nullptr;
        delete current;
    }
    
    //Delete the pointers to the array.
    delete[] frontGuards;
    delete[] rearGuards;
}
bool SkipList::Add(int value)
{
    // create newnode point to the o level front guards 
    SNode* nextNode = frontGuards[0]->next;
    // advance nextnode until it reach nullptr or get the data  
    while(nextNode->next != nullptr && nextNode->data < value)
    {
        nextNode = nextNode->next;
    }
    if (nextNode->data == value)
    {
        return false;
    }
    // create new node and and pass the value 
    SNode* newNode = new SNode(value);
    // call add pefore method to add the node 
    addBefore(newNode, nextNode);
   // check if the depth is more that one if that the case excute the 
    if (depth >1)
    {
        // assign to the depth to controle the loop 
       int count = 1;
       bool flag = alsoHigher();
       // excute the loop until the add to next level true and the count less than depth 
       while (flag == true && count < depth )
       {
        // create the new upper node and attched with the new node 
        SNode* newUpprt = new SNode(value);
        newNode->upLevel = newUpprt;
        newUpprt->downLevel = newNode;
       // move nextNode up one level 
        nextNode = frontGuards[count]->next; 
        // advance nextnode until it reach nullptr or the date less than the value  
        while (nextNode->next != nullptr && nextNode->data < value)
        {
            nextNode = nextNode->next; 
        }
        // call the addBefore method to add the upper value 
        addBefore(newUpprt, nextNode);
        // update count and flage 
         count++; 
        bool flag = alsoHigher();
       }  
    }
     return true; 
}
bool SkipList::Contains(int value) const
{
    // go through the each level until reach zero level 
    for (int i = depth -1; i >= 0; i--)
    {
        // create current node  and point to frontGuards[i]->next
        SNode* current = frontGuards[i]->next; 
        // advance the current node until the current is nullptr or the data less than value 
        while (current->next != nullptr && current->data < value)
        {
           current = current->next; 
        }
    // check the data is equal to vlaue and return true
        if (current->data == value)
        {
            return true; 
        }
    }
    // the value is not in the link list so return false 
    return false; 
}
bool SkipList::Remove(int value) 
{
    // assign the level to depth value 
     int level = depth - 1; 
     // flage variable to controle wether the value delete or not 
     bool flag = false; 
     // loop until the depth is less than zero 
    while (level >=0)
    {
         // create deletNode  and point to frontGuards[i]->next
        SNode* deleteNode = frontGuards[level]->next; 
        // advance the deletNode node until the cdeletNode is nullptr or the data less than value 
        while (deleteNode->next != nullptr && deleteNode->data < value)
        {
           deleteNode = deleteNode->next; 
        }
    // check wether the data is equal to the value if it is, delete deleteNode, 
    if (deleteNode->data == value)
    {
        // attached the deleteNode->prev->next to deleteNode->next
        deleteNode->prev->next = deleteNode->next; 
        // attached deleteNode->next->prev to deleteNode->prev
        deleteNode->next->prev = deleteNode->prev; 
        // delete deleteNode ans assign to nullptr
        deleteNode->downLevel = nullptr;
        deleteNode->next = nullptr;
        deleteNode->prev = nullptr;
        deleteNode->upLevel = nullptr;
        delete deleteNode; 
        deleteNode = nullptr; 
        // update the flag
        flag = true; 
    }
    // update the level 
        level--; 
    }
    return flag; 
}
void SkipList::addBefore(SNode *newNode, SNode *nextNode)
{
    //add the newnode and connect with the newNode 
    nextNode->prev->next = newNode;
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    nextNode->prev = newNode; 

}
bool SkipList::alsoHigher() const
{
    // return true if it psooible add at higher level 
    if ((rand() % 2) == 1)
    {
        return true;  
    } else {
        return false; 
    }
}
ostream &operator<<(ostream &out, const SkipList &list)
{
    out << "Skiplist: \n";
    
    for(int i = list.depth - 1; i > -1; i--)
    {
        //...have a head and a rear
        SkipList::SNode* head = list.frontGuards[i];
        SkipList::SNode* rear = list.rearGuards[i];
        out << "Level " << i << ": ";

        //As long as the head is not equal to the rear
        while(head->data != rear->data)
        {
            //Print out the head
            out << head->data << ", ";
            //Traverse
            head = head->next;
        }
        out << rear->data;
        out << endl;
    }
    
    return out; 
}