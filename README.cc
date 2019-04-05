/*
  	The directory contains 4 main programs, each one for a particular example.
 
  	main programs
 
  	main_1 : for a single person
  	main_2 : for a population without contagion
  	main_3 : for a population with contagion and innoculation
  	main_4 : for a population with spreading and innoculation
 
  	classes
 
  	person		 : includes all methods needed for all main programs
  	population_2 : includes methods for main_2
  	population_3 :    "        "     "  main_3
  	population_4 :    "        "     "  main_4
 
  	methods for person
 
  	status_string() : returns a string with the status of a single person
  	is_stable()     : returns the a boolean stating if  they're recovered or not
  	infect() 		: sets the status of a person = 5, so they are infected for 5 days
  	update() 		: subtracts 1 from a persons status and 2 if they are healthy so they become recovered and can't get sick again
 	get_status		: a getter method used mainly in the population class to access the status of a person
 
 	methods for population
  	
    count_infected()		  : counts the number of persons infected and returns that value
    total_infected()		  : counts the total number of people who got infected
	random_infection()  	  : selects a rendom person that is not innoculated to be the first person sick
    update()				  : subtracts 1 from every person that is sick
    printing()				  : prints the correct symbol for each person's status
    innoculation(float  per)  : takes in a percentage to innoculated that many people
    conatgion(float bad_luck) : compares a persons bad_luck to the probability of transfer which either infects the person the people next to the current person or nobody
    spreading()			      : instead of infecting the direct neighbors of a person, a sick person ocmes into contact with 6 people a day and may infect up to 6 random people
    
    NOTE:	each population class uses the same header file, but only contains the methids pertaining to the particular example
	
	Compiling the programs

	main_1 : icpc main_1.o person.o -o exe_fle_1
	main_2 : icpc main_2.o person.o population_2.o -o exe_file_2
	main_3 : icpc main_3.o person.o population_3.o -o exe_file_3
	main_4 : icpc main_4.o person.o population_4.o -o exe_file_4

*/
