#ifndef JELOLT_H
#define JELOLT_H

#include <string>

using namespace std;

class Jelolt {
private:
	string nev;
	string part;
	int valasztoKerulet;
	int szavazatok;
	Jelolt* kovetkezo;

public:
	Jelolt(string jNev, string jPart, int jValasztoKerulet, int jSzavazatok = 0);

	string getNev() const;

	string getPart() const;

	int getValKer() const;

	int getSzavazatokSzama() const;

	Jelolt* getKovetkezo() const;

	void setKovetkezo(Jelolt* kovetkezo);

	~Jelolt();
};

#endif