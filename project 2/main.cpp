#include "Student.h"
#include "Worker.h"

int Student::static_numofcourses = 0;
float Student::allaverage = 0;
int Worker::numofworkers = 0;
float Worker::sumofsalary = 0;

void find( Student** s, int size_s,  Worker** w, int size_w, char* find_id);
int best( Student** s, int size_s);
int rich( Worker** w, int size_w);
void print_menu();

int main()
{
	Student** students = NULL;
	Worker** workers = NULL;
	int student_size, workers_size, select=0,index,grade;
	float salary;
	char tempname[20], tempid[9];
	char *name, *id;
	cout << "Please enter how many students: ";
	cin >> student_size;
	students = new Student * [student_size];
	for (int i = 0; i < student_size; i++)
	{
		cout << "Enter name: ";
		cin >> tempname;
		name = new char[strlen(tempname) + 1];
		strcpy(name, tempname);
		cout << "Enter id: ";
		cin >> tempid;
		id = new char[strlen(tempid) + 1];
		strcpy(id, tempid);
		students[i] = new Student(name, id);
	}
	cout << "Please enter how many workers: ";
	cin >> workers_size;
	workers = new Worker * [workers_size];
	for (int i = 0; i < workers_size; i++)
	{
		cout << "Enter name: ";
		cin >> tempname;
		name = new char[strlen(tempname) + 1];
		strcpy(name, tempname);
		cout << "Enter id: ";
		cin >> tempid;
		id = new char[strlen(tempid) + 1];
		strcpy(id, tempid);
		cout << "Enter a salary: ";
		cin >> salary;
		workers[i] = new Worker(name, id,salary);
	}

	do
	{
		cout << endl;
		print_menu();
		cin >> select;
		switch (select)
		{
		case 1:
			for (int i = 0; i < student_size; i++)
				cout << students[i][0]<<endl;
			for (int i = 0; i < workers_size; i++)
				cout << workers[i][0]<<endl;
			break;
		case 2: 
			cout << "Enter index: ";
			cin >> index;
			while (index >= student_size)
			{
				cout << "Wrong index" << endl;
				cout << "Enter index: ";
				cin >> index;
			}
			cout << "Add grade: ";
			cin >> grade;
			while (grade<0||grade>100)
			{
				cout << "Wrong grade,please enter grade between 0-100" << endl;
				cout << "Add grade: ";
				cin >> grade;
			}
			students[index][0] += grade;
			break;
		case 3:
			cout << "Student with the highest average:"<<endl;
			index = best(students, student_size);
			cout << students[index][0]<<endl;
			break;
		case 4:
			cout<<Student::calcaverages_static()<<endl;
			break;
		case 5:
			cout << "Enter index: ";
			cin >> index;
			while (index>=workers_size)
			{
				cout << "Wrong index" << endl;
				cout << "Enter index: ";
				cin >> index;
			}
			cout << "Enter how many to add:  ";
			cin >> salary;
			workers[index][0] += salary;
			break;
		case 6:
			cout << "Enter index: ";
			cin >> index;
			while (index >= workers_size)
			{
				cout << "Wrong index" << endl;
				cout << "Enter index: ";
				cin >> index;
			}
			cout << "Enter Percentage: ";
			cin >> salary;
			workers[index][0] *= salary;
			break;
		case 7:
			index = rich(workers, workers_size);
			cout << workers[index][0]<<endl;
			break;
		case 8:
			cout << Worker::calcaveragesalary()<<endl;
			break;
		case 9:
			cout << "Please enter id: ";
			cin >> tempid;
			id = new char[strlen(tempid) + 1];
			strcpy(id, tempid);
			find(students, student_size, workers, workers_size, id);
			break;
		case 10:
			if (students != NULL)
			{
				for (int i = 0; i < student_size; i++)
					delete students[i];
				delete[]students;
			}
			if (workers != NULL)
			{
				for (int i = 0; i < workers_size; i++)
					delete workers[i];
				delete[] workers;
			}
			cout << "Exit" << endl;
			return 0;
		default:
			cout << "Wrong number, please enter number between 1-10" << endl;
			break;
		}	
	} while (select>=0||select<=0);
}

void find(Student** s, int size_s,Worker** w, int size_w, char* find_id) 
{
	for (int i = 0; i < size_s; i++)
	{
		for (int j = 0; j < size_w; j++)
		{
			if ((strcmp(find_id, s[i]->id) == 0) && strcmp(find_id, w[j]->id) == 0)
			{
				cout << s[i][0]<<endl;
				cout << w[j][0]<<endl;
				return;
			}
		}
	 }
	for (int i = 0; i < size_s; i++)
	{
		if (strcmp(s[i][0].id, find_id) == 0)
		{
			cout << s[i][0] << endl;
			return;
		}
	}
	for (int i = 0; i < size_w; i++)
	{
		if (strcmp(w[i][0].id, find_id) == 0)
		{
			cout << w[i][0] << endl;
			return;
		}
	}
	cout << "No person with this ID was found" << endl;
}

int best(Student** s, int size_s)
{
	int i, j=0;
	float temp = s[0]->average();
	for (i = 1; i < size_s; i++)
	{
		if (temp < s[i]->average())
		{
			temp = s[i]->average();
			j = i;
		}
	}
	return j;
}

int rich(Worker** w, int size_w)
{
	int i,j=0;
	float temp = w[0]->getsalary();
	for (i = 1; i < size_w; i++)
	{
		if (w[i]->getsalary() > temp)
		{
			temp = w[i]->getsalary();
			j = i;
		}
	}
	return j;
}

void print_menu()
{
	cout << "1. Print all Student and Workers " << endl;
	cout << "2. Add grade to student " << endl;
	cout << "3. Student with the highest average" << endl;
	cout << "4. All students average" << endl;
	cout << "5. Add salary to worker with number " << endl;
	cout << "6. Change salary to worker with Percentage" << endl;
	cout << "7. Worker with the highest salary" << endl;
	cout << "8. All average salary" << endl;
	cout << "9. Print person by id" << endl;
	cout << "10. End program" << endl;
}


