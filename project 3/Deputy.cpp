#include "Deputy.h"

Deputy::Deputy():Tutor()
{
}

Deputy::Deputy(const char* name, long id, int seniority, int numberofsubjects, char** nameofsubjects, char nameofclass[3]) : Tutor(name, id, seniority, numberofsubjects, nameofsubjects,nameofclass)
{
}

Deputy::Deputy(const Deputy& d):Tutor(d)
{
}

Deputy::~Deputy()
{
}


float Deputy::calc_salary()const
{
    float salary=Tutor::calc_salary()+2500;
    return salary;
}

void Deputy::print() const
{
    Tutor::print();
    cout << endl;
}

const char* Deputy::get_type() const
{
    return "Deputy";
}

const char* Deputy::get_name() const
{
    return name;
}

void Deputy::print_tutor() const
{
    Tutor::print_tutor();
}
