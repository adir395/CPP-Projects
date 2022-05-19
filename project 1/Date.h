#ifndef DATE_H
#define DATE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

class Date
{
public:
	Date();
	Date(int day, int month, int year);
	~Date();
	Date(const Date& d);
	bool SetDay(int day);
	int GetDay() const;
	bool SetMonth(int month);
	int GetMonth() const;
	bool SetYear(int year);
	int GetYear() const;
	void PrintDate();
	Date CalcDiff(Date d);



private:
	int day, month, year;
};

#endif // !DATE_H