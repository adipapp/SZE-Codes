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

//A destruktor �s a jeloltKeres fgv-ek �sszegy�r�s�b�l, t�bb j� megold�s is van, ez csak minta
void Valasztasirendszer::jeloltTorol(string nev)
{
	Jelolt* akt = jeloltekListaja;
	//Ha az els� elemet kell t�r�lni:
	if (akt->getNev() == nev) {
		jeloltekListaja = jeloltekListaja->getKovetkezo();
		delete akt;
	}
	//Ha valamelyik k�ztes vagy az utols� elemet kell t�r�lni
	else {
		Jelolt* elozo = jeloltekListaja; //T�rolja a keres�s sor�n mindig a megel�z� elemet, kezdetben a lista els� eleme
		akt = akt->getKovetkezo(); //T�rolja az aktu�lis elemet, mivel az els� elemet m�r ellen�rizt�k, �gy kezdetben a lista m�sodik eleme
		while (akt != nullptr) //Am�g v�ge nincs a list�nak
		{
			if (akt->getNev() == nev) { //Ha megtal�ltuk a t�rlend� k�pvisel�t
				elozo->setKovetkezo(akt->getKovetkezo()); //Az el�z� elem k�vet�je m�r nem az akt lesz, hanem az akt k�vet�je, mivel aktot szeretn�nk t�r�lni
				delete akt; //A megtal�lt jel�lt t�rl�se
				break; //Megszak�tjuk a ciklust mivel felt�telezhetj�k hogy csak 1 ilyen nev� jel�lt van
			}
			elozo = akt; // Amikor nem volt tal�lat akkor minden ciklusban l�ptetj�k az elozot �s aktot
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

//Plusz n�h�ny adat a cout-ra, semmi extra
void Valasztasirendszer::jelolteketListaz()
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		cout << i->getNev() << "\t\t" << i->getPart() << "\t" << i->getValKer() << ". kerulet\t" << i->getSzavazatokSzama() << " szavazat" << endl;
		i = i->getKovetkezo();
	}
}

//Egyszer� const getter fgv a Jelolt oszt�lyban l�v�k mint�j�ra
int Valasztasirendszer::getSzavazasraJogosultak() const
{
	return szavazasraJogosultak;
}

//Teljesen ugyanaz mint a jeloltKeres, csak return-�k helyett a megtal�lt jel�lt szavaz fgv-�t h�vja meg
void Valasztasirendszer::jeloltreSzavaz(string nev, int db)
{
	Jelolt* i = jeloltekListaja;
	while (i != nullptr)
	{
		if (i->getNev() == nev) i->szavaz(db);
		i = i->getKovetkezo();
	}
}

//Egyszer� lista v�g�gj�r�s, minden jel�ltre leadott szavazatot �sszegz�nk, a v�g�n egy oszt�ssal (musz�j doble-t haszn�lni k�l�nben eg�sz oszt�s lenne)
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

//Maximumkeres�s l�ncolt list�ban
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
		if(i->getPart() == part) partSzavazat += i->getSzavazatokSzama(); //Ha adott p�rt tagja, akkor a p�rtra leadott szavazatok sz�m�t n�velj�k
		osszSzavazat += i->getSzavazatokSzama(); //Minden k�pvisel�re leadott szavazat n�veli az �sszes leadott szavazatok sz�m�t
		i = i->getKovetkezo();
	}
	return (partSzavazat / osszSzavazat) * 100;
}

//Maximumkeres�s l�ncolt list�ban + 1 felt�tel
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