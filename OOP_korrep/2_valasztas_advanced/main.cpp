#include <iostream>
#include <string>

#include "Jelolt.h"
#include "Valasztasirendszer.h"

using namespace std;

int main() {
	Jelolt* f = new Jelolt("Fonok", "Csalok Bandaja", 51);
	Jelolt* j = new Jelolt("Kokler Joska", "Csalok Bandaja", 51);


	cout << (*j).getNev() << endl;
	cout << j->getPart() << endl;
	cout << j->getValKer() << endl;
	cout << j->getSzavazatokSzama() << endl;

	Valasztasirendszer vr = Valasztasirendszer();

	vr.jeloltHozzaad(j);
	vr.jeloltHozzaad(f);

	vr.jelolteketListaz();

	if (vr.jeloltKeres("hjsgadjhgadshj")) {
		cout << "Megtalaltam!" << endl;
	}
	else {
		cout << "Sorry, korrupcio miatt mar bortonben" << endl;
	}


	return 0;
}