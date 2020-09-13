/************************************
*BLG252E-Object Oriented Programming*
*Homework-1                         *
*Mehmet Gencay Ertürk - 150130118   *
************************************/    
#include <iostream>
#include "Time.h"
using namespace std;
Time::Time(int a[5])
{
        day=a[0];
        month=a[1];
        year=a[2];
        hour=a[3];
        minute=a[4];
}
void Time::getTime()
{
	cout << hour << '.' << minute << ' ' << day << '/' << month << "/20" << year<<endl;
}
bool Time::operator==(const Time& t)
{
	return (year == t.year) && (month == t.month) && (day == t.day) && (hour == t.hour) && (minute == t.minute);
}
bool Time::operator<(const Time& t)
{
	if (year != t.year) return year < t.year;
	else if(month != t.month) return month < t.month;
	else if(day != t.day) return day < t.day;
	else if (hour != t.hour) return hour < t.hour;
	else if (minute != t.minute) return minute < t.minute;
	else return !(*this == t);
}
bool Time::operator>(const Time& t)
{
   return !(*this < t) && !(*this == t);
}
long int Time::getDate()
{
	return year*10000+month*100+day;
}
