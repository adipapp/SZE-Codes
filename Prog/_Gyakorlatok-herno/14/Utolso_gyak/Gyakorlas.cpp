#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct nevLista{
	string nev;
	unsigned int eletkor;
	double eredmeny;
	struct nevLista *kov;
};



bool ellenoriz(string nev){
	if (nev.length() < 5) return false;
	int i = 0;
	while (i < nev.length() && nev[i] != ' ') i++;
	return i < nev.length();
}

nevLista *listaRendezveBeszur(nevLista *elso, double eredmeny, string nev, unsigned int eletkor){
	nevLista *uj = new nevLista;
	uj->eredmeny = eredmeny;
	uj->eletkor = eletkor;
	uj->nev = nev;
	uj->kov = NULL;
	if (!elso) return uj;
	if (eredmeny < elso->eredmeny){ //beszúrjuk az elejére
		uj->kov = elso;
		return uj;
	}
	else
	{
		nevLista *akt = elso;
		while (elso->eredmeny < eredmeny && elso->kov->eredmeny <= eredmeny) elso = elso->kov;
		elso->kov = uj;
		uj->kov = elso->kov;
	}
	return elso;
}

nevLista *listaFeltolt(){
	nevLista* lista = new nevLista;
	ifstream be;
	be.open("verseny.txt");
	if (!be.is_open()){
		lista = listaRendezveBeszur(NULL, 118.0, "Ferenczy Ferenc", 21);//
		lista = listaRendezveBeszur(lista, 120.8, "Hirtelen Helga", 18);
		lista = listaRendezveBeszur(lista, 130.6, "Czenki Csaba", 20);
	}
	else{
		string nev;
		unsigned int kor;
		double eredmeny;
		getline(be, nev);
		if (nev.empty()) return lista;
		be >> kor >> eredmeny;
		be.ignore(1);
		lista = listaRendezveBeszur(lista, eredmeny, nev, kor);

	}
	return lista;
}

void kiir(nevLista *rekord){
	cout << rekord->nev << " " << rekord->eletkor << " " << rekord->eredmeny;
}

void top3Kiir(nevLista *elso){
	for (int i = 0; i < 3; i++, elso=elso->kov) kiir(elso);
}

bool legidosebbe(nevLista *elso){
	unsigned int gyozteskor = elso->eletkor;
	//nevLista *akt = elso->kov;
	while (elso&&elso->eletkor<=gyozteskor)
	{
		elso = elso->kov;
	}
}

void main(){
	nevLista *lista = listaFeltolt();
	
	string nev;
	unsigned int kor;
	double eredmeny;
	cout << "Adja meg a nevet!\n";

	do
	{
		top3Kiir(lista);
		//Név beolvasása
		getline(cin, nev);
		if (nev.empty()) break;
		if (!ellenoriz(nev)){
			cout << "Hibas nev!\n";
			continue; //újraindítja a ciklust
		}
		cout << "Adja meg az eletkort!\n";
		cin >> kor;
		cout << "Eredmeny:";
		cin >> eredmeny;
		cin.ignore(1);//Puffer ürítése
		cout << nev << kor << eredmeny;//teszt

		lista = listaRendezveBeszur(lista, eredmeny, nev, kor);
	} while (nev.length() > 0);

	ofstream ki;
	ki.open("verseny.txt");
	nevLista *akt = lista;
	while (akt)
	{
		ki << akt->nev << endl << akt->eletkor << " " << akt->eredmeny << endl;
		nevLista *temp = akt->kov;
		delete(akt);
		akt = akt->kov;
	}
}