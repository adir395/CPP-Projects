#include "Student.h"

Student::Student(const char* name,const char* id)
{
	this->name = new char[strlen(name + 1)];
	strcpy(this->name, name);
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
	this->numofcourse = 0;
	this->grades = NULL;
}

Student::Student(const Student& st)
{
	this->name = new char[strlen(st.name + 1)];
	strcpy(this->name, st.name);
	this->id = new char[strlen(st.id + 1)];
	strcpy(this->id, st.id);
	this->numofcourse = st.numofcourse;
	this->grades = new int[numofcourse];
	for (int i = 0; i < numofcourse; i++)
	{
		this->grades[i] = st.grades[i];
		static_numofcourses++;
	}
	allaverage += average();
}

Student::~Student()
{
	cout << "deleteing... " << name<<endl;
	//if(name)
		//delete[]name;
	delete[]id;
	if(grades!=NULL)
		delete[]grades;
}


float Student::average()const
{
	float temp=0;
	if (numofcourse == 0)
		return 0.0;
	for (int i = 0; i < numofcourse; i++)
		temp = temp + grades[i];
	return temp;
}

void Student::operator+=(int g)
{
	if (g <= 100 && g >= 0)
	{
		numofcourse++;
		static_numofcourses++;
		if (numofcourse == 1)
		{
			grades = new int[numofcourse];
			grades[0] = g;
			allaverage += average();
			return;
		}
		int i;
		int* temp = new int[numofcourse-1];
		for (i = 0; i < numofcourse-1; i++)
			temp[i] = grades[i];
		delete[]grades;
		grades = new int[numofcourse];
		for (i = 0; i < numofcourse-1; i++)
			grades[i] = temp[i];
		grades[i] = g;
		delete[]temp;
		allaverage += average();
		return;
	}
	cout << "Error-bad grade" << endl;
}

bool Student::operator>(const Student& st) const
{
	if (this->average() > st.average())
		return true;
	return false;
}

float Student::calcaverages_static()
{	
	return allaverage / static_numofcourses;
}

ostream& operator<<(ostream& os, const Student& s)
{
	os <<"Student name: "<< s.name << endl;
	os <<"Id: "<< s.id << endl;
	os <<"Number of courses: "<< s.numofcourse << endl;
	os << "Grades: ";
	if (s.numofcourse == 0)
		cout << "None" << endl;
	else
	{
		for (int i = 0; i < s.numofcourse; i++)
			os << s.grades[i] << " ";
		os << endl;
	}
	os <<"Average: "<< s.average() << endl;
	return os;
}
