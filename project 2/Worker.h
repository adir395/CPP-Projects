#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)
#pragma once
class Student;
class Worker
{
private:
	char* name;
	char* id;
	float salary;
	static int numofworkers;
	static float sumofsalary;
public:
	Worker(const char* name, const char* id, float salary);
	Worker(const Worker& w);
	~Worker();
	char* getname();
	char* getid();
	float getsalary()const;
	void setname(char* name);
	void setid(char* id);
	void setsalaray(float salary);
	friend ostream& operator <<(ostream& os, const Worker& s);
	void operator+=(float d);
	void operator*=(float s);
	bool operator>(const Worker& w)const;
	friend void find( Student** s, int size_s,  Worker** w, int size_w, char* find_id);
	static float calcaveragesalary();
};
#endif