#include <stdio.h>
#include <vector>
#include <iostream>

#include "Input.h""

Input::Input(){
	numElements = 2;
	velocity = 0;
	delta = 0;
}
Input::Input(const Input& other) {
	numElements = 2;
	this->velocity = other.velocity;
	this->delta = other.delta;
}

Input::Input(double v, double delta){
	numElements = 2;
	this->velocity = v;
	this->delta = delta;
}

double Input::getV(){
	return velocity;
}
double Input::getDeltaDot(){
	return delta;
}


