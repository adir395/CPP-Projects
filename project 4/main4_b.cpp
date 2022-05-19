#include <iostream>
using namespace std;
#pragma warning(disable:4996)

template <class T>

T* remove(const T* arr, int *size, T val)
{
	int j = 0, new_size = 0;
	for (int i = 0; i < *(size); i++)
	{
		if (arr[i] == val)
			continue;
		new_size++;
	}
	*(size) = new_size;
	T* new_arr = new T[new_size];
	if (new_arr == NULL)
		return NULL;

	for (int i = 0; i <= *(size); i++)
	{
		if (arr[i] == val)
			continue;
		new_arr[j] = arr[i];
		j++;
	}
	return new_arr;
}

int main()
{
	float* arr_float = NULL,c_f;
	long* arr_long = NULL,c_l;
	int size_float, size_long;
	cout << "Please enter size of the float array: " << endl;
	cin >> size_float;
	arr_float = new float[size_float];
	if (arr_float == NULL)
		return 0;
	cout << "Enter the float array: " << endl;
	for (int i = 0; i < size_float; i++)
		cin >> arr_float[i];
	cout << endl;
	cout << "Enter a number that you want to remove: ";
	cin >> c_f;
	float* arr_f=remove(arr_float, &size_float,c_f);
	for (int i = 0; i < size_float; i++)
		cout<< arr_f[i]<<" ";
	cout << endl;
	cout << "Please enter size of the long array: " << endl;
	cin >> size_long;
	arr_long = new long[size_long];
	if (arr_long == NULL)
		return 0;
	cout << "Enter the long array: " << endl;
	for (int i = 0; i < size_long; i++)
		cin >> arr_long[i];
	cout << endl;
	cout << "Enter a number that you want to remove: ";
	cin >> c_l;
	long* arr_l=remove(arr_long, &size_long, c_l);
	for (int i = 0; i < size_long; i++)
		cout << arr_l[i] << " ";
	return 0;
}

