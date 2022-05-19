#include "Manager.h"

Manager::Manager():Worker()
{
}

Manager::Manager(const char* name, long id, int seniority):Worker(name,id,seniority)
{
}

Manager::Manager(const Manager& m):Worker(m)
{
}

Manager::~Manager()
{
}

float Manager::calc_salary()const
{
	float average = 10000 + (seniority * 800);
	return average;
}

void Manager::print() const
{
	cout << "Type of worker: " << get_type() << endl;
	Worker::print();
	cout <<"Salary:"<< calc_salary() << endl;
	
}

const char* Manager::get_type() const
{
	return "Manager";
}

const char* Manager::get_name() const
{
	return this->name;
}
