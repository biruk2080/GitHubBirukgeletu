#include <iostream>
#include <fstream>
#include <string>
#include "maze.h"

using namespace std;

Maze::Maze(string mazeFile)
{
    //Initialize and open the file.
    ifstream fileIn;
    fileIn.open(mazeFile);

    //If the file fails, it prints out the error message and exits the program
    if(!fileIn)
    {
        cout << "Failed to read the file" << endl;
        exit(0);
    }

    //Initialize the string
    string line;

    //Read in the first 4 numbers of the text file. The first two is the size
    //of the maze. Width (xAxis), and height(yAxis), and the next two is
    //The exit.
    fileIn >> xAxis >> yAxis;
    fileIn >> exitRow >> exitCol;

    //Read the first line. This is necessary because it reads in the whole line
    //and disregards if there is a \n or a white space in the txt file.
    getline(fileIn, line);

    //For each height...
    for(int i = 0; i < yAxis; i++)
    {
        //For each width...
        for(int j = 0; j < xAxis; j++)
        {
            //Put the characters in the field array.
            fileIn.get(field[i][j]);

            //cout just for debugging.
            //cout << field[i][j];
        }

        //Go to the next line and read in the next line.
        //cout << "\n";
        getline(fileIn, line);
    }

    //Close the file.
    fileIn.close();
}


bool Maze::IsClear(int row, int column) const
{
    //If there is a character ' ' in the maze, return true.
    if(field[row][column] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Maze::IsWall(int row, int column) const
{
    //If there is a character X in the maze, return true.
    if(field[row][column] == 'x' || field[row][column] == '#')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Maze::IsPath(int row, int column) const
{
    //If there is a character * in the maze, return true.
    if(field[row][column] == '*')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Maze::IsVisited(int row, int column) const
{
    //If there is a character + in the maze, return true.
    if(field[row][column] == '+')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Maze::IsExit(int row, int column) const
{
    //If the row and column has the same exit as field[exitRow][exitCol]
    //then return true. This method is used in the creature class and will
    //help if the creature reached an exit. 
    if(row == exitRow && column == exitCol)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Maze::MarkAsPath(int row, int column)
{
    // mark the maze with char *
    field[row][column] = '*';
}

void Maze::MarkAsVisited(int row, int column)
{
    // mark the maze with char +
    field[row][column] = '+';
}

ostream& operator<<(ostream &os, const Maze& item)
{
    //Prints out the maze.
    for(int i = 0; i < item.yAxis; i++)
    {
        for(int j = 0; j < item.xAxis; j++)
        {
            os << item.field[i][j];
        }
        os << endl;
    }
    return os;
}