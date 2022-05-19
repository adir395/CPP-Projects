#ifndef SECRETARY_H
#define SECRETARY_H
#include "Worker.h"
#pragma once

class Secretary:public Worker
{
private:
	int extrahours;
public:
	Secretary();
	Secretary(const char* name, long id, int seniority, int workhours);
	Secretary(const Secretary& s);
	~Secretary();
	void print()const;
	float calc_salary()const;
	virtual const char* get_type()const;

};

#endif

