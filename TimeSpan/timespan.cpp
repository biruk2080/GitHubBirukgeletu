#include "timespan.h"
using namespace std;

// This is code file of TimeSpan class that implement the header file 
// This class represents a duration of time in Hours, Minutes and Second. 

// this's default constractor 
TimeSpan::TimeSpan() : hour(1), minute(30), second(45)
{
  totalSecond =0;
}
// Constractor recived only second 
TimeSpan::TimeSpan(double second)
{
    totalSecond = second;
    int hur   = totalSecond / 3600;
    int min = (int)totalSecond % 3600/60;
    int sec = (int)totalSecond % 60;
    setTime(hur, min, sec);
}
// Constractor recived minutes and seconds 
TimeSpan::TimeSpan(double minute, double second)
{
    totalSecond = second + 60*minute;
    int hur   = totalSecond / 3600;
    int min = (int)totalSecond % 3600/60;
    int sec = (int)totalSecond % 60;
    setTime(hur, min, sec);
}
// Constractor recived Hours, minutes and seconds 
TimeSpan::TimeSpan(double hour, double minute, double second)
{
    //simplify();
    totalSecond = second + 60*(minute + 60*hour);
    int hur   = (int)totalSecond / 3600;
    int min = (int)totalSecond % 3600/60;
    int sec = (int)totalSecond % 60;
    setTime(hur, min, sec);
}
// set the value of minute, hour and second
 void TimeSpan::setTime(int hour, int minute, int second)
 {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
 }
 // return hour
int TimeSpan::hours()
{
    return hour;
}
// return minutes
int TimeSpan::minutes()
{
    return minute;
}
// return second 
int TimeSpan::seconds()
{
    return second;
}
//operator Overlode
//Comparisons

// check the inequality of the objects 
bool TimeSpan::operator!=(const TimeSpan& timespan) const
{
    if ((hour != timespan.hour)|| (minute != timespan.minute) || (second != timespan.second))
    {
        return true;
    }
    return false;
    
}
// check the greater than or equality of the objects 
bool TimeSpan::operator>=(const TimeSpan& timespan) const
{
    if(operator>(timespan) || operator==(timespan))
    {
        return true;
    }
    return false;
}
// check less than or equality of the objects
bool TimeSpan::operator<=(const TimeSpan& timespan) const
{
     if(operator<(timespan) || operator==(timespan))
    {
        return true;
    }
    return false;
}
//check less than of the objects
bool TimeSpan::operator<(const TimeSpan& timespan) const
{
    if(hour < timespan.hour){
        return true;
    }
    else if((hour == timespan.hour) && (minute < timespan.minute))
    {
        return true;
    }
    else if((hour == timespan.hour) && (minute == timespan.minute) && (second < timespan.second))
    {
        return true;
    }

    return false;
}
//check greater than of the objects
bool TimeSpan::operator>(const TimeSpan& timespan) const
{
    if(hour > timespan.hour){
        return true;
    }
    else if((hour == timespan.hour) && (minute > timespan.minute))
    {
        return true;
    }
    else if((hour == timespan.hour) && (minute == timespan.minute) && (second > timespan.second))
    {
        return true;
    }

    return false;

}
// check the equality of objects
bool TimeSpan::operator==(const TimeSpan& timespan) const
{
     if ((hour == timespan.hour) && (minute == timespan.minute) && (second == timespan.second))
    {
        return true;
    }
    return false;
}

// maths 
// add the two objects 
TimeSpan TimeSpan::operator+(const TimeSpan& timespan) const
{
    TimeSpan ts = *this;
    ts+=timespan;
    return ts;
}
// addition assignment 
TimeSpan& TimeSpan::operator+=(const TimeSpan& timespan)
{
    hour = hour + timespan.hour;
    minute = minute + timespan.minute;
    second = second + timespan.second;
    simplify();
    return *this;
}
// substract the two objects 
TimeSpan TimeSpan::operator-(const TimeSpan& timespan) const
{
    TimeSpan ts = *this;
    ts-=timespan;
    return ts;
}
//substraction assignmemnt
TimeSpan& TimeSpan::operator-=(const TimeSpan& timespan)
{
    hour = hour - timespan.hour;
    minute = minute - timespan.minute;
    second = second - timespan.second;
    simplify();
    return *this;
}
//Unary Negation 
TimeSpan TimeSpan::operator*(const int& multiply) const
{
    TimeSpan ts;
    ts.hour = hour * multiply;
    ts.minute = minute * multiply;
    ts.second = second * multiply;
    ts.simplify();
    return ts;

}
// this method convert the whole time durstion in to second and 
// convert into the right hour, minues and second and return timespan referance. 
TimeSpan& TimeSpan::simplify()
{
    //Convert everything to seconds
    double secondHour = hour * 3600;
    double secondMinutes = minute * 60;
    int secondSecond = second;
       
    //Add them all together to get the total seconds
    int totalSeconds = (int) secondHour +
                (int) secondMinutes + secondSecond;
       
    //1 hour is 3600 seconds so divide the total seconds by 3600
    //to get the hour.
    hour = totalSeconds / 3600;
    
    //To get minutes, you need to get the remainder of the hour. 
    int remainingHour = totalSeconds % 3600;
    
    //You only have remainder of the hour, so divide by 60 to get
    //the actual minutes
    minute = remainingHour / 60;
    
    //To get the seconds of the remainder of the hour, get the remainder
    //of remainingHour divided by 60.
    second = remainingHour % 60;

    return *this;
}

