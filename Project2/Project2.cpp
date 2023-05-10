#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Project2.h"
#include "Input.h"
#include "Director.h"
#include "Vehicle.h"


Project2::Project2() {
	dtime = 0;
	state = State();
	vehicle = Vehicle();
}
Project2::~Project2() {
	std::cout << "Project2 Destroyed\n";
}


bool Project2::Initiate(std::string inFile) {
	double wheelbase = 0, x = 0, y = 1, delta = 1, theta = 1, dt = 1;
	double velocity = 0, deltaDot = 1;
	std::string holdString;
	char holdChar;
	Input* inp;



	//Input Stream from file
	std::ifstream inputStream{ inFile };
	
	try {
		if (!inputStream) throw std::runtime_error("File not found\n");
		while (!inputStream.eof()) {

			inputStream >> velocity; //attempt to import velocity

			if (!inputStream) {
				if (inputStream.bad()) throw std::runtime_error("Fail line 39\n");
				else inputStream.clear(); //clear fail flag
				
				inputStream >> holdString; //retry input stream

				if (holdString.compare("Wheelbase:") == 0) {
					inputStream >> wheelbase;
					if (inputStream.fail()) { throw std::runtime_error("Wheelbase failed\n"); }
				}
				else if (holdString.compare("InitialPose:") == 0) {
					inputStream >> x >> holdChar >> y >> holdChar >> delta >> holdChar >> theta;
					state = State(x, y, delta, theta);
					if (inputStream.fail()) throw std::runtime_error("Initial Position failed\n");
				}
				else if (holdString.compare("Dt:") == 0) {
					inputStream >> dtime;
					if (inputStream.fail()) {
						inputStream.clear();
						if (director.inputSize() == 0) throw std::runtime_error("DT failed\n");
					}
				}
				
				else {
					inputStream.fail();
					throw std::runtime_error("Velocity failed\n");
				}
				
				
			}

			inputStream >> holdChar;
			if (holdChar == ',') {
				inputStream >> deltaDot;
				inp = new Input(velocity, deltaDot);
				SetDirector(inp);
			}
			else inputStream.unget();
			 
			
		}
		vehicle = Vehicle(state, wheelbase);
	}
	catch (std::runtime_error& excpt) {
		std::cout << excpt.what();
		return false;
	}
	return true;
}

void Project2::FileOutput(std::string outFile) {
	std::ofstream outputStream{ outFile };
	if (!outputStream) std::cout << "Output file not found\n";
	
	double dt = dtime, time = 0, i = 0;
	Input* tempImp;
	
	for (auto c : states) {
		tempImp = director.getInput(i);
		outputStream.precision(3);
		outputStream << time << ','
			<< c->getX() << ','
			<< c->getY() << ','
			<< c->getDelta() << ','
			<< c->getTheta() << ','
			<< tempImp->getV() << ','
			<< tempImp->getDeltaDot()
			<< std::endl;
		
		std::cout << time << ','
			<< c->getX() << ','
			<< c->getY() << ','
			<< c->getDelta() << ','
			<< c->getTheta() << ','
			<< tempImp->getV() << ','
			<< tempImp->getDeltaDot()
			<< std::endl;
			
		time += dt;
		i++;
	}
	
}

Director Project2::GetDirector() {
	return director;
}
void Project2::SetDirector(Input* inp) {
	director.addInput(inp);
}

void Project2::Simulate() {
	
	for (int i = 0; i < director.inputSize(); i++) {
		AddStateVector();
		vehicle.SetState(vehicle.update(director.getInput(i), dtime));
	}
	
}

void Project2::AddStateVector() {
	states.push_back(vehicle.getState());
}
