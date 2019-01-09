#include "Circle.hpp"

#include <iostream>
#include <cmath>

Circle::Circle(double x, double y, double r) : r(r), fill('o'), id(nextid++) {
	Point p;
	p.x = x;
	p.y = y;
	kp = p;
}

Circle::~Circle() {}

bool Circle::contains(double x, double y) const {
	return r >= sqrt(pow(x - kp.x, 2) + pow(y - kp.y, 2));
}

int Circle::nextid = 0;

Object2D::Point Circle::getkp() const {
	return kp;
}

double Circle::getr() const {
	return r;
}

int Circle::getid() const {
	return id;
}

char Circle::plot(double x, double y) const {
	if (contains(x, y)) return fill;
	else return ' ';
}

ostream& Circle::print(ostream& cout) {
	cout << getid() << ". Kor:\n\tX: " << getkp().x << " Y: " << getkp().y << "\n\tR: " << getr() << std::endl;
	return cout;
}

ofstream& Circle::printFile(ofstream& file, int bfx, int bfy) {
	int x = abs(kp.x - bfx);
	int y = abs(kp.y - bfy);
	file << "<circle cx = \""<<x*100<<"\" cy = \"" << y*100 << "\" r = \""<<r*100<<"\" stroke = \"black\" stroke-width = \"1\" fill = \"red\"/>" << std::endl;
	return file;
}