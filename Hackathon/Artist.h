#pragma once
#include"Date.h"
#include "Wallstatue.h"
class Artist
{
private:
	char* name;
	Date born;
	Date death;
	Creation** creationlist;
	int numofcreations;
public:
	Artist();
	Artist(char* name, Date born, Date death);
	Artist(const Artist& other);
	~Artist();
	void addcreation(Creation* creation);
	friend ostream& operator<<(ostream& os, const Artist& other);
	void operator=(const Artist& other);
	bool operator==(const Artist& other)const;
	int getnumofcreation()const;
	const char* getname()const;
	void deletecreation(char* name);
	const char* getcrationname(char* name)const;
	void printlist()const;
	bool countpictures()const;
	bool countstatues()const;

};