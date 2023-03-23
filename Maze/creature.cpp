#include <iostream>
#include <string>

#include "creature.h"
#include "maze.h"


using namespace std;

Creature::Creature(int r, int c)
{
    //Set this objects instance variables to the passing values.
    row = r;
    col = c;
}

ostream &operator<<(ostream &os, const Creature &creature)
{
    os << "The creature's position is: \n" << "row: " << creature.row
    << "\n" << "col: " << creature.col << endl;
    return os;
}


bool Creature::goNorth(Maze &maze)
{
    //If north is clear...
    if(maze.IsClear(row - 1, col))
    {
        //Mark it as a path
        maze.MarkAsPath(row - 1, col);
        row--;
        return true;
    }
    else
    {
        //Otherwise return false.
        return false;
    }
}

bool Creature::goWest(Maze &maze)
{
    //Backtracking: If west is already a path...
    if(maze.IsClear(row, col - 1))
    {
        //...mark it as a path
        maze.MarkAsPath(row, col - 1);
    
        //Go West
        col--;
        return true;
    }
    else
    {
        //Otherwise, return false.
        return false;
    }
}

bool Creature::goSouth(Maze &maze)
{
    //If South is clear...
    if(maze.IsClear(row + 1, col))
    {
        //...mark it as a path
        maze.MarkAsPath(row + 1, col);
        
        //Go south.
        row++;
        return true;
    }
    else
    {
        //Otherwise, return false
        return false;
    }
}

bool Creature::goEast(Maze &maze)
{
    //If East is clear...
    if(maze.IsClear(row, col + 1))
    {
        //...mark that position as a path
        maze.MarkAsPath(row, col + 1);
    
        // and go east.
        col++;
        return true;
    }
    else
    {
        //If it is not clear, return false
        return false;
    }
}

string Creature::Solve(Maze &maze)
{
    //Initializing the string thePath to append the direction of the path
    string thePath;
    
    //Base Case 1: If the starting position is clear
    if(maze.IsClear(row, col))
    {
        maze.MarkAsPath(row, col);
    }
    
    //Base Case 2: If the creature reached an exit.
    if(maze.IsExit(row, col))
    {
        return thePath;
    }
    
    //Base Case 3: If the starting position is a wall, then return X
    if(maze.IsWall(row, col))
    {
        return "X";
    }
    
    //Otherwise...
    else
    {
        //Check if North is clear
        if(goNorth(maze))
        {
            //If north is clear, then go north and update the string.
            thePath += "N";
            //Recurse.
            return thePath += Solve(maze);
        }
        //Check if north is a wall, is visited, or is a path.
        if(maze.IsWall(row - 1, col) || maze.IsVisited(row - 1, col)
                    || maze.IsPath(row - 1, col))
        {
            //If it is, then check west first before checking if
            //north is a path.
            if(goWest(maze))
            {
                //If west is clear, then go west and update the string.
                thePath += "W";
                //Recurse
                return thePath += Solve(maze);
            }
            //If west is a wall, visited, or path...
            if(maze.IsWall(row, col - 1) || maze.IsVisited(row, col - 1)
                            || maze.IsPath(row, col - 1))
            {
                //...Check east first.
                if(goEast(maze))
                {
                    //If east is clear, go east and update the path.
                    thePath += "E";
                    //Recurse
                    return thePath += Solve(maze);
                }
                //IF east is a wall, visited, or a path...
                if(maze.IsWall(row, col + 1) || maze.IsVisited(row, col + 1)
                            || maze.IsPath(row, col + 1))
                {
                    //...Check south first.
                    if(goSouth(maze))
                    {
                        //If south is clear, then go south and update the
                        //path string.
                        thePath += "S";
                        //Recurse.
                        return thePath += Solve(maze);
                    }
                    //If south is not a path, now check if east is a path.
                    if(maze.IsPath(row, col + 1))
                    {
                        //If it is, then mark it as visited and move east.
                        maze.MarkAsVisited(row, col);
                        col++;
                        //Pop the string back removing the E
                        thePath = thePath.substr(0, thePath.length() - 1);
    
                        //Recurse
                        return thePath += Solve(maze);
                    }
                    //If south is a wall, visited or path...
                    if(maze.IsWall(row + 1, col) || maze.IsVisited(row + 1, col)
                            || maze.IsPath(row + 1, col))
                    {
                        //You don't have to check to go anywhere because
                        //every direction has already been checked.
                        //Now check if south is a path.
                        if(maze.IsPath(row + 1, col))
                        {
                            //If south is a path, then mark it as visited
                            //and go south.
                            maze.MarkAsVisited(row, col);
                            row++;
                            //Pop the string back to remove the S
                            thePath = thePath.substr(0, thePath.length() - 1);

                            //Recurse.
                            return thePath += Solve(maze);
                        }
                        //If East is not clear, then you can check if West is a
                        //path.
                        if(maze.IsPath(row, col - 1))
                        {
                            //If it is, then mark the current position as visited
                            //and move west.
                            maze.MarkAsVisited(row, col);
                            col--;
                            //Pop the last character string to remove the W
                            thePath = thePath.substr(0, thePath.length() - 1);
                            //Recurse.
                            return thePath += Solve(maze);
                        }
    
                        if(maze.IsPath(row - 1, col))
                        {
                            //If it is, then mark the current position as visited
                            //and move west.
                            maze.MarkAsVisited(row, col);
                            row--;
                            //Pop the last character string to remove the W
                            thePath = thePath.substr(0, thePath.length() - 1);
                            //Recurse.
                            return thePath += Solve(maze);
                        }
                        //Since you checked if every direction is a wall, visited
                        //or a path, and it lead you to this point, check if south
                        //is a wall. If it is then it means that you are blocked
                        //and cannot get out.
                        return "X";
                    }
                }
            }
        }
    }
    return thePath;
}