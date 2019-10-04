#include <iostream>
#include <string>

#include "Jelolt.h"
//#include "MyClass.h"
//#include "MyClass1.h"

using namespace std;

int main() {
	//Jelolt j = Jelolt("Kokler Joska", "Csalok Bandaja", 51, 0);
	Jelolt j = Jelolt("Kokler Joska", "Csalok Bandaja", 51);
	
	//j.nev = "Kokler Joska";
	//j.part = "Csalok Bandaja";
	//j.valasztoKerulet = 51;
	//j.szavazatok = 1000000;

	cout << j.getNev() << endl;
	cout << j.getPart() << endl;
	cout << j.getValKer() << endl;
	cout << j.getSzavazatokSzama() << endl;
	return 0;
}