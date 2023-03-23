#include "robot.h"
#include<math.h>

Robot::Robot(int max_distanc, int robot_x, int robot_y, int treasure_x, int treasure_y)
{
    robot_x_ = robot_x;
    robot_y_ = robot_y;
    treasure_x_ = treasure_x;
    treasure_y_ = treasure_y;
    max_distance_ = max_distanc;
    last_direction_ = 'A';
    current_direction_ =1; 
    direction_end_ = abs(robot_x - treasure_x) + abs(robot_y -treasure_y);
   
}
int Robot::max_distance() const
{
    return max_distance_;
}
int Robot::robot_x() const
{
    return robot_x_;
}
int Robot::robot_y() const
{
    return robot_y_;
}
int Robot::treasure_x() const
{
    return treasure_x_;
}
int Robot::treasure_y() const
{
    return treasure_y_;
}
int Robot::direction_end() const
{
    return direction_end_;
}
vector<char> Robot::path() const
{
    return path_;
}
 bool Robot::IsAtEnd()
 {
     return (path_.size()>= direction_end_);
 }
 bool Robot::IsAtTreasure()
 {
     return ((robot_x_ == treasure_x_) && (robot_y_ == treasure_y_));
 }
bool Robot::IsValidStep(char step)
{
    return !((direction_end_ == current_direction_) &&(last_direction_ == step));
}
 Robot Robot::GoNorth()
 {
     Robot myRobot = *this;
     myRobot.robot_y_++;
     if (myRobot.last_direction_ == 'N')
     {
        myRobot.current_direction_++;
     } else{
        myRobot.last_direction_ ='N';
        myRobot.current_direction_ = 1;
     }
     myRobot.path_.push_back('N');
     return myRobot;
 }
 Robot Robot::GoSouth()
 {
      Robot myRobot = *this;
     myRobot.robot_y_--;
     if (myRobot.last_direction_ == 'S')
     {
        myRobot.current_direction_++;
     } else{
        myRobot.last_direction_ ='S';
        myRobot.current_direction_ = 1;
     }
     myRobot.path_.push_back('S');
     return myRobot;
 }
 Robot Robot::GoEast()
 {
      Robot myRobot = *this;
     myRobot.robot_y_++;
     if (myRobot.last_direction_ == 'E')
     {
        myRobot.current_direction_++;
     } else{
        myRobot.last_direction_ ='E';
        myRobot.current_direction_ = 1;
     }
     myRobot.path_.push_back('E');
     return myRobot;
 }
 Robot Robot::GoWest()
 {
      Robot myRobot = *this;
     myRobot.robot_y_--;
     if (myRobot.last_direction_ == 'W')
     {
        myRobot.current_direction_++;
     } else{
        myRobot.last_direction_ ='W';
        myRobot.current_direction_ = 1;
     }
     myRobot.path_.push_back('W');
     return myRobot;
 }
