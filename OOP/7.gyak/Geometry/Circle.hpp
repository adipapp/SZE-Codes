#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Object2D.hpp"

class Circle : public Object2D {
public:
	Circle(double x, double y, double r);
	~Circle();
	virtual bool contains(double x, double y) const;
	Point getkp() const;
	double getr() const;
	int getid() const;
	virtual ofstream& printFile(ofstream& file, int bfx, int bfy);

protected:
	virtual char plot(double x, double y) const;
	virtual ostream& print(ostream& cout);

private:
	Point kp;
	double r;
	char fill;
	int id;
	static int nextid;
};

#endif
