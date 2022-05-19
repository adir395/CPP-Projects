#include "Tutor.h"

Tutor::Tutor():Teacher()
{
	strcpy(nameofclass," ");
}

Tutor::Tutor(const char* name, long id, int seniority, int numberofsubjects, char** nameofsubjects, char nameofclass [3]): Teacher(name, id, seniority, numberofsubjects, nameofsubjects)
{
	strcpy(this->nameofclass, nameofclass);
}

Tutor::Tutor(const Tutor& t):Teacher(t)
{
	strcpy(nameofclass, t.nameofclass);
}

Tutor::~Tutor()
{
}

float Tutor::calc_tutor_salary()const
{
	float salary = Teacher::calc_salary();
	salary += 1000;
	return salary;
}

void Tutor::print() const
{
	Teacher::print();
	cout << "Name of class: " << nameofclass << endl;
}

const char* Tutor::get_type() const
{
	return "Tutor";
}

void Tutor::print_tutor() const
{
	cout <<"Name: "<< name<<endl;
	cout << "Class: " << nameofclass << endl;
}


