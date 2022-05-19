#pragma once
#include<iostream>
using namespace std;
class Artist;
class Creation
{
private:
	char* name;
	int year;
	char* movment;
	float height;
	Artist* artist;
public:
	Creation();
	Creation(char* name, int year, char* movment, float height, Artist* artist);
	Creation(const Creation& other);
	virtual ~Creation();
	virtual void print()const;
	virtual const char* gettype()const;
	char* getname()const;
	Artist* getartist()const;
	const char* getmovment()const;
};