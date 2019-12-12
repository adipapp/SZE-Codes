#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

class MotorBike : public Vehicle {
public:
	MotorBike(string name);
	virtual void print();
};

#endif
