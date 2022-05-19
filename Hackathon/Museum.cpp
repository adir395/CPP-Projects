#define _CRT_SECURE_NO_WARNINGS
#include"Museum.h"
Museum::Museum()
{
	artistlist = NULL;
	creationlist = NULL;
	numofartist = 0;
	numofcreation = 0;
}


Museum::~Museum()
{
	for (int i = 0; i < numofartist; i++)
	{
		delete artistlist[i];
	}
	delete[]artistlist;
	delete[]creationlist;
}


void Museum::addartist(Artist* newartist)
{
	if (numofartist == 0)
	{
		artistlist = new Artist * [1];
		artistlist[0] = newartist;
		numofartist++;
		cout << "artist added\n" << endl;
	}
	else
	{
		Artist** temp = new Artist * [numofartist + 1];
		for (int i = 0; i < numofartist; i++)
		{
			temp[i] = artistlist[i];
		}
		temp[numofartist] = newartist;
		numofartist++;
		delete[]artistlist;
		artistlist = temp;
		cout << "artist added\n" << endl;
	}
}


void Museum::addcreation(Creation* newcreation, int index)
{
	if (numofcreation == 0)
	{
		creationlist = new Creation * [1];
		creationlist[0] = newcreation;
		numofcreation++;
		artistlist[index]->addcreation(newcreation);
	}
	else
	{
		Creation** temp = new Creation * [numofcreation + 1];
		for (int i = 0; i < numofcreation; i++)
		{
			temp[i] = creationlist[i];
		}
		temp[numofcreation] = newcreation;
		numofcreation++;
		delete[]creationlist;
		creationlist = temp;
		artistlist[index]->addcreation(newcreation);
	}
}


Artist* Museum::returnartist(char* name)const
{
	for (int i = 0; i < numofartist; i++)
	{
		if (strcmp(name, artistlist[i]->getname()) == 0)
		{
			return artistlist[i];
		}
	}
	return NULL;
}


void Museum::printallartist()const
{
	for (int i = 0; i < numofartist; i++)
	{
		if (artistlist[i]->getnumofcreation() >= 1)
		{
			cout << artistlist[i];
		}
	}
}


void Museum::deletecreation(int index)
{
	if (numofcreation == 0)
	{
		cout << "There is nothing to delete" << endl;
	}
	else
	{
		char* name = creationlist[index]->getname();
		creationlist[index]->getartist()->deletecreation(name);
		if (numofcreation == 0)
		{
			cout << "There nothing to delete\n" << endl;
		}
		else
		{
			Creation** temp = new Creation * [numofcreation - 1];
			if (index == 0)
			{
				int k = 0;
				for (int i = 1; i < numofcreation; i++)
				{
					temp[k] = creationlist[i];
					k++;
				}
			}
			else if (index = numofcreation - 1)
			{
				for (int i = 0; i < numofcreation - 1; i++)
				{
					temp[i] = creationlist[i];
				}
			}
			else
			{
				int k = index;
				for (int i = 0; i < index; i++)
				{
					temp[i] = creationlist[i];
				}
				for (int i = index + 1; i < numofcreation; i++)
				{
					temp[k] = creationlist[i];
					k++;
				}
			}
			delete[]creationlist;
			creationlist = temp;
			numofcreation--;
		}
	}
}


void Museum::printbyweight(float weight)const
{
	int counter = 0;
	for (int i = 0; i < numofcreation; i++)
	{
		if (strcmp(creationlist[i]->gettype(), "Statue") == 0 || strcmp(creationlist[i]->gettype(), "Wallstatue") == 0)
		{
			if (dynamic_cast<Statue*>(creationlist[i]) != NULL)
			{
				if (dynamic_cast<Statue*>(creationlist[i])->getweight() >= weight)
				{
					counter++;
				}
			}
		}
	}
	if (counter == 0)
	{
		cout << "There is no creations with that kind of weight" << endl;
	}
	else
	{
		for (int i = 0; i < numofcreation; i++)
		{
			if (strcmp(creationlist[i]->gettype(), "Statue") == 0)
			{
				if (dynamic_cast<Statue*>(creationlist[i]) != NULL)
				{
					if (dynamic_cast<Statue*>(creationlist[i])->getweight() >= weight)
					{
						dynamic_cast<Statue*>(creationlist[i])->print();
						dynamic_cast<Statue*>(creationlist[i])->prints();
					}
				}
			}
			if (strcmp(creationlist[i]->gettype(), "Wallstatue") == 0)
			{
				if (dynamic_cast<Wallstatue*>(creationlist[i]) != NULL)
				{
					if (dynamic_cast<Wallstatue*>(creationlist[i])->getweight() >= weight)
					{
						dynamic_cast<Wallstatue*>(creationlist[i])->print();
					}
				}
			}
		}
	}
}


