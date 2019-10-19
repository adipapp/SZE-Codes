#ifndef VALASZTASIRENDSZER_H
#define VALASZTASIRENDSZER_H

#include <string>

#include "Jelolt.h"

using namespace std;

class Valasztasirendszer
{
public:
	Valasztasirendszer(int szavJog);
	~Valasztasirendszer();

	void jeloltHozzaad(Jelolt* ujJelolt);
	void jeloltTorol(string nev);
	bool jeloltKeres(string nev);
	void jelolteketListaz();
	int getSzavazasraJogosultak() const;
	void jeloltreSzavaz(string nev, int db = 1);
	double reszveteliArany() const;
	string gyoztesJelolt() const;
	double partSzavazatok(string part) const;
	string korzetSzavazatok(int korzet) const;

private:
	Jelolt* jeloltekListaja;
	int szavazasraJogosultak;
};



#endif // !VALASZTASIRENDSZER_H

