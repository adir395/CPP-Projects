#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& other);
	~Date();
	friend ostream& operator<<(ostream& os, const Date& other);
	void operator=(const Date& other);
	bool operator==(const Date& other)const;
};