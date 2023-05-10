
#include <iostream>

#include "Director.h"
#include "Input.h"


void Director::addInput(Input* i) {
	input.push_back(i);
}
Input* Director::getInput(int i) {
	return input.at(i);
}
int Director::inputSize() {
	return input.size();
}
void Director::PopDirector() {
	input.erase(input.begin());
}
