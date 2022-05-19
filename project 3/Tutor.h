#ifndef TUTOR_H
#define TUTOR_H
#include "Teacher.h"
using namespace std;
#pragma once

class Tutor:public Teacher
{
protected:
	char nameofclass [3];
public:
	Tutor();
	Tutor(const char* name, long id, int seniority, int numberofsubjects, char** nameofsubjects, char nameofclass[3]);
	Tutor(const Tutor& t);
	~Tutor();
	virtual float calc_tutor_salary()const;
	virtual void print()const;
	virtual const char* get_type()const;
	virtual void print_tutor()const;

};
#endif

