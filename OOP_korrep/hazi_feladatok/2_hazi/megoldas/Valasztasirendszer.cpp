#include <iostream>

#include "Valasztasirendszer.h"

using namespace std;

Valasztasirendszer::Valasztasirendszer(int szavJog) : jeloltekListaja(nullptr), szavazasraJogosultak(szavJog)
{
}

Valasztasirendszer::~Valasztasirendszer()
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		Jelolt* toDel = i;
		i = i->getKovetkezo();
		delete toDel;
	}
}

void Valasztasirendszer::jeloltHozzaad(Jelolt * ujJelolt)
{
	if (jeloltekListaja == nullptr) jeloltekListaja = ujJelolt;
	else {
		Jelolt* i;
		for (i = jeloltekListaja; i->getKovetkezo() != nullptr; i = i->getKovetkezo());
		i->setKovetkezo(ujJelolt);
	}
}

//A destruktor és a jeloltKeres fgv-ek összegyúrásából, több jó megoldás is van, ez csak minta
void Valasztasirendszer::jeloltTorol(string nev)
{
	Jelolt* akt = jeloltekListaja;
	//Ha az elsõ elemet kell törölni:
	if (akt->getNev() == nev) {
		jeloltekListaja = jeloltekListaja->getKovetkezo();
		delete akt;
	}
	//Ha valamelyik köztes vagy az utolsó elemet kell törölni
	else {
		Jelolt* elozo = jeloltekListaja; //Tárolja a keresés során mindig a megelõzõ elemet, kezdetben a lista elsõ eleme
		akt = akt->getKovetkezo(); //Tárolja az aktuális elemet, mivel az elsõ elemet már ellenõriztük, így kezdetben a lista második eleme
		while (akt != nullptr) //Amíg vége nincs a listának
		{
			if (akt->getNev() == nev) { //Ha megtaláltuk a törlendõ képviselõt
				elozo->setKovetkezo(akt->getKovetkezo()); //Az elõzõ elem követõje már nem az akt lesz, hanem az akt követõje, mivel aktot szeretnénk törölni
				delete akt; //A megtalált jelölt törlése
				break; //Megszakítjuk a ciklust mivel feltételezhetjük hogy csak 1 ilyen nevû jelölt van
			}
			elozo = akt; // Amikor nem volt találat akkor minden ciklusban léptetjük az elozot és aktot
			akt = akt->getKovetkezo();
		}
	}
}

bool Valasztasirendszer::jeloltKeres(string nev)
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		if (i->getNev() == nev) return true;
		i = i->getKovetkezo();
	}
	return false;
}

//Plusz néhány adat a cout-ra, semmi extra
void Valasztasirendszer::jelolteketListaz()
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		cout << i->getNev() << "\t\t" << i->getPart() << "\t" << i->getValKer() << ". kerulet\t" << i->getSzavazatokSzama() << " szavazat" << endl;
		i = i->getKovetkezo();
	}
}

//Egyszerû const getter fgv a Jelolt osztályban lévõk mintájára
int Valasztasirendszer::getSzavazasraJogosultak() const
{
	return szavazasraJogosultak;
}

//Teljesen ugyanaz mint a jeloltKeres, csak return-ök helyett a megtalált jelölt szavaz fgv-ét hívja meg
void Valasztasirendszer::jeloltreSzavaz(string nev, int db)
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		if (i->getNev() == nev) i->szavaz(db);
		i = i->getKovetkezo();
	}
}

//Egyszerû lista végégjárás, minden jelöltre leadott szavazatot összegzünk, a végén egy osztással (muszáj doble-t használni különben egész osztás lenne)
double Valasztasirendszer::reszveteliArany() const
{
	double szavazatok = 0;
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		szavazatok += i->getSzavazatokSzama();
		i = i->getKovetkezo();
	}
	return (szavazatok / szavazasraJogosultak) * 100;
}

//Maximumkeresés láncolt listában
string Valasztasirendszer::gyoztesJelolt() const
{
	Jelolt* i = jeloltekListaja;
	Jelolt* max = jeloltekListaja;
	while (i != nullptr)
	{
		if(i->getSzavazatokSzama() > max->getSzavazatokSzama()) max = i;
		i = i->getKovetkezo();
	}
	return max->getNev();
}

double Valasztasirendszer::partSzavazatok(string part) const
{
	double osszSzavazat = 0;
	double partSzavazat = 0;
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		if(i->getPart() == part) partSzavazat += i->getSzavazatokSzama(); //Ha adott párt tagja, akkor a pártra leadott szavazatok számát növeljük
		osszSzavazat += i->getSzavazatokSzama(); //Minden képviselõre leadott szavazat növeli az összes leadott szavazatok számát
		i = i->getKovetkezo();
	}
	return (partSzavazat / osszSzavazat) * 100;
}

//Maximumkeresés láncolt listában + 1 feltétel
string Valasztasirendszer::korzetSzavazatok(int korzet) const
{
	Jelolt* i = jeloltekListaja;
	Jelolt* max = jeloltekListaja;
	while (i != nullptr)
	{
		if (i->getValKer() == korzet && i->getSzavazatokSzama() > max->getSzavazatokSzama()) max = i;
		i = i->getKovetkezo();
	}
	return max->getNev();
}