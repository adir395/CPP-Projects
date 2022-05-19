#ifndef SCHOOL_H
#define SCHOOL_H
#include <iostream>
#include <string.h>
#include"Worker.h"
#include "Teacher.h"
#include"Temp.h"
#include"Tutor.h"
#include"Deputy.h"
#include "Manager.h"
#include "Secretary.h"
using namespace std;
#pragma warning(disable:4996)
#pragma once

class School
{
private:

	int numberofworkers;
	Worker** w=NULL;
	bool schoolmanager;

public:

	School();
	~School();
	void menu();
	void print_menu();
	void operator+=(Worker* wo);
};

#endif