#include "PlayerStats.h"

PlayerStats::PlayerStats(Csapat* newCsapat, int newGolok) : csapat(newCsapat), golok(newGolok), prev(nullptr) { }

Csapat* PlayerStats::getCsapat()
{
	return csapat;
}

void PlayerStats::setCsapat(Csapat * newCsapat)
{
	PlayerStats* elozo = new PlayerStats(csapat, golok);
	golok = 0;
	csapat = newCsapat;
	prev = elozo;
}

int PlayerStats::getGol()
{
	return golok;
}

void PlayerStats::setGol()
{
	golok++;
}

PlayerStats * PlayerStats::getPrev()
{
	return prev;
}
