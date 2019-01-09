#include <iostream>
#include <string>
#include "Teknos.h"
using namespace std;

bool interpreter(string& c, double& d) {
	string t = c.substr(0, 2);
	if (t == "fd" || t == "lt" || t == "rt") {
		d = stod(c.substr(3));
		c = t;
		return true;
	}
	else return false;
}

int main() {
	Teknos t;
	string command;
	bool quit;
	double d;
	do
	{
		cout << ">>> ";
		getline(cin, command);
		if (command == "quit") break;
		if (interpreter(command, d)) {
			if (command == "fd") t.fd(d);
			else if (command == "rt") t.rt(d);
			else if (command == "lt") t.lt(d);
			cout << "\nX: " << t.getX() << "\tY: " << t.getY() << "\tAlpha: " << t.getAlpha() << endl;
		}
		else cout << "Hiba!" << endl;
	} while (true);
}