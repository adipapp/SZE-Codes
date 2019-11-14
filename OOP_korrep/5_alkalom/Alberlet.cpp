#include "Alberlet.h"

Alberlet::Alberlet(string cim, int nm) : Lakas(cim, nm), alberlok(nullptr), alberlokDb(0)
{
}

Alberlet::~Alberlet()
{
	delete[] alberlok;
}

void Alberlet::szerzodik(string ujBerlo)
{
	string* temp = new string[alberlokDb + 1];
	for (int i = 0; i < alberlokDb; i++)
	{
		temp[i] = alberlok[i];
	}
	temp[alberlokDb] = ujBerlo;
	delete[] alberlok;
	alberlok = temp;
	alberlokDb++;
}