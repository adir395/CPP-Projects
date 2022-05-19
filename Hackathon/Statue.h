#pragma once
#include"Creation.h"
class Statue :virtual public Creation
{
private:
	float weight, area;
public:
	Statue();
	Statue(char* name, int year, char* movment, float height, Artist* artist, float weight, float area);
	Statue(const Statue& other);
	virtual ~Statue();
	//void print()const;
	void prints()const;
	virtual const char* gettype()const;
	float getweight()const;
};