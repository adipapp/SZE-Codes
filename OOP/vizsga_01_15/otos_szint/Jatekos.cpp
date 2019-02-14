#include "Jatekos.h"
#include "Csapat.h"

Jatekos::Jatekos(string nev, int szulEv) : nev(nev), szulEv(szulEv), playerStat(nullptr) { }

Jatekos::~Jatekos()
{
	PlayerStats* temp;
	for (auto& it = playerStat; it != nullptr; it = temp) {
		temp = it->getPrev();
		delete it;
	}
}

string Jatekos::getNev() const
{
	return nev;
}

void Jatekos::gol()
{
	if(playerStat!= nullptr) playerStat->setGol();
}

PlayerStats* Jatekos::getPlayerStat()
{
	return playerStat;
}

void Jatekos::setPlayerStat(PlayerStats * newPS)
{
	playerStat = newPS;
}

void Jatekos::statisztika()
{
	if (playerStat == nullptr) cout << nev << " meg nem szerzodott csapathoz!" << endl;
	else {
		cout << nev << endl;
		for (auto& it = playerStat; it != nullptr; it = playerStat->getPrev()) {
			cout << "\t"<< it->getCsapat()->getName() << ": " << it->getGol() << "db golt szerzett" << endl;
		}
	}
	
}
