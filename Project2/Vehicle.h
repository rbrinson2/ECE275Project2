//
//  Vehicle.hpp
//
//

#ifndef Vehicle_h
#define Vehicle_h

#include <stdio.h>
#include "State.h"
#include "Input.h"

class Vehicle {
    
public:
    // vehicle should start at 0, 0, 0, 0 if nothing is passed in. It should
    // allocate a default value of State of 0, 0, 0, 0
    Vehicle( );
    // vehicle should make a copy of the data in x0 and allocate new memory
    // to hold its state value
    Vehicle( State x0, double wheelbase );
    // implementation should delete the state variable data
    ~Vehicle( );
    // return the wheelbase value
    double getWheelbase( );
    // returns a pointer to the current state. The calling object should make
    // a deep copy of the data if it wants to keep it
    State* update( Input* u, double ts );
    // returns a pointer to the current state. The calling object should make
    // a deep copy of the data if it wants to keep it
    State* getState( );
    void SetState(State* s);
    
private:
    double wheelbase;
    State* state;
};

#endif /* Vehicle_h */
