#ifndef VALASZTASIRENDSZER_H
#define VALASZTASIRENDSZER_H

#include <string>

#include "Jelolt.h"

using namespace std;

class Valasztasirendszer
{
public:
	Valasztasirendszer();
	~Valasztasirendszer();

	void jeloltHozzaad(Jelolt* ujJelolt);
	void jeloltTorol(string nev);
	bool jeloltKeres(string nev);
	void jelolteketListaz();

private:
	Jelolt* jeloltekListaja;
};



#endif // !VALASZTASIRENDSZER_H

