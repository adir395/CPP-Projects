#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

class MyArray
{
private:
	float* arr;
	int size;
public:
	MyArray();/////defult cons
	MyArray(float* arr, int size);///init cons
	MyArray(int size);///get size and fill with 0
	MyArray(const MyArray& arr2);///copy cons
	bool allocte(float* arr, int size);///remove old memory and allocate new
	bool change(float num, int index);///change num in the arr
	bool ret(int index, float& x);///return number from the arr with &
	float calcarr();//return the sum of the arr
	int countarr();//how many number
	void printarr();//print the arr
};

