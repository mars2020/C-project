#ifndef POPULATION_HEADER_H_
#define POPULATION_HEADER_H_
#include <iostream>
#include <string>
#include "person_header.h"
#include <vector>
using namespace std;

class Population
{
	private:
		int people;
		float prob;
	public:
		vector<Person> pops;
		Population();
		Population(int npeople,float probability);
		int count_infected();
		void random_infection();
		void update();
		void printing();
		void innoculation(float per);
		void contagion(float bad_luck);
		void spreading();
};
#endif
