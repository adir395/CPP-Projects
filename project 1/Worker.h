#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

class Worker
{
private:
	char name[15];
	long id;
	double hoursalary;
	int workhour;
	int extrahour;
public:
	Worker();
	Worker(const char name[], long id, double hoursalary, int workhour, int extrahour);//name by const
	char* getname() { return name; }
	long getid() { return id; }
	double gethoursalary() { return hoursalary; }
	int getworkhour() { return workhour; }
	int getextrahour() { return extrahour; }
	void sethoursalary(double hoursalary);
	void setworkhour(int workhour);
	void setextrahour(int extrahour);
	double payment();
	void printworker();
};



