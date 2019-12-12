#include "Vehicle.h"

Vehicle::Vehicle(string name) : name(name) { }

string Vehicle::getName()
{
	return name;
}

void Vehicle::addPart(Part* newPart)
{
	parts.push_back(newPart);
}

void Vehicle::amortizeParts()
{
	for (auto i : parts) {
		i->amortize();
	}
}

void Vehicle::repairParts()
{
	for (auto i : parts) {
		if(!i->isHealthy()) i->repair();
	}
}
