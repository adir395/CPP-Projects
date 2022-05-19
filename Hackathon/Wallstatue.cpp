#include"Wallstatue.h"
Wallstatue::Wallstatue() :Creation(), Statue(), Picture()
{
	numofbolts = 0;
}
Wallstatue::Wallstatue(char* name, int year, char* movment, float height, Artist* artist, float weight, float area, float width, int numofbolts) : Creation(name, year, movment, height, artist), Statue(name, year, movment, height, artist, weight, area), Picture(name, year, movment, height, artist, width)
{
	this->numofbolts = numofbolts;
}
Wallstatue::Wallstatue(const Wallstatue& other) : Statue(other), Picture(other)
{
	numofbolts = other.numofbolts;
}
Wallstatue::~Wallstatue()
{

}
void Wallstatue::print()const
{
	Creation::print();
	Statue::prints();
	Picture::printp();
	cout << "Number of bolts: " << numofbolts << endl;
	cout << endl;
}


const char* Wallstatue::gettype()const
{
	return "Wallstatue";
}