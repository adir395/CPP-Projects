#ifndef DEPUTY_H
#define DEPUTY_H
#include "Tutor.h"
#pragma once

class Deputy:public Tutor
{
public:
	Deputy();
	Deputy(const char* name, long id, int seniority, int numberofsubjects, char** nameofsubjects, char nameofclass[3]);
	Deputy(const Deputy& d);
	~Deputy();
	virtual float calc_salary()const;
	void print()const;
	virtual const char* get_type()const;
	const char* get_name()const;
	void print_tutor()const;

};
#endif
