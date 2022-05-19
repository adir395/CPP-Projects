#include "Worker.h"

Worker::Worker()
{
	strcpy(this->name, nullptr);
	this->id = 9999999;
	this->hoursalary = 30;
	this->workhour = 12;
	this->extrahour = 4;
}

Worker::Worker(const char name[], long id, double hoursalary, int workhour, int extrahour)
{
	strcpy(this->name, name);
	this->id = id;
	this->hoursalary = hoursalary;
	this->workhour = workhour;
	this->extrahour = extrahour;
}

void Worker::sethoursalary(double hoursalary)
{
	this->hoursalary = hoursalary;
}

void Worker::setworkhour(int workhour)
{
	this->workhour = workhour;
}

void Worker::setextrahour(int extrahour)
{
	this->extrahour = extrahour;
}

double Worker::payment()
{
	double pay;
	pay = (hoursalary * workhour) + (extrahour * hoursalary * 1.5);
	return pay;
}

void Worker::printworker()
{
	cout << "Name: " << getname() << endl;
	cout << "ID: " << getid() << endl;
	cout << "Hour Salary: " << gethoursalary() << endl;
	cout << "Work Hours: " << getworkhour() << endl;
	cout << "Extra Hours: " << getextrahour() << endl;
	cout << "Salary: " << payment() << endl << endl;
}
