#include "Object2DHandler.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

#include <list>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Object2DHandler::Object2DHandler(){}

list<Object2D*> Object2DHandler::readFile(string filename) const {
	ifstream file(filename);
	list<Object2D*> objectlist;
	if (!file.is_open()) {
		cerr << "Sikertelen megnyitasi kiserlet!"; 
		return objectlist;
	}

	//fájlban sor eleji r: rectangle, c: circle
	char type;
	
	while (!file.eof())
	{
		file >> type;
		switch (type)
		{
		case 'r':
			double bfx, bfy, jax, jay;
			file >> bfx;
			file >> bfy;
			file >> jax;
			file >> jay;
			objectlist.push_back(new Rectangle(bfx, bfy, jax, jay));
			break;
		case 'c':
			double x, y, r;
			file >> x;
			file >> y;
			file >> r;
			objectlist.push_back(new Circle(x, y, r));
			break;
		}
	}
	return objectlist;
}

void Object2DHandler::plot(list<Object2D*> objects, int canbfx, int canbfy, int canjax, int canjay, int resx, int resy) const {
	for (int dx = 0; dx <= resx+1; dx++) cout << "-";
	cout << endl;
	objects.reverse();

	double stepx = abs(canjax - canbfx) / (double)resx;
	double stepy = abs(canbfy - canjay) / (double)resy;

	for (int i = 0; i < resy; i++)
	{
		cout << "|";
		for (int j = 0; j < resx; j++)
		{
			char a = ' ';
			for (auto& obj : objects)
			{
				if (obj->plot(canbfx+j*stepx, canbfy - i * stepy) != ' ') {
					a = obj->plot(canbfx + j * stepx, canbfy - i * stepy);
					break;
				}
			}
			cout << a;
		}
		cout << "|" << endl;
	}
	   
	for (int dx = 0; dx <= resx+1; dx++) cout << "-";
	cout << endl;
}

void Object2DHandler::plot(list<Object2D*> objects, int canbfx, int canbfy, int canjax, int canjay) const {
	for (int dx = canbfx; dx <= canjax+2; dx++) cout << "-";
	cout << endl;
	objects.reverse();

	for (int dy = canbfy; dy >= canjay; dy--)
	{
		cout << "|";
		for (int dx = canbfx; dx <= canjax; dx++)
		{
			char a = ' ';
			for (auto& obj : objects)
			{
				if (obj->plot(dx, dy) != ' ') {
					a = obj->plot(dx, dy);
					break;
				}
			}
			cout << a;
		}
		cout << "|" << endl;
	}

	for (int dx = canbfx; dx <= canjax+2; dx++) cout << "-";
	cout << endl;
}

int Object2DHandler::containsPoint(list<Object2D*> objects, double x, double y) const {
	int db = 0;
	for (auto& obj : objects) if (obj->contains(x, y)) db++;
	return db;
}

void Object2DHandler::printObjectsData(list<Object2D*> objects) const {
	for (auto& obj : objects) cout << obj;
}

void Object2DHandler::plotToSVG(string filename, list<Object2D*> objects, int canbfx, int canbfy, int canjax, int canjay) const {
	ofstream file(filename);
	int width = abs(canbfx - canjax);
	int height = abs(canbfy - canjay);
	file << "<html><body><svg width = \""<<width*100<<"\" height = \""<<height*100<<"\">"<<endl;
	for (auto& obj : objects) obj->printFile(file, canbfx, canbfy);

	file << "</svg></body></html>";
	file.close();
}
