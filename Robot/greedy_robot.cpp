#include "robot.h"
#include <iostream>
#include <string>
using namespace std;
void ShortestPath(Robot myRobot);

int main(int argc, char* argv[])
{
    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    if (argc == 6)
    {
        int direction_max = stoi(argv[1]);
        int direction_x = stoi(argv[2]);
        int direction_y = stoi(argv[3]);
        int treasure_x = stoi(argv[4]);
        int treasure_y = stoi(argv[5]);
        Robot robot(direction_max, direction_x, direction_y, treasure_x, treasure_y);
        if (robot.direction_end() == 0)
        {
           cout << "The Maximum Distance is 0";
        } else 
        {
            ShortestPath(robot);
        }
    }
}
void ShortestPath(Robot myRobot)
{
    if (myRobot.IsAtTreasure())
    {
       vector<char> myPath = myRobot.path();
       for (int i = 0; i < myPath.size(); i++)
       {
          cout << myPath[i];
       }
    }
    if (myRobot.IsAtEnd())
    {
      
    }
    if (myRobot.IsValidStep('N'))
    {
       ShortestPath(myRobot.GoNorth());
    }
    if (myRobot.IsValidStep('S'))
    {
       ShortestPath(myRobot.GoSouth());
    }
    if (myRobot.IsValidStep('E'))
    {
       ShortestPath(myRobot.GoEast());
    }
    if (myRobot.IsValidStep('W'))
    {
       ShortestPath(myRobot.GoWest());
    }
    
}