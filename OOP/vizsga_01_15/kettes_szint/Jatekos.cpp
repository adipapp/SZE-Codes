#include "Jatekos.h"
#include "Csapat.h"

Jatekos::Jatekos(string nev, int szulEv) : nev(nev), szulEv(szulEv), csapat(nullptr) { }

string Jatekos::getNev() const
{
	return nev;
}

Csapat* Jatekos::getCsapat() const
{
	return csapat;
}

void Jatekos::setCsapat(Csapat* ujcsapat)
{
	csapat=ujcsapat;
}
