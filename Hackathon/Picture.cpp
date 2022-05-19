#include"Picture.h"
Picture::Picture() :Creation()
{
	width = 0;
}


Picture::Picture(char* name, int year, char* movment, float height, Artist* artist, float width) : Creation(name, year, movment, height, artist)
{
	this->width = width;
}


Picture::Picture(const Picture& other) : Creation(other)
{
	width = other.width;
}


Picture::~Picture()
{

}


void Picture::printp()const
{
	cout << "Width: " << width << " CM \n" << endl;
}


const char* Picture::gettype()const
{
	return "Picture";
}