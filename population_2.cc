#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "population_header.h"
#include "person_header.h"

using namespace std;

//succeptible ?
//sick +
//recovered -

Population::Population()
{
	int people = 10;
	vector<Person> temp(people,Person());
	pops = temp;
};
Population::Population(int npeople)
{
	people = npeople;
	vector<Person> temp(npeople,Person());
	pops = temp;
};

void Population::random_infection()
{
	srand(time(NULL));
	int random = floor(people*(float)(rand()/(float)RAND_MAX));
	pops[random].infect(5);
};

int Population::count_infected()
{
	int count = 0;
	for(int i=0;i<people;i++)
		if(pops[i].get_status() > 0)
			count+=1;
	return count;
};

void Population::update()
{
	for(int i=0;i<people;i++)
		pops[i].update();
};
void Population::printing()
{
	cout << "#sick " << count_infected() << " : ";
	for(int i=0;i<people;i++)
	{
		if(pops[i].get_status()>0)
			cout << "+ ";
		else if(pops[i].get_status() == 0)
			cout << "? ";
		else
			cout << "- ";
	}
	cout << endl;
};

