#include <iostream>

using namespace std;

#include "Karakter.h"
#include "Jedi.h"
#include "Sith.h"

int main() {
	Karakter* jedi1 = new Jedi("Luke Skywalker", 64, false);
	Karakter* jedi2 = new Jedi("Obi-wan Kenobi", 80, true);
	Karakter* jedi3 = new Jedi("Yoda", 99, true);
	Karakter* sith1 = new Sith("Darth Maul", 36);
	Karakter* sith2 = new Sith("The Emperor", 70, false);

	//Ha jól dolgoztok, ennek nem szabad mûködnie: (miért is? :))
	//Karakter* karakter = new Karakter("Jabba", 0);

	jedi2->print();
	jedi2->setEro(21);
	jedi2->print();
	jedi2->setEro(20);
	jedi2->print();

	sith1->print();
	dynamic_cast<Sith*>(sith1)->setGyengeseg(false); // Erre majd kitérünk következõ alkalommal
	sith1->print();

	cout << endl << "Harcol egymassal: (szabalyos harc)" << endl;
	jedi1->print();
	sith2->print();
	sith2->harc(jedi1);
	cout << "Harcot kovetoen: (az alabbi erok a random generalas miatt elterhetnek az enyemtol!)" << endl;
	jedi1->print();
	sith2->print();

	cout << endl << "Harcol egymassal: (szabalytalan harc)" << endl;
	jedi2->print();
	jedi3->print();
	jedi3->harc(jedi2);
	cout << "Harcot kovetoen: (az alabbiaknak viszont egyezniuk kell!)" << endl;
	jedi2->print();
	jedi3->print();

	return 0;
}