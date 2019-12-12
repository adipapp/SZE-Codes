#include "MotorBike.h"
#include <iostream>

MotorBike::MotorBike(string name) : Vehicle(name)
{
	addPart(new Part("Front wheel", 4));
	addPart(new Part("Rear wheel", 4));
}

void MotorBike::print()
{
	cout << "Motorbike named " << name << " with " << parts.size() << " parts:" << endl;
	for (auto i : parts) {
		cout << "\t" << i->getName() << "(" << i->getAge() << " years old)";
		if (!i->isHealthy()) cout << " - Needs repair!";
		cout << endl;
	}
}
