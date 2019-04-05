#include <iostream>
#include <cmath>
#include <string>
#include "person_header.h"
using namespace std;

//recoverd : used as a boolean to exit while and for loops in population class
//status : represents if they're sick, healthy(succeptible), recovered, or innoculted

//healthy(succeptible) = 0
//sick > 0
//recovered = -1
//inocculated = -2

Person::Person()
{
	status = 0;
	recovered = false;
};

Person::Person(int n)
{
	status = n;
	recovered = false;
};

string Person::status_string()
{

	if(status > 0) 
		return  "sick ";
	else if(status == 0)
		return "suceptible ";
	else
		return "recovered ";
};

bool Person::is_stable()
{
	if (status == -1)
		recovered = true;
	else
		recovered = false;
	return recovered;
};

void Person::infect(int n)
{
	if(status == 0)
		status = n;
};

void Person::update()
{
	if(status > 0)
	{
		status-=1;
		if(status == 0)
			status -=1;
	}
};

int Person::get_status()
{	
	return status;
};
