#include "Rectangle.hpp"

#include <iostream>

Rectangle::Rectangle(double xbf, double ybf, double xja, double yja) : fill('#'), id(nextid++) {
	bf.x = xbf;
	bf.y = ybf;
	ja.x = xja;
	ja.y = yja;
	jf.x = xbf + (xja - xbf);
	jf.y = ybf;
	ba.x = xbf;
	ba.y = ybf + (yja - ybf);
}

Rectangle::~Rectangle(){}

bool Rectangle::contains(double x, double y) const {
	if (x >= bf.x&&x <= ja.x&&y <= bf.y&&y >= ja.y) return true;
	else return false;
}

int Rectangle::nextid = 0;

Object2D::Point Rectangle::getbf() const {
	return bf;
}

Object2D::Point Rectangle::getja() const {
	return ja;
}

int Rectangle::getid() const {
	return id;
}

char Rectangle::plot(double x, double y) const {
	if (contains(x, y)) return fill;
	else return ' ';
}

ostream& Rectangle::print(ostream& cout) {
	cout << getid() << ". Teglalap:\n\tBF-X: " << getbf().x << " BF-Y: " << getbf().y << "\n\tJA-X: " << getja().x << " JA-Y: " << getja().y << std::endl;
	return cout;
}

ofstream& Rectangle::printFile(ofstream& file, int bfx, int bfy) {
	int x = abs(bf.x - bfx);
	int y = abs(bf.y - bfy);
	int width = abs(bf.x - ja.x);
	int heigth = abs(bf.y - ja.y);
	file << "<rect x = \"" << x*100 << "\" y = \"" << y*100 << "\" width = \"" << width*100 << "\" height = \"" << heigth*100 << "\"	style = \"fill:blue;stroke:black;stroke-width:1;\"/>" << std::endl;
	return file;
}