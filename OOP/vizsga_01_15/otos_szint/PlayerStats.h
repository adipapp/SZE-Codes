#ifndef PLYERSTATS_H
#define PLYERSTATS_H

#include "Csapat.h"
#include <string>

using namespace std;

class PlayerStats
{
public:
	PlayerStats(Csapat* newCsapat=nullptr, int golok=0);
	Csapat* getCsapat();
	void setCsapat(Csapat* newCsapat);
	int getGol();
	void setGol();
	PlayerStats* getPrev();

private:
	Csapat* csapat;
	int golok;
	PlayerStats* prev;
};


#endif // !PLYERSTATS_H