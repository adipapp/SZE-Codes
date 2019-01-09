#include "Kotet.h"
#include <iostream>
#include <string>

using namespace std;

Kotet::Kotet(string szerzo_neve, string konyv_cime, int kiadas_eve, string sorozat_neve, int kotet_kotetszam)
	: Konyv::Konyv(szerzo_neve, konyv_cime, kiadas_eve), sorozat(sorozat_neve), kotetszam(kotet_kotetszam) {}

Kotet::~Kotet(){}

string Kotet::getSorozat() const {
	return sorozat;
}

int Kotet::getKotetszam() const {
	return kotetszam;
}

void Kotet::print() {
	cout << sorozat << "/" << kotetszam << ": " << szerzo << " - " << cim << " (" << kiadas << ")" << endl;
}

string Kotet::format() const
{
	return sorozat + "/" + to_string(kotetszam) + ": " + szerzo + " - " + cim + " (" + to_string(kiadas) + ")";
}