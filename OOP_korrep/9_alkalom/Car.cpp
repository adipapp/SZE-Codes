#include "Car.h"
#include <iostream>

Car::Car(string name): Vehicle(name)
{
	addPart(new Part("Front left wheel", 5));
	addPart(new Part("Front right wheel", 5));
	addPart(new Part("Rear left wheel", 5));
	addPart(new Part("Rear right wheel", 5));
}

void Car::print()
{
	cout << "Car named " << name << " with " << parts.size() << " parts:" << endl;
	for (auto i : parts) {
		cout << "\t" << i->getName() << "(" << i->getAge() << " years old)";
		if (!i->isHealthy()) cout << " - Needs repair!";
		cout << endl;
	}
}
