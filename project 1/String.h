#ifndef STRING_H
#define STRING_H
#include "Date.h"

class String
{
public:

	void SetString(const char* string);
	const void PrintStr();
	void operator=(const String& str);
	String();
	String(char* str);
	String(const char* str);
	~String();


private:
	char* name;
};



#endif // !STRING_H
