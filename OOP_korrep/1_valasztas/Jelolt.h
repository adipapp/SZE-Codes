#ifndef JELOLT_H
#define JELOLT_H

#include <string>

using namespace std;

class Jelolt {
private:
	string nev;
	string part;
	int valasztoKerulet;
	int szavazatok;

public:
	//Jelolt(string jNev, string jPart, int jValasztoKerulet, int jSzavazatok) {
	//	nev = jNev;
	//	part = jPart;
	//	valasztoKerulet = jValasztoKerulet;
	//	szavazatok = jSzavazatok;
	//}

	//Jelolt(string jNev, string jPart, int jValasztoKerulet, int jSzavazatok) :
	//	nev(jNev), valasztoKerulet(jValasztoKerulet), part(jPart), szavazatok(jSzavazatok) {	}

	Jelolt(string jNev, string jPart, int jValasztoKerulet, int jSzavazatok = 0);

	string getNev();

	string getPart();

	int getValKer();

	int getSzavazatokSzama();


};

#endif