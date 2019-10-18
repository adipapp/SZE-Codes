#include "Jedi.h"
#include <iostream>
#include <string>

using namespace std;

Jedi::Jedi(string nev, int ero, bool mesterE) : Karakter(nev, ero), mesterE(mesterE)
{
	//Ilyet származtatásnál NE!!!
	//this->nev = nev;
	//this->ero = ero;
	//this->mesterE = mesterE;
}

bool Jedi::getMesterE()
{
	return mesterE;
}

void Jedi::setMesterE(bool mE)
{
	mesterE = mE;
}

void Jedi::print() const
{
	string m = "";
	if (mesterE) m = "Mester";
	else m = "Nem mester";
	cout << nev << "\t" << ero << "\t" << m << endl;
}
