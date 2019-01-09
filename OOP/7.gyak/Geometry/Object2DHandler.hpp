#ifndef OBJECT2DHANDLER_HPP
#define OBJECT2DHANDLER_HPP

#include "Object2D.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

#include <string>
#include <list>
#include <iostream>
using namespace std;

class Object2DHandler {
public:
	Object2DHandler();
	list<Object2D*> readFile(string filename) const;
	void plot(list<Object2D*> objects, int canbfx, int canbfy, int canjax, int canjay, int resx, int resy) const;
	void plot(list<Object2D*> objects, int canbfx, int canbfy, int canjax, int canjay) const;
	int containsPoint(list<Object2D*> objects, double x, double y) const;
	void printObjectsData(list<Object2D*> objects) const;
	void plotToSVG(string filename, list<Object2D*> objects, int canbfx, int canbfy, int canjax, int canjay) const;
};

#endif