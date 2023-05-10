#include <stdint.h>
#include "State.h"
#include <iostream>

#define X 0
#define Y 1
#define DELTA 2
#define THETA 3

#define M_PI 3.1415927
#define DELTA_MAX 0.5236
#define DELTA_MIN (-DELTA_MAX)
#define HEADING_MAX (2*M_PI)

State::State() {
	numElements = 4;
	elements.push_back(0);
	elements.push_back(0);
	elements.push_back(0);
	elements.push_back(0);
}
State::State(double x, double y, double delta, double theta) : MathVector(numElements) {
	numElements = 4;
	elements.push_back(x);
	elements.push_back(y);
	elements.push_back(delta);
	elements.push_back(theta);
}

State::State(const State& other) {
	numElements = 4;
	elements.push_back(other.elements.at(X));
	elements.push_back(other.elements.at(Y));
	elements.push_back(other.elements.at(DELTA));
	elements.push_back(other.elements.at(THETA));
}
double State::getX() {
	return elements.at(X);
}
double State::getY() {
	return elements.at(Y);
}
double State::getDelta() {
	return elements.at(DELTA);
}
double State::getTheta() {
	return elements.at(THETA);
}
void State::setX(double newX) {
	elements.at(X) = newX;
}
void State::setY(double newY) {
	elements.at(Y) = newY;
}
void State::setDelta(double newDelta) {
	if (newDelta > DELTA_MAX) newDelta = DELTA_MAX;
	if (newDelta < DELTA_MIN) newDelta = DELTA_MIN;
	elements.at(DELTA) = newDelta;
}
void State::setTheta(double newTheta) {
	if (newTheta < 0) newTheta = HEADING_MAX;
	if (newTheta > HEADING_MAX) newTheta = 0;
	elements.at(THETA) = newTheta;
}