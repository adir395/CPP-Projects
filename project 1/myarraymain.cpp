#include "MyArray.h"

int main()
{
	int sizezero, sizeparameter, index;
	float* newarr, element, a, sum = 0;
	cout << "Enter length of zero_arr: ";
	cin >> sizezero;
	cout << "Enter length of parameters_arr: ";
	cin >> sizeparameter;
	newarr = new float[sizeparameter];
	cout << "Enter elements of parameters_arr: ";
	for (int i = 0; i < sizeparameter; i++)
		cin >> newarr[i];
	MyArray arr1, arr2(sizezero), arr3(newarr, sizeparameter), arr4(arr2);
	arr1.printarr();
	arr2.printarr();
	arr3.printarr();
	arr4.printarr();
	cout << "Enter new length of zero_arr: ";
	cin >> sizezero;
	newarr = new float[sizezero];
	cout << "Enter elements of zero_arr: ";
	for (int i = 0; i < sizezero; i++)
		cin >> newarr[i];
	arr2.allocte(newarr, sizezero);
	cout << "Changing an element in zero_arr: " << endl;
	cout << "Enter index: ";
	cin >> index;
	cout << "Enter element: ";
	cin >> element;
	arr2.change(element, index);
	cout << "Changing an element in parameters_arr: " << endl;
	cout << "Enter index: ";
	cin >> index;
	cout << "Enter element: ";
	cin >> element;
	arr3.change(element, index);
	cout << "Changing an element in copied_arr:" << endl;
	cout << "Enter index: ";
	cin >> index;
	cout << "Enter element: ";
	cin >> element;
	arr4.change(element, index);
	arr1.printarr();
	arr2.printarr();
	arr3.printarr();
	arr4.printarr();
	cout << "Enter index: ";
	cin >> index;
	if (arr1.ret(index, a) == true)
		cout << a << endl;
	if (arr2.ret(index, a) == true)
		cout << a << endl;
	if (arr3.ret(index, a) == true)
		cout << a << endl;
	if (arr4.ret(index, a) == true)
		cout << a << endl;
	cout << "sum= " << arr1.calcarr();
	cout << ", length= " << arr1.countarr() << endl;
	cout << "sum: " << arr2.calcarr();
	cout << ", length= " << arr2.countarr() << endl;
	cout << "sum= " << arr3.calcarr();
	cout << ", length= " << arr3.countarr() << endl;
	cout << "sum= " << arr4.calcarr();
	cout << ", length= " << arr4.countarr() << endl;
	return 0;
}