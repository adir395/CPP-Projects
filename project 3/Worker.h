#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)
#pragma once

class Worker
{
protected:
	char* name;
	long id;
	int seniority;
public:
	Worker();
	Worker(const char* name, long id, int seniority);
	Worker(const Worker& w);
	virtual ~Worker();
	virtual float calc_salary();
	virtual void print()const;
	virtual const char* get_type()const;
	virtual const long get_id()const;
};

#endif