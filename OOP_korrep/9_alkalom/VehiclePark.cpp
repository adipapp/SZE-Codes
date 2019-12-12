#include "VehiclePark.h"
#include "Car.h"
#include "MotorBike.h"

void VehiclePark::addVehicle(Vehicle* newVehicle)
{
	vehicles.push_back(newVehicle);
}

void VehiclePark::printVehicles()
{
	for (auto i : vehicles) {
		i->print();
	}
}

void VehiclePark::amortize()
{
	for (auto i : vehicles) {
		i->amortizeParts();
	}
}

void VehiclePark::repairCars()
{
	for (auto i : vehicles) {
		if(dynamic_cast<Car*>(i)) i->repairParts();
	}
}

void VehiclePark::repairBikes()
{
	for (auto i : vehicles) {
		if (dynamic_cast<MotorBike*>(i)) i->repairParts();
	}
}
