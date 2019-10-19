#include <iostream>
#include <string>

#include "Jelolt.h"
#include "Valasztasirendszer.h"

using namespace std;

int main() {
	string partok[] = { "Csalok bandaja", "Narancsvidek", "Az MSZMP orok", "fuggetlen" };
	int keruletek[] = { 42, 51, 69 };

	Valasztasirendszer vr = Valasztasirendszer(500);

	Jelolt* j1 = new Jelolt("Kozpenz Karoly", partok[1], keruletek[2], 3);
	Jelolt* j2 = new Jelolt("Kokler Joska", partok[0], keruletek[2]);

	j2->szavaz(100);

	vr.jeloltHozzaad(j1);
	vr.jeloltHozzaad(j2);

	vr.jelolteketListaz();  cout << endl;

	if (vr.jeloltKeres("Kokler Joska")) {
		cout << "Megtalaltam!" << endl;
	}
	else {
		cout << "Sorry, korrupcio miatt mar bortonben" << endl;
	}

	vr.jeloltHozzaad(new Jelolt("Kadar Janos", partok[2], keruletek[1]));
	vr.jeloltHozzaad(new Jelolt("Rakosi Matyas", partok[2], keruletek[0], 11));
	vr.jeloltHozzaad(new Jelolt("Dakota Torzsfonok", partok[1], keruletek[2]));
	vr.jeloltHozzaad(new Jelolt("Cserepes Virag", partok[0], keruletek[0], 9));
	vr.jeloltHozzaad(new Jelolt("Vegh Bela", partok[0], keruletek[1], 32));
	vr.jeloltHozzaad(new Jelolt("Beviz Elek", partok[2], keruletek[0], 28));

	vr.jelolteketListaz();  cout << endl;

	vr.jeloltreSzavaz("Kadar Janos", 111);

	vr.jeloltTorol("Kokler Joska");

	if (vr.jeloltKeres("Kokler Joska")) {
		cout << "Megtalaltam!" << endl;
	}
	else {
		cout << "Sorry, korrupcio miatt mar bortonben" << endl;
	}

	vr.jelolteketListaz(); cout << endl;

	cout << "Szavazasra jogosult: " << vr.getSzavazasraJogosultak() << " fo" << endl;
	cout << "A reszveteli arany avagy erdekesebb volt-e a Forma-1-et nezni szavazas helyett: " << vr.reszveteliArany() << "%" << endl;
	cout << "A gyoztes jelolt aki a legtobbet lophat 4 evig: " << vr.gyoztesJelolt() << endl;  cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << partok[i] << " part a szavazatok ennyi szazalekat kapta: " << vr.partSzavazatok(partok[i]) << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << keruletek[i] << ". valsztokeruletben a gyoztes: " << vr.korzetSzavazatok(keruletek[i]) << endl;
	}

	return 0;
}