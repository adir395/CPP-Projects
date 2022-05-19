#ifndef TEACHER_H
#define TEACHER_H
#include "Worker.h"
#pragma once
class Teacher:public Worker
{
protected:
	int numberofsubjects;
	char** nameofsubjects;
public:
	Teacher();
	Teacher(const char* name, long id, int seniority, int numberofsubjects, char** nameofsubjects);
	Teacher(const Teacher& t);
	virtual ~Teacher();
	virtual float calc_salary()const;
	virtual void print()const;
	virtual const char* get_type()const;
	virtual void print_by_sub(char* sub)const;
};
#endif
