#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <ctime>
#include "person_header.h"
#include "population_header.h"
using namespace std;

//additions
//population
//spreading

//sick +
//succeptible ?
//recovered -
int main()
{
	int step=0;
	int npeople;
	float per_in;
	float prob;

	cout << "Enter population size: " << endl;
	cin >> npeople;

	cout << "Enter probability of transfer: " << endl;
	cin >> prob;

	cout << "Enter percentage of people innoculated: " << endl;
	cin >> per_in;

	Population pop(npeople,prob);
	pop.innoculation(per_in);
	pop.random_infection();
	srand(time(NULL));

	while(pop.count_infected()!=0)
	{
		step+=1;
		cout << "In step " << setw(3) <<  step << " ";
		pop.printing();
		pop.update();
		pop.spreading();
	}
	cout << "In step " << setw(3) << step+1 << " ";
	pop.printing();
	cout << "Disease ran its course by step " <<  step+1 << endl;
	cout << "Total people infected : " << pop.total_infected() << endl;

}
