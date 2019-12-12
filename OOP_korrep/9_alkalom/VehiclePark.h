#ifndef VEHICLEPARK_H
#define VEHICLEPARK_H

#include "Vehicle.h"
#include <vector>
using namespace std;

class VehiclePark {
private:
	vector<Vehicle*> vehicles;

public:
	void addVehicle(Vehicle* newVehicle);
	void printVehicles();
	void amortize();
	void repairCars();
	void repairBikes();
};

#endif