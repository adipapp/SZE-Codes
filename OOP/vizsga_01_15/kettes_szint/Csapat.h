#ifndef CSAPAT_H
#define CSAPAT_H

#include <string>
#include <vector>

using namespace std;

class Jatekos;

class Csapat
{
public:
	Csapat(string nev);
	string getName() const;
	void jatekosok() const;
	void leigazol(Jatekos* ujJatekos);

private:
	string nev;
	vector<Jatekos*> jatekosLista;
	void elad(Jatekos* eladottJatekos);
};

#endif