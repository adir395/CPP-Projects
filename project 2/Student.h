#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)
#pragma once
class Worker;
class Student
{
private:
	char* name;
	char* id;
	int numofcourse;
	int* grades;
	static int static_numofcourses;
	static float allaverage;
public:
	Student(const char* name,const char* id);
	Student(const Student& st);//copy cons
	~Student();
	float average()const;
	friend ostream& operator <<(ostream& os, const Student& s);
	void operator+=(int g);///add grade to student
	bool operator>(const Student& st)const;
	static float calcaverages_static();
	friend void find( Student** s, int size_s,  Worker** w, int size_w, char* find_id);
};
#endif