int Museum::menu()
{
	int num = 50, day, month, year, num2 = 50, index = 0, numofbolts;
	char name[20], movment[20], name2[20], name3[20];
	float height, width, area, weight;
	while (num != 0)
	{
		cout << "Please choose and option." << endl;
		cout << "1.Add artist." << endl;
		cout << "2.Add creation" << endl;
		cout << "3.Delete creation" << endl;
		cout << "4.Print artists with at least one creation." << endl;
		cout << "5.Print all creations" << endl;
		cout << "6.Print all pictures" << endl;
		cout << "7.Print all statues" << endl;
		cout << "8.Print specific artist works" << endl;
		cout << "9.Print creations by movment" << endl;
		cout << "10.Print artist who have pictures" << endl;
		cout << "11.Print artist who have statues" << endl;
		cout << "12.Print statue by weight" << endl;
		cout << "13.Exit\n" << endl;
		cin >> num;
		cout << endl;


		if (num == 1)
		{
			cout << "Please enter a name: ";
			cin >> name;
			cout << "Please enter date of birth: "<<endl;
			cout << "Day: ";
			cin >> day;
			cout << "Month: ";
			cin >> month;
			cout << "Year: ";
			cin >> year;
			Date born(day, month, year);
			cout << "Please enter date of death:" << endl;
			cout << "Day: ";
			cin >> day;
			cout << "Month: ";
			cin >> month;
			cout << "Year: ";
			cin >> year;
			cout << endl;
			Date death(day, month, year);
			Artist* newartist = new Artist(name, born, death);
			addartist(newartist);
		}


		if (num == 2)
		{
			if (numofartist == 0)
			{
				cout << "Add an artist first" << endl;
			}
			else
			{
				cout << "choose and creation" << endl;
				cout << "1.Picture" << endl;
				cout << "2.Statue" << endl;
				cout << "3.Wall statue" << endl;
				cin >> num2;
				if (num2 == 1)
				{
					cout << "Enter creation name: ";
					cin >> name2;
					cout << "Enter year of the creation: ";
					cin >> year;
					cout << "Enter the movment of the creation: ";
					cin >> movment;
					cout << "Enter the height of the picture: ";
					cin >> height;
					cout << "Enter the width of the picture: ";
					cin >> width;
					cout << "Enter a name of the artist: ";
					cin >> name3;
					Artist* pointer = returnartist(name3);
					if (pointer != NULL)
					{
						Creation* newcreation = new Picture(name2, year, movment, height, pointer, width);
						for (int i = 0; i < numofartist; i++)
						{
							if (pointer == artistlist[i])
							{
								index = i;
							}
						}
						addcreation(newcreation, index);
					}
					else
					{
						cout << "The artist doesnt exists" << endl;
					}
				}
				if (num2 == 2)
				{
					cout << "Enter creation name: ";
					cin >> name2;
					cout << "Enter year of the creation: ";
					cin >> year;
					cout << "Enter the movment of the creation: ";
					cin >> movment;
					cout << "Enter the height of the creation: ";
					cin >> height;
					cout << "Enter the area of the creation: ";
					cin >> area;
					cout << "Enter the weight of the creation: ";
					cin >> weight;
					cout << "Enter a name of the artist: ";
					cin >> name3;
					Artist* pointer = returnartist(name3);
					if (pointer != NULL)
					{
						Creation* newcreation = new Statue(name2, year, movment, height, pointer, weight, area);
						for (int i = 0; i < numofartist; i++)
						{
							if (pointer == artistlist[i])
							{
								index = i;
							}
						}
						addcreation(newcreation, index);
					}
					else
					{
						cout << "The artist doesnt exists" << endl;
					}
				}
				if (num2 == 3)
				{
					cout << "Enter creation name: ";
					cin >> name2;
					cout << "Enter year of the creation: ";
					cin >> year;
					cout << "Enter the movment of the creation: ";
					cin >> movment;
					cout << "Enter the height of the creation: ";
					cin >> height;
					cout << "Enter the area of the creation: ";
					cin >> area;
					cout << "Enter the weight of the creation: ";
					cin >> weight;
					cout << "Enter the width of the creation: ";
					cin >> width;
					cout << "Enter number of bolts for the creation: ";
					cin >> numofbolts;
					cout << "Enter a name of the artist: ";
					cin >> name3;
					Artist* pointer = returnartist(name3);
					if (pointer != NULL)
					{
						Creation* newcreation = new Wallstatue(name2, year, movment, height, pointer, weight, area, width, numofbolts);
						for (int i = 0; i < numofartist; i++)
						{
							if (pointer == artistlist[i])
							{
								index = i;
							}
						}
						addcreation(newcreation, index);
					}
					else
					{
						cout << "The artist doesnt exists" << endl;
					}
				}
			}
		}


		if (num == 3)
		{
			if (numofartist == 0)
			{
				cout << "No artits exsist, cant delete creation..." << endl;
			}
			else
			{
				cout << "Enter an index: ";
				cin >> index;
				deletecreation(index);
			}
		}


		if (num == 4)
		{
			if (numofartist == 0)
			{
				cout << "No artits exsist, cant print..." << endl;
			}
			else
			{
				cout << "Artist list: " << endl;
				for (int i = 0; i < numofartist; i++)
				{
					if (artistlist[i]->getnumofcreation() >= 1)
					{
						cout << artistlist[i][0] << endl;
					}
					cout << endl;
				}
			}
			cout << endl;
		}


		if (num == 5)
		{
			if (numofcreation == 0)
			{
				cout << "Please add creations" << endl;
			}
			else
			{
				for (int i = 0; i < numofcreation; i++)
				{
					if (strcmp(creationlist[i]->gettype(), "Picture") == 0)
					{
						if (dynamic_cast<Picture*>(creationlist[i]) != NULL)
						{
							dynamic_cast<Picture*>(creationlist[i])->print();
							dynamic_cast<Picture*>(creationlist[i])->printp();
							cout << endl;
						}
					}
					if (strcmp(creationlist[i]->gettype(), "Statue") == 0)
					{
						if (dynamic_cast<Statue*>(creationlist[i]) != NULL)
						{
							dynamic_cast<Statue*>(creationlist[i])->print();
							dynamic_cast<Statue*>(creationlist[i])->prints();
							cout << endl;
						}
					}
					if (strcmp(creationlist[i]->gettype(), "Wallstatue") == 0)
					{
						if (dynamic_cast<Wallstatue*>(creationlist[i]) != NULL)
						{
							dynamic_cast<Wallstatue*>(creationlist[i])->print();
							cout << endl;
						}
					}
				}
			}
		}


		if (num == 6)
		{
			int counter = 0;

			cout << "All pictures" << endl;
			for (int i = 0; i < numofcreation; i++)
			{
				if (strcmp(creationlist[i]->gettype(), "Picture") == 0)
				{
					if (dynamic_cast<Picture*>(creationlist[i]) != NULL)
					{
						dynamic_cast<Picture*>(creationlist[i])->print();
						dynamic_cast<Picture*>(creationlist[i])->printp();
						cout << endl;
						counter++;
					}
					cout << endl;
				}
			}
			if (counter == 0)
			{
				cout << "No pictures in the museum" << endl;
			}
			cout << endl;
		}


		if (num == 7)
		{
			int counter = 0;
			cout << "All statues" << endl;
			for (int i = 0; i < numofcreation; i++)
			{
				if (strcmp(creationlist[i]->gettype(), "Statue") == 0)
				{
					if (dynamic_cast<Statue*>(creationlist[i]) != NULL)
					{
						dynamic_cast<Statue*>(creationlist[i])->print();
						dynamic_cast<Statue*>(creationlist[i])->prints();
						cout << endl;
						counter++;
					}
					cout << endl;
				}
			}
			if (counter == 0)
			{
				cout << "No statues in the museum" << endl;
			}
			cout << endl;
		}


		if (num == 8)
		{
			char name[20];
			int index = 0;
			cout << "Enter a name of an artist: ";
			cin >> name;
			
			cout << "Artist list of creations" << endl;
			for (int i = 0; i < numofartist; i++)
			{
				if (strcmp(name, artistlist[i]->getname()) == 0)
				{
					if (artistlist[i]->getnumofcreation() > 0)
					{
						artistlist[i]->printlist();
						cout << endl;
					}
					else
					{
						cout << "This artist doesnt have any creations" << endl;
					}
				}
			}
			cout << endl;
		}


		if (num == 9)
		{
			char movment[20];
			int counter = 0;
			cout << "Enter a movment: ";
			cin >> movment;
			cout << "List of creation from a similar movment: " << endl;
			for (int i = 0; i < numofcreation; i++)
			{
				if (strcmp(creationlist[i]->getmovment(), movment) == 0)
				{
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "There is no creations from that movment" << endl;
			}
			else
			{
				for (int i = 0; i < numofcreation; i++)
				{
					if (strcmp(creationlist[i]->getmovment(), movment) == 0)
					{
						cout << creationlist[i]->getname();
					}
				}
			}
			cout << endl;
		}


		if (num == 10)
		{
			cout << "Artist list who have pictures: " << endl;
			int counter = 0;
			for (int i = 0; i < numofartist; i++)
			{
				if (artistlist[i]->countpictures() == true)
				{
					cout << artistlist[i]->getname() << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "There is no artist with pictuers" << endl;
			}
			cout << endl;
		}


		if (num == 11)
		{
			int counter = 0;
			cout << "Artist list who have statues: " << endl;
			for (int i = 0; i < numofartist; i++)
			{
				if (artistlist[i]->countstatues() == true)
				{
					cout << artistlist[i]->getname() << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "There is no artist with statues" << endl;
			}
			cout << endl;
		}


		if (num == 12)
		{
			float weight = 0;
			cout << "Enter a weight: ";
			cin >> weight;
			printbyweight(weight);
			cout << endl;
		}


		if (num == 13)
		{
			cout << "Have a nice day" << endl;
			num = 0;
		}
	}
	return 0;
}