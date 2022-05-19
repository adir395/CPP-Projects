#ifndef TEMP_H
#define TEMP_H
#include "Teacher.h"
#pragma once
class Temp:public Teacher
{
private:
	int weeklyworkhours;
public:
	Temp();
	Temp(const char* name, long id, int seniority, int numberofsubjects, char** nameofsubjects, int weeklyworkhours);
	Temp(const Temp& t);
	~Temp();
	virtual float calc_salary()const;
	void print()const;
	virtual const char* get_type()const;

};
#endif

