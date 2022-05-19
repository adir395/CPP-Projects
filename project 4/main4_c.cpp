#include "Set.h"

int main()
{
	int size, *arr_int1 = NULL,*arr_int2=NULL;
	float* arr_fl1=NULL, * arr_fl2 = NULL;
	char* arr_c1 = nullptr, *arr_c2 = nullptr;
	cout << "Please enter size of the first intger array: ";
	cin >> size;
	arr_int1 = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr_int1[i];
	Set<int> s1(arr_int1, size);
	cout << "Please enter size of the second intger array: ";
	cin >> size;
	arr_int2 = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr_int2[i];
	Set<int>s2(arr_int2, size);
	Set<int>s3 = s1 + s2;
	cout << "Union: ";
	s3.print();
	Set<int>s4 = s1 - s2;
	cout << "difference: ";
	s4.print();
	Set<int>s5 = s1 * s2;
	cout << "intersection: ";
	s5.print();
	cout << endl;


	cout << "Please enter size of the first float array: ";
	cin >> size;
	arr_fl1 = new float[size];
	for (int i = 0; i < size; i++)
		cin >> arr_fl1[i];
	Set<float> f1(arr_fl1, size);
	cout << "Please enter size of the second float array: ";
	cin >> size;
	arr_fl2 = new float[size];
	for (int i = 0; i < size; i++)
		cin >> arr_fl2[i];
	Set<float>f2(arr_fl2, size);
	Set<float>f3 = f1 + f2;
	cout << "Union: ";
	f3.print();
	Set<float>f4 = f1 - f2;
	cout << "difference: ";
	f4.print();
	Set<float>f5 = f1 * f2;
	cout << "intersection: ";
	f5.print();
	cout << endl;


	cout << "Please enter size of the first char array: ";
	cin >> size;
	arr_c1 = new char[size];
	for (int i = 0; i < size; i++)
		cin >> arr_c1[i];
	Set<char> c1(arr_c1, size);
	cout << "Please enter size of the second char array: ";
	cin >> size;
	arr_c2 = new char[size];
	for (int i = 0; i < size; i++)
		cin >> arr_c2[i];
	Set<char>c2(arr_c2, size);
	Set<char>c3 = c1 + c2;
	cout << "Union: ";
	c3.print();
	Set<char>c4 = c1 - c2;
	cout << "difference: ";
	c4.print();
	Set<char>c5 = c1 * c2;
	cout << "intersection: ";
	c5.print();
	return 0;
}