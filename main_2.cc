#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include "person_header.h"
#include "population_header.h"
using namespace std;

//additions
//population


//healthy = 0
//sick > 0
//recovered = -1
//inocculated = -2
//sick +
//succeptible ?
//recovered -
int main()
{
	int step=0;
	int npeople;
	cout << "Enter population size: " << endl;
	cin >> npeople;
	Population pop(npeople);
	pop.random_infection();
	srand(time(NULL));
	while(pop.count_infected()!=0)
	{
		float bad_luck = (float)rand()/(float)RAND_MAX;
		step+=1;
		cout << "In step " << step << " ";
		pop.printing();
		pop.update();
	}
	cout << "In step " << step+1 << " ";
	pop.printing();
	cout << "Disease ran its course by step " << step+1 << endl;

}
