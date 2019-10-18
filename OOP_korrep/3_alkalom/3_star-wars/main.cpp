#include <iostream>

using namespace std;

#include "Karakter.h"
#include "Jedi.h"

int main() {
	Karakter* k = new Karakter("Jabba", 0);
	Jedi* j = new Jedi("Luke Skywalker", 95, false);

	Karakter* kj1 = new Jedi("Obi-wan Kenobi", 80, true);
	Karakter* kj2 = new Karakter("Jango Fett", 10);

	k->print();
	j->print();

	kj1->print();
	kj2->print();

	Jedi* temp1 = dynamic_cast<Jedi*>(kj1);
	Jedi* temp2 = dynamic_cast<Jedi*>(kj2);
	
	if (temp1 == nullptr) cout << "kj1 az egy Karakter" << endl;
	else cout << "kj1 az egy Jedi" << endl;

	if (temp2 == nullptr) cout << "kj2 az egy Karakter" << endl;
	else cout << "kj2 az egy Jedi" << endl;

	return 0;
}