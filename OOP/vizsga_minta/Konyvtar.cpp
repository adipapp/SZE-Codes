#include "Konyvtar.h"

Konyvtar::~Konyvtar()
{
	for (auto& i : konyvek)
	{
		delete i;
	}
}

void Konyvtar::add(Konyv* ujkonyv) {
	konyvek.push_back(ujkonyv);
}

void Konyvtar::print() {
	for (auto& i : konyvek)
	{
		i->print();
	}
}

int Konyvtar::db(string szerzo, string cim) {
	int db = 0;
	for (auto& i : konyvek)
	{ 
		if (i->getSzerzo() == szerzo && i->getCim() == cim) db++;
	}
	return db;
}

bool hasonlit(Konyv* a, Konyv* b) { // true ha b nagyobb, false ha a
	if (a->getSzerzo() < b->getSzerzo()) return true;
	else if (a->getSzerzo() == b->getSzerzo()) return a->getCim() < b->getCim();
	else return false;
}

void Konyvtar::rendez() {
	konyvek.sort(hasonlit);
}

const Konyv * Konyvtar::operator[](int idx)
{
	int id = 0;
	for (auto& i : konyvek) {
		if (id == idx) return i;
		id++;
	}
	return nullptr;
}

list<const Konyv*> Konyvtar::operator[](string sorozatcim)
{
	list<const Konyv*> talalatok;
	for (auto& i : konyvek)
	{
		Kotet* temp = dynamic_cast<Kotet*>(i);
		if (temp != nullptr && temp->getSorozat() == sorozatcim) talalatok.push_back(temp);
	}
	return talalatok;
}
