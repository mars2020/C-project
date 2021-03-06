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
//contagion
//innoculation

//sick +
//succeptible ?
//recovered -
int main()
{
	int step;
	int npeople;
	float per_in;
	float prob;
	
	for(int trials =0;trials<9;trials++)
	{
		step = 0;

		cout << "Enter population size: " << endl;
		cin >> npeople;

		cout << "Enter probability of transfer: " << endl;
		cin >> prob;

		cout << "Enter percentage of people innoculated: " << endl;
		cin >> per_in;
	
		srand(time(NULL));
		Population pop(npeople,prob);
		pop.innoculation(per_in);
		pop.random_infection();

		while(pop.count_infected()!=0)
		{
			float bad_luck = (float)rand()/(float)RAND_MAX;
			step+=1;
			//cout << "In step " <<setw(4)<< step << " ";
			//pop.printing();
			pop.update();
			pop.spreading();
		}
	//	cout << "In step " <<setw(4) <<step+1 << " ";
	//	pop.printing();
		cout << "Disease ran its course by step " << step+1 << endl;
		cout << "Total people infected : " << pop.total_infected() << endl;
	}
}
