#ifndef JATEKOS_H
#define JATEKOS_H

#include <string>
#include <iostream>

using namespace std;

class Csapat;

class Jatekos
{
public:
	Jatekos(string nev, int szulEv);
	string getNev() const;
	Csapat* getCsapat() const;
	void setCsapat(Csapat* ujcsapat);

private:
	string nev;
	int szulEv;
	Csapat* csapat;
};

#endif