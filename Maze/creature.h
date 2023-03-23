#ifndef creature_h
#define creature_h

#include <stdio.h>
#include <iostream>
#include "maze.h"

using namespace std;

class Creature
{
    //Friend operator to print out the creature
    friend ostream &operator<<(ostream &os, const Creature &creature);
public:
    //Constructors
    Creature(int r, int c);

    /*
     * This is the string to solve the maze. It'll print out the North, South,
     * East, West.
     *
     * Precondition: The object is not null and contains values.
     *
     * Postcondition: Print out the best coordinates for solving the maze.
     */
    string Solve(Maze &maze);

private:
    //Private instance variables needed
    int row;
    int col;

    /*
     * This checks whether if north is clear.
     *
     * Precondition: There is an object.
     *
     * Postcondition: * is put down in the path and return true
     * if it is clear.
     */
    bool goNorth(Maze &maze);

    /*
     * This checks whether if south is clear.
     *
     * Precondition: There is an object.
     *
     * Postcondition: * is put down in the path and return true
     * if it is clear.
     */
    bool goSouth(Maze &maze);

    /*
     * This checks whether if east is clear.
     *
     * Precondition: There is an object.
     *
     * Postcondition: * is put down in the path and return true
     * if it is clear.
     */
    bool goEast(Maze &maze);

    /*
     * This checks whether if west is clear.
     *
     * Precondition: There is an object.
     *
     * Postcondition: * is put down in the path and return true
     * if it is clear.
     */
    bool goWest(Maze &maze);
};

#endif /* creature_h*/