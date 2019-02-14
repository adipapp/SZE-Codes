#ifndef JATEKOS_H
#define JATEKOS_H

#include "PlayerStats.h"
#include <string>
#include <iostream>

using namespace std;

class Csapat;

class Jatekos
{
public:
	Jatekos(string nev, int szulEv);
	~Jatekos();
	string getNev() const;
	void gol();
	PlayerStats* getPlayerStat();
	void setPlayerStat(PlayerStats* newPS);
	void statisztika();
	

private:
	string nev;
	int szulEv;
	PlayerStats* playerStat;
};

#endif