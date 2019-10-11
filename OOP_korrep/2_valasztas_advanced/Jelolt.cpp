#include <string>

#include "Jelolt.h"

using namespace std;

Jelolt::Jelolt(string jNev, string jPart, int jValasztoKerulet, int jSzavazatok) {
	nev = jNev;
	part = jPart;
	valasztoKerulet = jValasztoKerulet;
	szavazatok = jSzavazatok;
	kovetkezo = nullptr;
}

string Jelolt::getNev() const {
	return nev;
}

string Jelolt::getPart() const {
	return part;
}

int Jelolt::getValKer() const {
	return valasztoKerulet;
}

int Jelolt::getSzavazatokSzama() const {
	return szavazatok;
}

Jelolt::~Jelolt()
{
	
}

Jelolt * Jelolt::getKovetkezo() const
{
	return kovetkezo;
}

void Jelolt::setKovetkezo(Jelolt * kovetkezo)
{
	this->kovetkezo = kovetkezo;
}