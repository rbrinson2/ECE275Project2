#include <string> 
#include <iostream>
#include <cstdbool>
#include "MathVector.h"

MathVector::MathVector() {
	numElements = 0;
}

bool MathVector::readElements(std::string str) {
	return true;
}
std::string MathVector::toString() {
	std::string tempString;
	for (auto c : elements) {
		tempString.push_back(c);
		tempString.push_back(', ');
	}
	return tempString;
}