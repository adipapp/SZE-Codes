#include <iostream>

using namespace std;

struct Lista{
	int adat;
	Lista *kov;
};

//Lista l�trehoz�sa t�mbb�l
Lista *ListaLetrehoz(){
	int szamok[] = { 213, -756, 4, 1, 87, 2, -1 };
	Lista *eleje = NULL; //�res lista
	for (int i = 0; szamok[i] != -1; i++)//
	{
		Lista *uj = new Lista;
		uj->kov = eleje;
		uj->adat = szamok[i];
		eleje = uj;
	}
	return eleje; // a lista elej�nek mem�ric�me
}

void ListaKi�r(Lista *lista){
	for (Lista *iter = lista; iter != NULL; iter=iter->kov)
	{
		cout << "[" << iter->adat << "]\n";
	}
}

Lista *ListaElejere(Lista *eleje, int szam){
	Lista *uj = new Lista;
	uj->kov = eleje;
	uj->adat = szam;
	eleje = uj;
	return eleje;
}

Lista *ListaVegere(Lista *eleje, int adat){
	Lista *uj = new Lista;
	Lista *iter;
	uj->adat = adat;
	uj->kov = NULL;
	if (eleje == NULL) return uj;
	for (iter=eleje; iter->kov != NULL; iter = iter->kov); //�res ciklus, a ista v�g�t keresi
	iter->kov = uj;
	return eleje;
}

void Felszabadit(Lista *eleje){
	Lista *akt = new Lista;
	while (eleje != NULL){
		akt = eleje;
		eleje = eleje->kov;
		delete(akt);
		//Ern�.f�le megold�s:
		//Lista *kov = eleje->kov;
		//delete(eleje);
		//eleje=kov;
	}
}

//megoldas11lancoltalap.cpp
void main(){
	Lista *lista = ListaLetrehoz();
	cout << "A lista elemei:\n";
	ListaKi�r(lista);

	cout << "A lista vegere beszuras:\n";
	lista = ListaVegere(lista, 1000);
	ListaKi�r(lista);

	cout << "A lista elejere beszuras:\n";
	lista = ListaElejere(lista, 2000);
	ListaKi�r(lista);

	Felszabadit(lista);
}