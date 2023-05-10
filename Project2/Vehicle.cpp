#include "Vehicle.h"
#include "State.h"
#include "Input.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

// vehicle should start at 0, 0, 0, 0 if nothing is passed in. It should
// allocate a default value of State of 0, 0, 0, 0
Vehicle::Vehicle() {
    state = new State{ 0, 0, 0, 0 };
    wheelbase = 0;
}


// vehicle should make a copy of the data in x0 and allocate new memory
// to hold its state value
Vehicle::Vehicle(State x0, double wheelbase) {
    state = new State(x0);
    this->wheelbase = wheelbase;
}


// implementation should delete the state variable data
Vehicle::~Vehicle() {
    
}


// return the wheelbase value
double Vehicle::getWheelbase() {
    return wheelbase;
}

// returns a pointer to the current state. The calling object should make
// a deep copy of the data if it wants to keep it
State* Vehicle::update(Input* u, double ts) {
    
    State* state2 = new State();
    
    state2->setX(state->getX() + (ts * u->getV() * cos(state->getDelta()) * cos(state->getTheta())));
    state2->setY(state->getY() + (ts * u->getV() * cos(state->getDelta()) * sin(state->getTheta())));
    state2->setDelta(state->getDelta() + ts * u->getDeltaDot());
    state2->setTheta(state->getTheta() + (ts * u->getV() * (1.0 / wheelbase) * sin(state->getDelta())));

    return state2;
}


// returns a pointer to the current state. The calling object should make
// a deep copy of the data if it wants to keep it
State* Vehicle::getState() {
    return state;
}

void Vehicle::SetState(State* s) {
    state = s;
}