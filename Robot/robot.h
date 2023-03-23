#ifndef ROBOT_H_
#define ROBOT_H_
#include <string>
#include <vector>
using namespace std;

class Robot
{
public:
    Robot();
    Robot(int max_distanc, int robot_x, int robot_y, int treasure_x, int treasure_y);
   
    // setters and getters 
    int robot_x() const;
    int robot_y() const;
    int treasure_x() const;
    int treasure_y() const;
    int max_distance() const;
    int direction_end() const;
    vector<char> path() const;

    bool IsAtEnd();
    bool IsAtTreasure();
    bool IsValidStep(char step);

    Robot GoNorth();
    Robot GoSouth();
    Robot GoEast();
    Robot GoWest();

private:
int robot_x_;
int robot_y_;
int treasure_x_;
int treasure_y_;
int max_distance_;
int direction_end_;
int current_direction_;
vector<char> path_;
char last_direction_;

};

#endif