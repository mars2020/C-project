#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include "person_header.h"
using namespace std;

//only one person is infected

//healthy = 0
//sick > 0
//recovered = -1
//inocculated = -2
//sick +
//succeptible ?
//recovered -
int main()
{
	srand(time(NULL));
	int step=0;
	Person p1;
	while(1)
	{
		step+=1;
		p1.update();
		float bad_luck = (float) rand()/(float)RAND_MAX;
		if (bad_luck>.95)
			p1.infect(5);
		cout << "On day " << step << ", p1 is " << p1.status_string() << endl;		
		if (p1.is_stable()) 
			break;
	}

}
