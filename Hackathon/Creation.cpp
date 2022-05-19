#define _CRT_SECURE_NO_WARNINGS
#include"Creation.h"


Creation::Creation()
{
	name = new char[5];
	strcpy(name, " ");
	year = 0;
	movment = new char[5];
	strcpy(movment, " ");
	height = 0;
	artist = NULL;
}


Creation::Creation(char* name, int year, char* movment, float height, Artist* artist)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->year = year;
	this->movment = new char[strlen(movment) + 1];
	strcpy(this->movment, movment);
	this->height = height;
	this->artist = artist;
}


Creation::Creation(const Creation& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	year = other.year;
	movment = new char[strlen(other.movment) + 1];
	strcpy(movment, other.movment);
	height = other.height;
	artist = other.artist;
}


Creation::~Creation()
{
	delete[]name;
	delete[]movment;
}


void Creation::print()const
{
	cout << "Name: " << name<<endl;
	cout << "Year: " << year<<endl;
	cout << "Movment: " << movment<<endl;
	cout << "Height: " << height << " CM" << endl;
}


const char* Creation::gettype()const
{
	return "Creation";
}


char* Creation::getname()const
{
	return name;
}


Artist* Creation::getartist()const
{
	return artist;
}


const char* Creation::getmovment()const
{
	return movment;
}