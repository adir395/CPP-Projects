#include "Secretary.h"

Secretary::Secretary():Worker()
{
	extrahours = 0;
}

Secretary::Secretary(const char* name, long id, int seniority, int extrahours):Worker(name,id,seniority)
{
	this->extrahours = extrahours;
}

Secretary::Secretary(const Secretary& s):Worker(s)
{
	extrahours = s.extrahours;
}

Secretary::~Secretary()
{
}

void Secretary::print() const
{
	cout << "Type of worker: " << get_type() << endl;
	Worker::print();
	cout << "Extra work hours: " << extrahours << endl;
	cout << "Salary: " << calc_salary()<<endl;
}

float Secretary::calc_salary()const
{
	float salary = 5000;
	salary += seniority * 200;
	salary += extrahours * 60;
	return salary;
}

const char* Secretary::get_type() const
{
	return "Secretary";
}
