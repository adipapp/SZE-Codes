#include <iostream>
#include "Karakter.h"

Karakter::Karakter(string nev, int ero) : nev(nev), ero(ero)
{
}

string Karakter::getNev() const
{
	return nev;
}

int Karakter::getEro() const
{
	return ero;
}

void Karakter::setEro(int e)
{
	ero = e;
}

void Karakter::print() const
{
	cout << nev << "\t" << ero << endl;
}