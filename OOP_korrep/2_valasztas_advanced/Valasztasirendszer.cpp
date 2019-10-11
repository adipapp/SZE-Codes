#include <iostream>

#include "Valasztasirendszer.h"

using namespace std;

Valasztasirendszer::Valasztasirendszer() : jeloltekListaja(nullptr)
{
}

Valasztasirendszer::~Valasztasirendszer()
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		Jelolt* toDel = i;
		i = i->getKovetkezo();
		delete toDel;
	}
}

void Valasztasirendszer::jeloltHozzaad(Jelolt * ujJelolt)
{
	if (jeloltekListaja == nullptr) jeloltekListaja = ujJelolt;
	else {
		Jelolt* i;
		for (i = jeloltekListaja; i->getKovetkezo() != nullptr; i = i->getKovetkezo());
		i->setKovetkezo(ujJelolt);
	}
}

void Valasztasirendszer::jeloltTorol(string nev)
{
}

bool Valasztasirendszer::jeloltKeres(string nev)
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		if (i->getNev() == nev) return true;
		i = i->getKovetkezo();
	}
	return false;
}

void Valasztasirendszer::jelolteketListaz()
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		cout << i->getNev() << endl;
		i = i->getKovetkezo();
	}
}