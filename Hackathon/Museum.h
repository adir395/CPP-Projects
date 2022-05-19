#pragma once
#include "Artist.h"
class Museum
{
private:
	Artist** artistlist;
	Creation** creationlist;
	int numofartist;
	int numofcreation;
public:
	Museum();
	~Museum();
	void addartist(Artist* newartist);
	void addcreation(Creation* newcreation, int index);
	void deletecreation(int index);
	void printallartist()const;
	int menu();
	Artist* returnartist(char* name)const;
	void printbyweight(float weight)const;
};