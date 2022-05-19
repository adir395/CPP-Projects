#include "Teacher.h"

Teacher::Teacher():Worker()
{
	numberofsubjects = 0;
	nameofsubjects = nullptr;
}

Teacher::Teacher(const char* name, long id, int seniority, int numberofsubjects, char** nameofsubjects):Worker(name,id,seniority)
{
	this->numberofsubjects = numberofsubjects;
	this->nameofsubjects = new char* [numberofsubjects];
	for (int i = 0; i < numberofsubjects; i++)
	{
		this->nameofsubjects[i] = new char[strlen(nameofsubjects[i]) + 1];
		strcpy(this->nameofsubjects[i], nameofsubjects[i]);
	}

}

Teacher::Teacher(const Teacher& t): Worker(t)
{
	numberofsubjects = t.numberofsubjects;
	nameofsubjects = new char* [numberofsubjects];
	for (int i = 0; i < numberofsubjects; i++)
	{
		nameofsubjects[i] = new char[strlen(t.nameofsubjects[i]) + 1];
		strcpy(nameofsubjects[i], t.nameofsubjects[i]);
	}

}

Teacher::~Teacher()
{
	for (int i = 0; i < numberofsubjects; i++)
		delete nameofsubjects[i];
	delete[] nameofsubjects;
}

float Teacher::calc_salary()const
{
	float salary = 5000;
	salary += 500 * seniority;
	salary += 300 * numberofsubjects;
	return salary;
}

void Teacher::print()const
{
	cout <<"Type of worker: "<< get_type() << endl;
	Worker::print();
	cout <<"Number of subject: " << numberofsubjects << endl;
	cout << "Name of subjects: " << endl;
	for (int i = 0; i < numberofsubjects; i++)
		cout << nameofsubjects[i]<<" ";
	cout << endl;
	cout << "Salary: " << calc_salary() << endl;
}

const char* Teacher::get_type() const
{
	return "Teacher";
}

void Teacher::print_by_sub(char* sub) const
{
	for (int i = 0; i < numberofsubjects; i++)
		if (strcmp(nameofsubjects[i], sub) == 0)
			print();
}
