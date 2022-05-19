#include"Date.h"
Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}


Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}


Date::Date(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
}


Date::~Date()
{

}


ostream& operator<<(ostream& os, const Date& other)
{
	os << other.day << "/" << other.month << "/" << other.year << endl;
	return os;
}


void Date::operator=(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
}


bool Date::operator==(const Date& other)const
{
	if (day == other.day && month == other.month && year == other.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}