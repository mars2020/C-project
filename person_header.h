#ifndef PERSON_HEADER_H_
#define PERSON_HEADER_H_
#include <iostream>
#include <string>
using namespace std;

class Person
{
	private: 
		int status;
		bool recovered;
	public:
		Person();
		Person(int n);
		string status_string();
		bool is_stable();
		void infect(int n);
		void update();
		int get_status();
};
#endif
