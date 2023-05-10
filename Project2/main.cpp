#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Project2.h"



int main(int argc, char*argv[]) {
	bool test = false;
	
	Project2* project2 = new Project2;
	std::string inFile (argv[1]), outFile (argv[2]);

	test = project2->Initiate(inFile);
	if (test == true) {
		project2->Simulate();
		project2->FileOutput(outFile);
	}
	
	delete project2;

	return 0;
}