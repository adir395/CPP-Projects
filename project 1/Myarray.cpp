#include "MyArray.h"

MyArray::MyArray()///defult con
{
	arr = nullptr;
	size = 0;
}

MyArray::MyArray(float* arr, int size)//init con
{
	this->arr = new float[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = arr[i];
	this->size = size;
}

MyArray::MyArray(int size)
{
	arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
	this->size = size;
}

MyArray::MyArray(const MyArray& arr2)//copy cons
{
	this->size = arr2.size;
	this->arr = new float[arr2.size];
	for (int i = 0; i < arr2.size; i++)
		this->arr[i] = arr2.arr[i];
}

bool MyArray::allocte(float* arr, int size)
{
	delete[] this->arr;
	this->arr = new float[size];
	this->size = size;
	if (arr != 0)
	{
		for (int i = 0; i < size; i++)
			this->arr[i] = arr[i];
		return true;
	}
	else
		return false;
}

bool MyArray::change(float num, int index)
{
	if (index > size || index < 0)
	{
		cout << "Bad index" << endl;
		return false;
	}
	else
	{
		arr[index] = num;
		cout << "Changed" << endl;
		return true;
	}
}

bool MyArray::ret(int index, float& x)
{
	if (index > size)
	{
		cout << "Bad index" << endl;
		return false;
	}
	else
	{
		x = arr[index];
		return true;
	}
}

void MyArray::printarr()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

float MyArray::calcarr()
{
	float sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}

int MyArray::countarr()
{
	return size;
}
