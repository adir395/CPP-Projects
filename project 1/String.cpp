#include "String.h"

void String::SetString(const char* string)
{
	if (name)
	{
		delete[] name;
	}
	if (string)
	{
		int length = strlen(string) + 1;
		name = new char[length];
		strcpy(name, string);
	}

	else
	{
		name = nullptr;
	}
}

void String::operator=(const String& str)
{
	delete[] this->name;
	this->name = new char[strlen(str.name) + 1];
	strcpy(this->name, str.name);
}


String::String()
{
	this->name = nullptr;

}
String::String(char* str)
{
	int length = strlen(str)+1;
	this->name = new char[length];
	strcpy(this->name, str);
}

String::~String()
{
	delete[] name;
}

String::String(const char* str)
{
	delete[] this->name;
	int length = strlen(str) + 1;
	this->name = new char[length];
	strcpy(this->name, str);

}

const void String::PrintStr()
{
	cout << this->name;
}