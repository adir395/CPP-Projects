#pragma once
#include"Creation.h"
class Picture :virtual public Creation
{
private:
	float width;
public:
	Picture();
	Picture(char* name, int year, char* movment, float height, Artist* artist, float width);
	Picture(const Picture& other);
	virtual ~Picture();
	//void print()const;
	void printp()const;
	virtual const char* gettype()const;
};