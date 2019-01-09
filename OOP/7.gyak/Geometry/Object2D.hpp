#ifndef OBJECT2D_HPP
#define OBJECT2D_HPP

#include <iostream>
#include <fstream>
using namespace std;

class Object2D {
protected:
	struct Point
	{
		double x;
		double y;
	};

public:
	virtual bool contains(double x, double y) const = 0;
	virtual char plot(double x, double y) const = 0;
	virtual ofstream& printFile(ofstream& file, int bfx, int bfy) = 0;

protected:
	virtual ostream& print(ostream& cout) = 0;
	
	friend ostream& operator<<(ostream& cout, Object2D* obj) {
		return obj->print(cout);
	}
};


#endif