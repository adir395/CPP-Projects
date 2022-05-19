#include "Worker.h"

Worker::Worker()
{
	name = nullptr;
	id = 0;
	seniority = 0;
}

Worker::Worker(const char* name, long id, int seniority)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->id = id;
	this->seniority = seniority;
}

Worker::Worker(const Worker& w)
{
	name = new char[strlen(w.name) + 1];
	strcpy(name, w.name);
	id = w.id;
	seniority = w.seniority;
}

Worker::~Worker()
{
	if(name!=nullptr)
		delete[]name;
}

float Worker::calc_salary()
{
	return 0.0f;
}

void Worker::print()const
{
	cout << "Name: " << name<<endl;
	cout << "Id: " << id << endl;
	cout << "Seniority: " << seniority << endl;
}

const char* Worker::get_type() const
{
	return "Worker";
}

const long Worker::get_id() const
{
	return id;
}
