#include "Worker.h"

Worker::Worker(const char* name,const char* id, float salary)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
	this->salary = salary;
	numofworkers++;
	sumofsalary += salary;
}

Worker::Worker(const Worker& w)
{
	name = new char[strlen(w.name) + 1];
	strcpy(name, w.name);
	id = new char[strlen(w.id) + 1];
	strcpy(id, w.id);
	salary = w.salary;
	numofworkers++;
	sumofsalary += salary;
}

Worker::~Worker()
{
	cout << "Deleteing..." << name << endl;
	delete[]name;
	delete[]id;
}

char* Worker::getname()
{
	return name;
}

char* Worker::getid()
{
	return id;
}

float Worker::getsalary()const
{
	return salary;
}

void Worker::setname(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Worker::setid(char* id)
{
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
}

void Worker::setsalaray(float salary)
{
	this->salary = salary;
}

void Worker::operator+=(float d)
{
	salary = salary + d;
	sumofsalary += d;
}

void Worker::operator*=(float s)
{
	sumofsalary -= salary;
	salary = (salary * (s / 100)+salary);
	sumofsalary += salary;
}

bool Worker::operator>(const Worker& w) const
{
	if (salary > w.salary)
		return true;
	return false;
}

float Worker::calcaveragesalary()
{
	return (sumofsalary / numofworkers);
}

ostream& operator<<(ostream& os, const Worker& s)
{
	os <<"Worker name: "<< s.name << endl;
	os <<"Id: "<< s.id << endl;
	os <<"Salary: "<< s.salary << endl;
	return os;
}
