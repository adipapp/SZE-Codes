#ifndef KOTET_H
#define KOTET_H

#include "Konyv.h"
#include <string>

using namespace std;

class Kotet : public Konyv{
public:
	Kotet(string szerzo, string cim, int kiadas, string sorozat, int kotetszam);
	virtual ~Kotet();
	string getSorozat() const;
	int getKotetszam() const;
	virtual void print();
	virtual string format() const;

protected:
	string sorozat;
	int kotetszam;
};

#endif

