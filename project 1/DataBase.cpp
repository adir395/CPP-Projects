#include "DataBase.h"

DataBase::DataBase()
{
	this->numberOfEmployee = 0;
	this->list = NULL;
}

DataBase::DataBase(int num, Node* node)
{
	this->numberOfEmployee = num;
	this->list = node;
}

DataBase::~DataBase()
{
	delete[] list;
}

void DataBase::addNewEmployee(Employee newE)
{
	Employee* newEmp = new Employee(newE);
	Node* newNode = new Node(newEmp, NULL);
	if (this->list == NULL)
		this->list = newNode;
	else
	{
		this->list->setNext(newNode);

	}
	this->numberOfEmployee++;
}

Employee* DataBase::getEmployee(int index)
{
	if (index > this->numberOfEmployee)
		return NULL;
	Node* indexNode = this->list;
	while (index > 0)
	{
		indexNode = indexNode->getNode();
		index--;
	}
	return indexNode->getEmployee();

}
void DataBase::removeEmployye(int index)
{
	Employee* tempe = NULL;
	Node* tempn = NULL;
	if (index > this->numberOfEmployee)
		return;

}
//Employee* DataBase::getEmployee(int index)
//{
//
//}
void DataBase::printAll(Date d)
{
	for (int i = 0; i < numberOfEmployee; i++)
	{
		
	}
}