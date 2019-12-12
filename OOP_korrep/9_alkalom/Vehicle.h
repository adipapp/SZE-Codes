#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>
#include "Part.h"
using namespace std;

class Vehicle {
protected:
	string name;
	vector<Part*> parts;

public:
	Vehicle(string name);
	string getName();
	void addPart(Part* newPart);
	virtual void print() = 0;
	void amortizeParts();
	void repairParts();
};

#endif