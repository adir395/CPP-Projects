#include "School.h"

School::School()
{
	numberofworkers = 0;
	w = NULL;
	schoolmanager = false;
}

School::~School()
{
	for (int i = 0; i < numberofworkers; i++)
		delete w[i];
	delete[] w;
}

void School::menu()
{
	int select1, seniority, number_of_subject,weekly_work_hours;
	char select2,name[20],**subject_name,subname[10],name_of_class[3];
	long id;
	bool break_loop = false;
	Worker* a=NULL;
	do
	{
		cout << endl;
		print_menu();
		cin >> select1;
		switch (select1)
		{
		case 1:
			do {
				cout << "Choose type of worker:" << endl;
				cout << "A. Teacher " << endl;
				cout << "B. Temp " << endl;
				cout << "C. Tutor " << endl;
				cout << "D. Deputy " << endl;
				cout << "E. Manager " << endl;
				cout << "F. Secretary " << endl;
				cin >> select2;
				switch (select2)
				{
				case 'A':
					
					cout << "Please enter TEACHER data:" << endl;
					cout << "Name: ";
					cin >> name;
					cout << "Id: ";
					cin >> id;
					for (int j = 0; j < numberofworkers; j++)
						if (w[j]->get_id() == id)
						{
							cout << "This Id is already in use..." << endl;
							break_loop = true;
						}
					if (break_loop == false)
					{
						cout << "Seniority: ";
						cin >> seniority;
						cout << "Number of subjects: ";
						cin >> number_of_subject;
						subject_name = new char* [number_of_subject];
						cout << "Name of subjects: ";
						for (int i = 0; i < number_of_subject; i++)
						{
							cin >> subname;
							subject_name[i] = new char[strlen(subname) + 1];
							strcpy(subject_name[i], subname);
						}
						a = new Teacher(name, id, seniority, number_of_subject, subject_name);
						operator+=(a);
						break;
					}
					break;
				case 'B':
					cout << "Please enter TEMP TEACHER data:" << endl;
					cout << "Name: ";
					cin >> name;
					cout << "Id: ";
					cin >> id;
					for (int j = 0; j < numberofworkers; j++)
						if (w[j]->get_id() == id)
						{
							cout << "This Id is already in use..." << endl;
							break_loop=true;
						}
					if (break_loop == false)
					{
						cout << "Seniority: ";
						cin >> seniority;
						cout << "Number of subjects: ";
						cin >> number_of_subject;
						subject_name = new char* [number_of_subject];
						cout << "Name of subjects: ";
						for (int i = 0; i < number_of_subject; i++)
						{
							cin >> subname;
							subject_name[i] = new char[strlen(subname) + 1];
							strcpy(subject_name[i], subname);
						}
						cout << "Weekly work hours: ";
						cin >> weekly_work_hours;
						a = new Temp(name, id, seniority, number_of_subject, subject_name, weekly_work_hours);
						operator+=(a);
						break;
					}
					break;
				case 'C':
					cout << "Please enter TUTOR data:" << endl;
					cout << "Name: ";
					cin >> name;
					cout << "Id: ";
					cin >> id;
					for (int j = 0; j < numberofworkers; j++)
						if (w[j]->get_id() == id)
						{
							cout << "This Id is already in use..." << endl;
							break_loop = true;
						}
					if (break_loop == false)
					{
						cout << "Seniority: ";
						cin >> seniority;
						cout << "Number of subjects: ";
						cin >> number_of_subject;
						subject_name = new char* [number_of_subject];
						cout << "Name of subjects: ";
						for (int i = 0; i < number_of_subject; i++)
						{
							cin >> subname;
							subject_name[i] = new char[strlen(subname) + 1];
							strcpy(subject_name[i], subname);
						}
						cout << "Name of class: ";
						cin >> name_of_class;
						a = new Tutor(name, id, seniority, number_of_subject, subject_name, name_of_class);
						operator+=(a);
						break;
					}
					break;
				case 'D':
					cout << "Please enter DEPUTY data:" << endl;
					cout << "Name: ";
					cin >> name;
					cout << "Id: ";
					cin >> id;
					for (int j = 0; j < numberofworkers; j++)
						if (w[j]->get_id() == id)
						{
							cout << "This Id is already in use..." << endl;
							break_loop = true;
						}
					if (break_loop == false)
					{
						cout << "Seniority: ";
						cin >> seniority;
						cout << "Number of subjects: ";
						cin >> number_of_subject;
						subject_name = new char* [number_of_subject];
						cout << "Name of subjects: ";
						for (int i = 0; i < number_of_subject; i++)
						{
							cin >> subname;
							subject_name[i] = new char[strlen(subname) + 1];
							strcpy(subject_name[i], subname);
						}
						cout << "Name of class: ";
						cin >> name_of_class;
						a = new Deputy(name, id, seniority, number_of_subject, subject_name, name_of_class);
						operator+=(a);
						break;
					}
					break;
				case 'E':
					if (schoolmanager == true)
					{
						cout << "There is already manager" << endl;
						break;
					}
					if (schoolmanager == false)
					{
						cout << "Please enter MANAGER data:" << endl;
						cout << "Name: ";
						cin >> name;
						cout << "Id: ";
						cin >> id;
						for (int j = 0; j < numberofworkers; j++)
							if (w[j]->get_id() == id)
							{
								cout << "This Id is already in use..." << endl;
								break_loop = true;
							}
						if (break_loop == false)
						{
							schoolmanager = true;
							cout << "Seniority: ";
							cin >> seniority;
							a = new Manager(name, id, seniority);
							operator+=(a);
							break;
						}
					}
					break;
				case 'F':
					cout << "Please enter SECRETARY data:" << endl;
					cout << "Name: ";
					cin >> name;
					cout << "Id: ";
					cin >> id;
					for (int j = 0; j < numberofworkers; j++)
						if (w[j]->get_id() == id)
						{
							cout << "This Id is already in use..." << endl;
							break_loop = true;
						}
					if (break_loop == false)
					{
						cout << "Seniority: ";
						cin >> seniority;
						cout << "Extra hours: ";
						cin >> weekly_work_hours;
						a = new Secretary(name, id, seniority, weekly_work_hours);
						operator+=(a);
						break;
					}
					break;
				default:
					cout << "You enter wrong char" << endl;
					break;
				}

			} while (select2 != 'A' && select2<'B'&& select2 != 'C' && select2 < 'D'&& select2 != 'E' && select2 < 'F');
			break;
		case 2:
			for (int i = 0; i < numberofworkers; i++)
			{
				w[i]->print();
				cout << endl;
			}
			break;
		case 3:
			cout << "Please enter profession: ";
			cin >> subname;
			for (int i = 0; i < numberofworkers; i++)
			{
				if (strcmp(w[i]->get_type(), "Teacher") == 0 || strcmp(w[i]->get_type(), "Temp") == 0 || strcmp(w[i]->get_type(), "Tutor") == 0 || strcmp(w[i]->get_type(), "Deputy") == 0)
					if (dynamic_cast <Teacher*>(w[i]) != NULL)
						dynamic_cast<Teacher*>(w[i])->print_by_sub(subname);
			}
			break;
		case 4:
			for (int i = 0; i < numberofworkers; i++)
				if (strcmp(w[i]->get_type(), "Tutor") == 0 || strcmp(w[i]->get_type(), "Deputy") == 0)
					if (dynamic_cast <Tutor*>(w[i]) != NULL)
						(dynamic_cast<Tutor*>(w[i])->print_tutor());
			break;
		case 5:
			for (int i = 0; i < numberofworkers; i++)
			{
				if (strcmp(w[i]->get_type(), "Manager") == 0)
					if (dynamic_cast <Manager*>(w[i]) != NULL)
						cout <<"Manager name: "<< (dynamic_cast<Manager*>(w[i])->get_name()) << endl;
			}
			for (int i = 0; i < numberofworkers; i++)
			{
				if (strcmp(w[i]->get_type(), "Deputy") == 0)
					if (dynamic_cast <Deputy*>(w[i]) != NULL)
						cout <<"Deputy name: "<< (dynamic_cast<Deputy*>(w[i])->get_name()) << endl;
			}
			break;
		case 6:
			return;

		default:
			cout << "Wrong number, please enter number between 1-10" << endl;
			break;
		}
	} while (select1 >= 0 || select1 <= 0);
}

void School::print_menu()
{
	cout << "1.Add worker " << endl;
	cout << "2.Print workers " << endl;
	cout << "3.Print profession " << endl;
	cout << "4.Print tutors" << endl;
	cout << "5.Print management " << endl;
	cout << "6.Exit" << endl;
}

void School::operator+=(Worker* wo)
{
	if (numberofworkers == 0)
	{
		w = new Worker * [1];
		numberofworkers++;
		w[0] = wo;
	}
	else
	{
		Worker** temp = new Worker * [numberofworkers + 1];
		for (int i = 0; i < numberofworkers; i++)
		{
			temp[i] = w[i];
		}
		temp[numberofworkers] = wo;
		numberofworkers++;
		delete[]w;
		w = temp;
	}
}

