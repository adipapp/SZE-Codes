#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Object2D.hpp"

class Rectangle : public Object2D {
public:
	Rectangle(double xbf, double ybf, double xja, double yja);
	~Rectangle();
	virtual bool contains(double x, double y) const;
	Point getbf() const;
	Point getja() const;
	int getid() const;
	virtual ofstream& printFile(ofstream& file, int bfx, int bfy);

protected:
	virtual ostream& print(ostream& cout);
	virtual char plot(double x, double y) const;

private:
	Point bf;
	Point ba;
	Point jf;
	Point ja;
	char fill;
	int id;
	static int nextid;
};

#endif