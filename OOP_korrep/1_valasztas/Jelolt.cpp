#include <string>

#include "Jelolt.h"

using namespace std;

Jelolt::Jelolt(string jNev, string jPart, int jValasztoKerulet, int jSzavazatok) {
	nev = jNev;
	part = jPart;
	valasztoKerulet = jValasztoKerulet;
	szavazatok = jSzavazatok;
}

string Jelolt::getNev() {
	return nev;
}

string Jelolt::getPart() {
	return part;
}

int Jelolt::getValKer() {
	return valasztoKerulet;
}

int Jelolt::getSzavazatokSzama() {
	return szavazatok;
}