//print out the time duration Hour:Minut:Second 
ostream &operator<<(ostream &outStream, const TimeSpan &time)
{
    //Not necessary, but it'll save doing time.instanceVariable
    //over and over again.
    int h = time.hour;
    int m = time.minute;
    int s = time.second;
    
    //If hour is less than zero and both the min and the seconds are
    //less than -10
    if(h < 0 && m < -10 && s < -10)
    {
        return outStream << "-" << h  * -1
                        << ":" << m * -1 << ":" << s * -1;
    }
    
    //If hour is less than zero and both the minutes are equal to zero
    if(h < 0 && m == 0 && s == 0)
    {
        return outStream << "-" << h  * -1 << ":00:00";
    }
    
    //If hour is less than zero, the minutes is in between zero and
    // -10, the seconds is equal to zero
    if(h < 0 && (m < 0 && m > -10) && s == 0)
    {
        return outStream << "-" << h * -1 << ":0" << m * -1 << ":00";
    }
    
    //If hour is less than zero, the seconds is in between zero and
    // -10, the minutes is equal to zero
    if(h < 0 && m == 0 && (s < 0 && s > -10))
    {
        return outStream << "-" << h * -1 << ":00:0" << s * -1;
    }
    
    //If hour is less than zero and both the minute and seconds is
    //in between 0 and -10.
    if(h < 0 && (m < 0 && m > -10) && (s < 0 && s > -10))
    {
        return outStream << "-" << h * -1<< ":0" << m * -1 << ":0" << s * -1;
    }
    
    //If hour is zero and both minutes and seconds is less than -10
    if(h == 0 && m < -10 && s < -10)
    {
        return outStream << "-0:" << m * -1 << ":" << s * -1;
    }
    
    //If hour is zero, minutes is in between zero and -10, and seconds
    //is zero
    if(h == 0 && (m < 0 && m > -10) && s == 0)
    {
        return outStream << "-0:0" << m * -1 << ":00";
    }
    
    //If hour is zero and both minutes and seconds is in between zero
    //and -10
    if(h == 0 && (m < 0 && m > -10) && (s < 0 && s > -10))
    {
        return outStream << "-0:0" << m * -1 << ":0" << s * -1;
    }
    
    //If all the time is zero.
    if(h == 0 && m == 0 && s == 0)
    {
        return outStream << "0:00:00";
    }
    
    
    //Output the outStream if both min and sec are 0.
    if(m == 0 && s == 0)
    {
        return outStream << h << ":00:00";
    }
    
    //if not, then output the outStream if min is 0 and sec is
    //less than 10.
    if((m == 0) && (s < 10 && s >= 0))
    {
        return outStream << h << ":00:0" << s;
    }
    
    //if not, then output the outStream if min is 0.
    if(m == 0)
    {
        return outStream << h << ":00:" << s;
    }
    
    //if not, then output the outStream if min is less than 0
    if(m >= 0 && m < 10)
    {
        return outStream << h << ":0" << m << ":" << s;
    }
    
    //if not, then output the outStream if sec is
    //less than 10.
    if(s >= 0 && s < 10)
    {
        return outStream << h << ":" << m << ":0" << s;
    }
    
    //if not, then output the outStream if sec is 0
    if(s == 0)
    {
        return outStream << h << ":" << m << ":00";
    }
       
    //If none of the conditions are met, then print out the
    //time. 
    return outStream << h << ":" << m << ":" << s;
}

