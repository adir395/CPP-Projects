#include "Worker.h"

int main()
{
	char name[15];
	long id;
	double hoursalary;
	int workhour;
	int extrahour;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter salary per hour: ";
	cin >> hoursalary;
	cout << "Enter number of regular hours: ";
	cin >> workhour;
	cout << "Enter number of extra hours: ";
	cin >> extrahour;
	Worker w1(name, id, hoursalary, workhour, extrahour);
	cout << "Salary is " << w1.payment() << endl;
	cout << "Update regular hours: ";
	cin >> workhour;
	w1.setworkhour(workhour);
	w1.printworker();
	cout << "Update extra hours: ";
	cin >> extrahour;
	w1.setextrahour(extrahour);
	w1.printworker();
	cout << "Update salary per hour: ";
	cin >> hoursalary;
	w1.sethoursalary(hoursalary);
	w1.printworker();
	return 0;
}