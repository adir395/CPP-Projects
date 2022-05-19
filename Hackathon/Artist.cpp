#define _CRT_SECURE_NO_WARNINGS
#include<typeinfo>
#include"Artist.h"
#include"Wallstatue.h"
Artist::Artist()
{
	name = new char[5];
	strcpy(name, " ");
	born;
	death;
	creationlist = NULL;
	numofcreations = 0;
}
Artist::Artist(char* name, Date born, Date death)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->born = born;
	this->death = death;
	creationlist = NULL;
	numofcreations = 0;
}
Artist::Artist(const Artist& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	born = other.born;
	death = other.death;
	numofcreations = other.numofcreations;
	creationlist = new Creation * [numofcreations];
	for (int i = 0; i < numofcreations; i++)
	{
		creationlist[i] = other.creationlist[i];
	}
}
Artist::~Artist()
{
	for (int i = 0; i < numofcreations; i++)
	{
		delete creationlist[i];
	}
	delete[]creationlist;
	delete[]name;
}
void Artist::addcreation(Creation* creation)
{
	if (numofcreations == 0)
	{

		creationlist = new Creation * [1];
		creationlist[0] = creation;
		numofcreations++;
		cout << "Creation added\n" << endl;
	}
	else
	{

		Creation** temp = new Creation * [numofcreations + 1];
		for (int i = 0; i < numofcreations; i++)
		{
			temp[i] = creationlist[i];
		}
		temp[numofcreations] = creation;
		numofcreations++;
		delete[]creationlist;
		creationlist = temp;
		cout << "Creation added\n" << endl;
	}
}
ostream& operator<<(ostream& os, const Artist& other)
{
	os << "Name: " << other.name << endl;
	os << "Born date: " << other.born << endl;
	os << "Death date" << other.death << endl;
	os << "Creation list" << endl;
	for (int i = 0; i < other.numofcreations; i++)
	{
		os << other.creationlist[i]->getname() << endl;
	}
	return os;
}

void Artist::operator=(const Artist& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	born = other.born;
	death = other.death;
	numofcreations = other.numofcreations;
	creationlist = new Creation * [numofcreations];
	for (int i = 0; i < numofcreations; i++)
	{
		creationlist[i] = other.creationlist[i];
	}
}
int Artist::getnumofcreation()const
{
	return numofcreations;
}


const char* Artist::getname()const
{
	return name;
}

bool Artist::operator==(const Artist& other)const
{
	int counter = 0;
	if (strcmp(name, other.name) == 0)
	{
		counter++;
	}
	if (born == other.born && death == death)
	{
		counter++;
	}
	if (counter == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Artist::deletecreation(char* name)
{
	int index = 0;
	if (numofcreations == 0)
	{
		cout << "There nothing to delete" << endl;
	}
	else
	{
		for (int i = 0; i < numofcreations; i++)
		{
			if (strcmp(name, creationlist[i]->getname()) == 0)
			{
				index = i;
			}
		}
		Creation** temp = new Creation * [numofcreations - 1];
		if (index == 0)
		{
			int k = 0;
			for (int i = 1; i < numofcreations; i++)
			{
				temp[k] = creationlist[i];
				k++;
			}
		}
		else if (index = numofcreations - 1)
		{
			for (int i = 0; i < numofcreations - 1; i++)
			{
				temp[i] = creationlist[i];
			}
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				temp[i] = creationlist[i];
			}
			for (int i = index + 1; i < numofcreations; i++)
			{
				temp[i] = creationlist[i];
			}
		}
		delete creationlist[index];
		delete[]creationlist;
		creationlist = temp;
		numofcreations--;
		cout << "Creation deleted\n" << endl;
	}
}


const char* Artist::getcrationname(char* name)const
{
	for (int i = 0; i < numofcreations; i++)
	{
		if (strcmp(name, creationlist[i]->getname()) == 0)
		{
			return creationlist[i]->getname();
		}
	}
	cout << endl;
}


void Artist::printlist()const
{
	for (int i = 0; i < numofcreations; i++)
	{
		if (strcmp(creationlist[i]->gettype(), "Picture") == 0)
		{
			if (dynamic_cast<Picture*>(creationlist[i]) != NULL)
			{
				dynamic_cast<Picture*>(creationlist[i])->print();
				dynamic_cast<Picture*>(creationlist[i])->printp();
			}
		}
		if (strcmp(creationlist[i]->gettype(), "Statue") == 0)
		{
			if (dynamic_cast<Statue*>(creationlist[i]) != NULL)
			{
				dynamic_cast<Statue*>(creationlist[i])->print();
				dynamic_cast<Statue*>(creationlist[i])->prints();
			}
		}
		if (strcmp(creationlist[i]->gettype(), "Wallstatue") == 0)
		{
			if (dynamic_cast<Wallstatue*>(creationlist[i]) != NULL)
			{
				dynamic_cast<Wallstatue*>(creationlist[i])->print();
			}
		}
	}
	cout << endl;
}



bool Artist::countpictures()const
{
	for (int i = 0; i < numofcreations; i++)
	{
		if (strcmp(creationlist[i]->gettype(), "Picture") == 0)
		{
			return true;
		}
	}
	return false;
}


bool Artist::countstatues()const
{
	for (int i = 0; i < numofcreations; i++)
	{
		if (strcmp(creationlist[i]->gettype(), "Statue") == 0)
		{
			return true;
		}
	}
	return false;
}
