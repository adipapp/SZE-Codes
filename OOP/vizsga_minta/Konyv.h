#ifndef KONYV_H
#define KONYV_H

#include <string>

using namespace std;

class Konyv
{
public:
	Konyv(string szerzo, string cim, int kiadas_eve);
	virtual ~Konyv();
	string getSzerzo() const;
	string getCim() const;
	int getKiadas() const;
	virtual void print();
	virtual string format() const;
	
protected:
	string szerzo;
	string cim;
	int kiadas;
};

ostream & operator<<(ostream & cout, const Konyv& konyv);

#endif
