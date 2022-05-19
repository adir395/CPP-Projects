#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "String.h"
typedef enum
{
	SECRETARY, EMPLOYED, MANAGER, DIRECTOR
}Status;
class Employee
{
public:
	void printemployee(Date da);
	Date getSeniority( Date d);
	Employee();
	~Employee();
	Employee(const Employee& empl);
	Employee(String firstname, String lastname, const Date birthday, const int id, const Date JoinCompany, double salary,int status);
	Date getAge( Date d);
	void printSatus();
	void promotion();

	

private:
	String FirstName, lastName;
	const Date BirthDay;
	const int id;
	const Date JoinCompany;
	double salary;
	Status status;
};

#endif // !EMPLOYEE_H
