#include"Statue.h"
Statue::Statue() :Creation()
{
	weight = 0;
	area = 0;
}
Statue::Statue(char* name, int year, char* movment, float height, Artist* artist, float weight, float area) : Creation(name, year, movment, height, artist)
{
	this->area = area;
	this->weight = weight;
}
Statue::Statue(const Statue& other) : Creation(other)
{
	weight = other.weight;
	area = other.area;
}

Statue::~Statue()
{

}

//void Statue::print()const
//{
//	Creation::print();
//}
void Statue::prints()const
{
	cout << "Area: " << area << " CM " << endl;
	cout << "weight: " << weight << " KG " << endl;
}


const char* Statue::gettype()const
{
	return "Statue";
}


float Statue::getweight()const
{
	return weight;
}