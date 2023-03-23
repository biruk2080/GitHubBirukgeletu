#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <iostream>
#include <istream>
#pragma once
/*
Name Biruk Geletu 
Assignment Two 
class: CSS342 
Instructor:  
this class implement TimeSpan class which represents a duration in hours, minutes and seconds.
*/

// This header file contain the interface of TimeSpan class and the class data members. 

class TimeSpan
{
    // This is the friend function. This will allow the function to
    // have access to the private instance variables of the classes.
    friend std::ostream& operator<<(std::ostream& stream, const TimeSpan& timespan);
public:
    //Constructors
    TimeSpan();
    TimeSpan(double second);
    TimeSpan(double minute, double second);
    TimeSpan(double hour, double minute, double second);

   //Getter and Setter
   int hours();
   int minutes();
   int seconds();
   // Actions
   void setTime(int hour, int minute, int second);
   // operator Overlode
   //Comparisons
   bool operator==(const TimeSpan& timespan) const;
   bool operator!=(const TimeSpan& timespan) const;
   bool operator<=(const TimeSpan& timespan) const;
   bool operator>=(const TimeSpan& timespan) const;
   bool operator>(const TimeSpan& timespan) const;
   bool operator<(const TimeSpan& timespan) const;
  
   // Mathes
   // This method overloads the + operator to add two objects
   // and their private instance variables together.
   TimeSpan operator+(const TimeSpan& timespan) const;
   TimeSpan& operator-=(const TimeSpan& timespan);
   TimeSpan& operator+=(const TimeSpan& timespan);
   TimeSpan operator-(const TimeSpan& timespan) const;
   TimeSpan operator*(const int& multipy) const;

private:
// class data members 
int hour;
int minute;
int second;
double totalSecond;
// this method convert the whole time durstion in to second and 
// convert into the right hour, minues and second and return timespan referance. 
TimeSpan& simplify(); 
};

#endif

