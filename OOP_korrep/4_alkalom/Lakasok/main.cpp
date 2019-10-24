#include <iostream>

#include "Lakas.h"
#include "Alberlet.h"

using namespace std;

int main() {
	Lakas::setArPerNm(210000);

	Lakas* l = new Lakas("9021 Gyor, Szechenyi ter 34.", 54);
	l->elad("Kiss Janos");
	l->elad("Kovacs Agnes");
	l->elad("Joó Laszlo");
	l->elad("Varga Denes");
	l->elad("Lengyel Bela");
	l->elad("Poor Tamas");
	cout << "A lakas erteke: " << l->vetelar() << endl;

	Lakas* a = new Alberlet("9022 Gyor, Batthyany ter 5.", 45);
	a->elad("Tamas Gabor");
	//a->szerzodik("Nagy Fruzsina");
	//a->szerzodik("Nemeth Dora");
	//a->szerzodik("Keri Robert");
	a->elad("Agoston Jozsef");
	cout << "Az alberlet erteke: " << a->vetelar() << endl;

	//Lakas ll = Lakas(*l);
	//Alberlet aa = Alberlet(*a);
	
	delete l;
	delete a;

	return 0;
}