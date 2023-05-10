#ifndef Director_h
#define Director_h

#include <vector>

#include "Input.h"

class Director {
public:
	void addInput(Input* i);
	Input* getInput(int i);
	int inputSize();
	void PopDirector();

private:
	std::vector<Input*> input;
};


#endif // !Director_h