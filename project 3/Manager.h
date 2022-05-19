#ifndef MANAGER_H
#define MANAGER_H
#include "Worker.h"

class Manager:public Worker
{
public:
	Manager();
	Manager(const char* name, long id, int seniority);
	Manager(const Manager& m);
	~Manager();
	float calc_salary()const;
	void print()const;
	const char* get_type()const;
	const char* get_name()const;
};
#endif

