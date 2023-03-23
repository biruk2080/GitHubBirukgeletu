#ifndef maze_h
#define maze_h

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class Maze
{
    /*
     * This is the friend operator that looks at the private instance
     * variables.
     *
     * Precondition: The item is an object of Maze.
     *
     * Postcondition: Prints out the maze.
     *
     */
    friend ostream& operator<<(ostream &os, const Maze& item);
public:

    /*
     * Precondition: There are values inside of row and column.
     *
     * Postcondition: Checks whether the character field in the position
     * [row] and [column] is true. If it has a ' ' character, then it
     * returns true.
     */
    bool IsClear(int row, int column) const;

    /*
     * Precondition: There are values inside of row and column.
     *
     * Postcondition: Checks whether the character field in the position
     * [row] and [column] is true. If it has a 'X' character, or a wall,
     * then it returns true.
     */
    bool IsWall(int row, int column) const;

    /*
     * Precondition: There are values inside of row and column.
     *
     * Postcondition: Checks whether the character field in the position
     * [row] and [column] is true. If it has a '*' character, then it
     * returns true.
     */
    bool IsPath(int row, int column) const;

    /*
     * Precondition: There are values inside of row and column.
     *
     * Postcondition: Checks whether the character field in the position
     * [row] and [column] is true. If it has a '+' character, then it
     * returns true.
     */
    bool IsVisited(int row, int column) const;
    
    /*
     * Precondition: There are values inside of row and column.
     *
     * Postcondition: Checks whether the character field in the position
     * [row] and [column] is true. If there is an exit position in the
     * maze, then return true. This is mostly used in the creature class. 
     */
    bool IsExit(int row, int column) const;

    // mark the maze with *
    void MarkAsPath(int row, int column);

    // mark the maze with +
    void MarkAsVisited(int row, int column);

    // Maze constructor requiring a valid file name
    explicit Maze(string mazeFile);
    
private:

    //Set a maximum number in the array.
    static const int MAX_NUMBER_IN_ARRAY = 100;

    //field of characters to put in the maze.
    char field[MAX_NUMBER_IN_ARRAY][MAX_NUMBER_IN_ARRAY];

    //Width
    int xAxis;

    //Height
    int yAxis;

    //Exit y position
    int exitRow;

    //Exit x position
    int exitCol;

};
#endif /* maze_h */