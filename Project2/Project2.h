#include "Director.h"
#include "Input.h"
#include "State.h"
#include "Vehicle.h"

#include <string>
#include <vector>

class Project2
{
public:
	Project2();
	~Project2();

	bool Initiate(std::string inFile);
	void FileOutput(std::string outFile);
	Director GetDirector();
	void SetDirector(Input* inp);
	void Simulate();
	void AddStateVector();

private:
	double dtime;
	Director director;
	State state;
	Vehicle vehicle;
	std::vector<State*> states;
};


