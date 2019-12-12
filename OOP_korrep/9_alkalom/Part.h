#ifndef PART_H
#define PART_H

#include <string>
using namespace std;

class Part {
private:
	string name;
	int lifetime;
	int age;

public:
	Part(string name, int lifetime);
	string getName();
	void amortize();
	void repair();
	bool isHealthy();
	int getAge();
};

#endif