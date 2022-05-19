#include "Date.h"

bool Date::SetDay(int day)
{
	if (day < 1 || day>31)
	{
		cout << "Day must have between 1-31" << endl;
		return false;	
	}
	this->day = day;
	return true;
}
int Date::GetDay() const
{
	return this->day;
}
bool Date::SetMonth(int month)
{
	if (month < 1 || month>12)
	{
		cout << "Month must have between 1-12" << endl;
		return false;
	}
	this->month = month;
	return true;
}
int Date::GetMonth() const
{
	return this->month;
}
bool Date::SetYear(int year)
{
	if (year < 999 || year>9000)
	{
		return false;
		cout << "Year must have between 999-9000" << endl;
	}
	this->year = year;
	return true;
}
int Date::GetYear() const 
{
	return this->year;
}

void Date::PrintDate()
{
	cout << GetDay() << "/" << GetMonth() << "/" << GetYear() << endl;
}

Date::Date(const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;

}

Date::Date() //default ctor
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	this->day = timeinfo->tm_mday;
	this->month = timeinfo->tm_mon + 1;
	this->year = timeinfo->tm_year + 1900;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{

}

Date Date::CalcDiff(Date d)
{
	static int increment[12] = { 1, -2, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };
	int daysInc = 0;
	if ((d.GetDay() - this->GetDay()) < 0)
	{
		int month = this->GetMonth() - 2; 
		if (month < 0)
			month = 11;
		daysInc = increment[month];
		if ((month == 1) && (this->GetYear() % 4 == 0))
			daysInc++; 
	}

	int total1 = d.GetYear() * 360 + d.GetMonth() * 30 + d.GetDay();
	int total2 = this->GetYear() * 360 + this->GetMonth() * 30 + this->GetDay();
	int diff = total2 - total1;
	int years = diff / 360;
	int months = (diff - years * 360) / 30;
	int days = diff - years * 360 - months * 30 + daysInc;

	if (d.GetDay() == 1 && this->GetDay() == 31) {
		months--;
		days = 30;
	}

	Date result(days, months, years);
	return result;

}