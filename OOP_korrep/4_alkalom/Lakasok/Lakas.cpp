#include "Lakas.h"

Lakas::Lakas(string cim, int nm) : nm(nm), cim(cim), tulajok(nullptr), tulajDb(0)
{
}

int Lakas::arPerNm = 120000;

Lakas::~Lakas()
{
	delete[] tulajok;
}

int Lakas::vetelar()
{
	return arPerNm*nm;
}

void Lakas::elad(string ujTulaj)
{
	string* temp = new string[tulajDb + 1];
	for (int i = 0; i < tulajDb; i++)
	{
		temp[i] = tulajok[i];
	}
	temp[tulajDb] = ujTulaj;
	delete[] tulajok;
	tulajok = temp;
	tulajDb++;
}

void Lakas::setArPerNm(int newAr)
{
	arPerNm = newAr;
}