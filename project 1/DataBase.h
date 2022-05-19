#ifndef DATA_BASE
#define DATA_BASE
#include "Employee.h"
#include "Date.h"
class DataBase
{


private:

	class Node {
	private:
		Employee* employee;
		Node* next;

	public:
		Node()
		{
			this->employee = NULL;
			this->next = NULL;
		}
		Node(Employee* e, Node* n)
		{
			this->employee = e;
			this->next = n;
		}
		~Node(){}
		Employee* getEmployee() { return this->employee; }
		Node* getNode() { return this->next; }
		void setEmployee(Employee* e)
		{
			this->employee = e;
		}
		void setNext(Node* n)
		{
			this->next = n;
		}


	};
    int numberOfEmployee;
	Node* list;

public:
	DataBase();
	DataBase(int num, Node* node);
	~DataBase();
	void addNewEmployee(Employee newEmp);
	Employee* getEmployee(int index);
	void removeEmployye(int index);
	//Employee* getEmployee(int index);
	void printAll(Date d);
};

#endif // !DATA_BASE
