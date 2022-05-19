#include "Temp.h"

Temp::Temp():Teacher()
{
	weeklyworkhours = 0;
}

Temp::Temp(const char* name, long id, int seniority, int numberofsubjects, char** nameofsubjects, int weeklyworkhours):Teacher(name,id,seniority,numberofsubjects,nameofsubjects)
{
	this->weeklyworkhours = weeklyworkhours;
}

Temp::Temp(const Temp& t):Teacher(t)
{
	weeklyworkhours = t.weeklyworkhours;
}

Temp::~Temp()
{
}

float Temp::calc_salary()const
{
	float salary = Teacher::calc_salary();
	salary += 300 * weeklyworkhours;
	if (seniority > 5 && weeklyworkhours > 10)
		salary += 700;
	return salary;
}

void Temp::print()const
{
	Teacher::print();
	cout << "Weekly work hours: " << weeklyworkhours << endl;
}

const char* Temp::get_type() const
{
	return "Temp";
}
