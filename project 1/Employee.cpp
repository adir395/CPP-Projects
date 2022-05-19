#include "Employee.h"


void Employee::printemployee(Date da) 
{
	cout << "First name: ";
	this->FirstName.PrintStr();
	cout << "Last name: ";
	this->lastName.PrintStr();
	cout << "ID: " << this->id;
	cout << "Age: ";
	getAge(da).PrintDate();
	cout << "seniority" << endl;
	getSeniority(da).PrintDate();
	cout << "Salary: " << this->salary;
	cout << "Status :" << endl;
	printSatus();

}


Date Employee::getSeniority( Date d)
{
	return d.CalcDiff(this->JoinCompany);
}

Employee::Employee() :id(0), BirthDay(), JoinCompany()
{
	this->FirstName = "/0";
	this->lastName = "/0";
	this->salary = 0;
	this->status = SECRETARY;
}

Employee::~Employee()
{
}

Employee::Employee(String firstname, String lastname, const Date birthday, const int id, const Date joinCompany, double salary,int status):id(id),BirthDay(birthday),JoinCompany(joinCompany)
{
	this->FirstName = firstname ;
	this->lastName = lastname;
	this->salary = salary;
	this->status = Status(status);
}

Date Employee::getAge( Date d)
{

	return d.CalcDiff(this->BirthDay);
}

void Employee::printSatus()
{
	switch (this->status)
	{
	case 0:
	{
		cout << "SECRETARY" << endl;
	}
	case 1:
	{
		cout << "EMPLOYED" << endl;
	}
	case 2:
	{
		cout << "MANAGER" << endl;
	}
	case 3:
	{
		cout << "DIRECTOR" << endl;
	}
	default:
		break;
	}
}

void Employee::promotion()
{
	switch (this->status)
	{
	case 0:
	{
		this->status = EMPLOYED;
	}
	case 1:
	{
		this->status = MANAGER;
	}
	case 2:
	{
		this->status = DIRECTOR;
	}
	case 3:
	{
		this->salary *= 2;
	}
	default:
		break;
	}
	this->salary *= 1.1;
}

Employee::Employee(const Employee& empl):id(empl.id),BirthDay(empl.BirthDay),JoinCompany(empl.JoinCompany)
{
	this->FirstName = empl.FirstName;
	this->lastName = empl.lastName;
	this->salary = empl.salary;
	this->status = empl.status;

}



//
//const void Employee::SetAge(const Date d)
//{
//	this->BirthDay(d);
//
//}

