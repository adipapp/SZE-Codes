#include <iostream>

#include "Lakas.h"
#include "Alberlet.h"

using namespace std;

int main() {
	Lakas* l = new Lakas("9021 Gyor, Szechenyi ter 34.", 54, 120000);
	l->elad("Kiss Janos");
	l->elad("Kovacs Agnes");
	l->elad("Joó Laszlo");
	l->elad("Varga Denes");
	l->elad("Lengyel Bela");
	l->elad("Poor Tamas");
	cout << "A lakas erteke: " << l->vetelar() << endl;

	Lakas* a = new Alberlet("9021 Gyor, Szechenyi ter 34.", 54, 120000);
	a->elad("Tamas Gabor");
	a->szerzodik("Nagy Fruzsina");
	a->szerzodik("Nemeth Dora");
	a->szerzodik("Keri Robert");
	a->elad("Agoston Jozsef");
	cout << "Az alberlet erteke: " << a->vetelar() << endl;

	return 0;
}