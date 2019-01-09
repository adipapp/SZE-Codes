#include "Object2D.hpp"
#include "Object2DHandler.hpp"

#include <list>
#include <iostream>
using namespace std;

int main() {
	Object2DHandler handler;
	list<Object2D*> objects = handler.readFile("geometry.txt");
	
	handler.printObjectsData(objects);
	handler.plot(objects, -5, 5, 5, -5, 75, 40);
	handler.plot(objects, -5, 5, 5, -5);
	handler.plotToSVG("plot.html", objects, -5, 5, 5, -5);
	cout << "A pontot fedo alakzatok szama: " << handler.containsPoint(objects, 0, 0) << endl;
}