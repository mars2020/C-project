#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
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
	prob = .5;
};
Population::Population(int npeople,float probability)
{
	people = npeople;
	vector<Person> temp(npeople,Person());
	pops = temp;
	prob = probability;
};

void Population::random_infection()
{
	srand(time(NULL));
	int random = rand()%people;
	while(pops[random].get_status()==-2)
		random = rand()%people;
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

int Population::total_infected()
{
	int total=0;
	for(int i=0;i<people;i++)
		if(pops[i].is_stable())
			total+=1;
	return total;
};

void Population::update()
{
	for(int i=0;i<people;i++)
		pops[i].update();
};

void Population::printing()
{
	cout << setw(3) << "#sick " << setw(3) << count_infected() << " : ";
	for(int i=0;i<people;i++)
	{
		if(pops[i].get_status()>0)
			cout << "+";
		else if(pops[i].get_status() == 0)
			cout << "?";
		else if(pops[i].get_status()==-1)
			cout << "-";
		else
			cout << "*";
	}
	cout << endl;
};

void Population::spreading()
{
	srand(time(NULL));
 	vector<int> sick(0);
	for(int i=0;i<people;i++)
	{
		if(pops[i].get_status()>0)
		{
			for(int contact=0;contact<6;contact++)
			{
				float bad_luck = (float)rand()/(float)RAND_MAX;
				if(bad_luck < prob)
				{
					int random = rand()%people;
					while(i==random)
					{
						random = rand()%people;
					}
					sick.push_back(random);
				}
			}	
		}
	}
	for(int k=0;k<sick.size();k++)
	{
		if(pops[sick[k]].get_status()==0)
		{
			pops[sick[k]].infect(5);
		}
	}
};

void Population::innoculation(float per)
{
	srand(time(NULL));
	int count =0;
	int per_innoculated = ceil(people*per);
	while(count < per_innoculated)
	{
		int random = floor(people*(float)rand()/(float)RAND_MAX);
		pops[random] = -2;
		count +=1;
	}
};

