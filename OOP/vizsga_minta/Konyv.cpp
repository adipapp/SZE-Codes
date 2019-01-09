#include "Konyv.h"
#include <string>
#include <iostream>

using namespace std;

Konyv::Konyv(string szerzo_neve, string konyv_cime, int kiadas_eve)
	: szerzo(szerzo_neve), cim(konyv_cime), kiadas(kiadas_eve) {}

Konyv::~Konyv(){}

string Konyv::getSzerzo() const {
	return szerzo;
}

string Konyv::getCim() const {
	return cim;
}

int Konyv::getKiadas() const
{
	return kiadas;
}

void Konyv::print() {
	cout << szerzo << " - " << cim << "(" << kiadas << ")" << endl;
}

string Konyv::format() const {
	return szerzo + " - " + cim + "(" + to_string(kiadas) + ")";
}

ostream & operator<<(ostream & cout, const Konyv& konyv)
{
	cout << konyv.format();
	return cout;
}
