#include "Part.h"

Part::Part(string name, int lifetime) : name(name), lifetime(lifetime), age(0) { }

string Part::getName()
{
	return name;
}

void Part::amortize()
{
	age++;
}

void Part::repair()
{
	age = 0;
}

bool Part::isHealthy()
{
	return age <= lifetime;
}

int Part::getAge()
{
	return age;
}
