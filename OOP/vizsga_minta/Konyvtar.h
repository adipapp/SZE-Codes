#ifndef KONYVTAR_H
#define KONYVTAR_H

#include "Konyv.h"
#include "Kotet.h"

#include <list>

class Konyvtar
{
public:
	~Konyvtar();
	void add(Konyv*);
	void print();
	int db(string szerzo, string cim);
	void rendez();
	const Konyv* operator[](int idx);
	list<const Konyv*> operator[](string sorozatcim);

private:
	list<Konyv*> konyvek;
};

#endif

