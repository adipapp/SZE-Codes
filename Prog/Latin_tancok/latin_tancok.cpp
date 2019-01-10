#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Tanc
{
	string kategoria;
	string lany;
	string fiu;
	Tanc* kovetkezo;
};

struct Szotar{
	string nev;
	int db;
	Szotar* kovetkezo;
};

Tanc* utolsoElem(Tanc* elso){
	Tanc* akt = elso;
	while (akt->kovetkezo != NULL){
		akt = akt->kovetkezo;
	}
	return akt;
}


Tanc* beszur(Tanc* elso, string kategoria, string fiu, string lany){
	Tanc* uj = new Tanc;
	uj->kategoria = kategoria;
	uj->fiu = fiu;
	uj->lany = lany;
	uj->kovetkezo = NULL;
	if (elso == NULL) return uj;
	Tanc* akt = utolsoElem(elso);
	akt->kovetkezo = uj;
	return elso;
}

int tancDb(Tanc* elso, string tanc){
	int i = 0;
	Tanc* akt = elso;
	while (akt->kovetkezo != NULL){
		if (akt->kategoria == tanc) i++;
		akt = akt->kovetkezo;
	}
	return i;
}

string VilmaParja(Tanc* elso, string tanc){
	Tanc* akt = elso;
	while (akt != NULL){
		if (akt->lany == "Vilma" && akt->kategoria == tanc) return "A samba bemutaton Vilma parja " + akt->fiu + " volt.";
		akt = akt->kovetkezo;
	}
	return "Vilma nem tancolt "+tanc+"-t.";
}

Szotar* szotarbaBeszur(Szotar* elso, string nev){
	if (elso == NULL){
		Szotar* uj = new Szotar;
		uj->nev = nev;
		uj->db = 1;
		uj->kovetkezo = NULL;
		return uj;
	}
	Szotar* akt = elso;
	while (akt!=NULL)
	{
		if (akt->nev == nev){
			akt->db++;
			return elso;
		}
		if (akt->kovetkezo == NULL){
			Szotar* uj = new Szotar;
			uj->nev = nev;
			uj->db = 1;
			uj->kovetkezo = NULL;
			akt->kovetkezo = uj;
		}
		akt = akt->kovetkezo;
	}
	return elso;
}

Szotar* statisztika(Tanc* lista, Szotar* elso, bool lanyt){
	Tanc* akt = lista;
	while (akt!=NULL)
	{
		elso = szotarbaBeszur(elso, lanyt ? akt->lany : akt->fiu);
		akt = akt->kovetkezo;
	}
	return elso;
}

//find(begin(*tomb), end(*tomb), elem) == end(*tomb)

void listaz(Tanc* elso, Szotar* fiuk, Szotar* lanyok){
	ofstream f("szereplok.txt");
	if (f.is_open()){
		f << "Lanyok: ";
		Szotar* akt = lanyok;
		while (akt != NULL){
			f << akt->nev << ", ";
			akt = akt->kovetkezo;
		}

		akt = fiuk;
		f << "\nFiuk: ";
		while (akt != NULL){
			f << akt->nev << ", ";
			akt = akt->kovetkezo;
		}
	}
	else cout << "Fajlt nem sikerult letrehozni";
	f.close();
}

string maximumKeresSzotarban(Szotar* elso){
	Szotar* akt = elso;
	string maxnev;
	int maxdb=0;
	while (akt!=NULL)
	{
		if (akt->db >= maxdb){
			maxnev = akt->nev;
			maxdb = akt->db;
		}
		akt = akt->kovetkezo;
	}
	return maxnev;
}

void main(){
	Tanc* lista = NULL;
	ifstream f("tancrend.txt");
	if (f.is_open()){
		while (!f.eof())
		{
			string kategoria, fiu, lany;
			getline(f, kategoria);
			getline(f, lany);
			getline(f, fiu);
			if (kategoria != "" && fiu != "" && lany != "") lista = beszur(lista, kategoria, fiu, lany);
		}
	}
	else{ cout << "Nem nyithato meg a fajl!"; }
	f.close();

	cout << "2. feladat:\nElso tanc: " << lista->kategoria << "\nUtolso tanc: " << utolsoElem(lista)->kategoria << endl;

	cout << "3. feladat\nA sambat bemutatott parok szama: " << tancDb(lista, "samba") << endl;

	cout << "4. feladat:\nVilma a kovetkezo tancokban szerepelt:" << endl;
	Tanc* akt = lista;
	string tancok[6];
	int i = 0;
	while (akt != NULL){
		if (akt->lany == "Vilma" && find(begin(tancok), end(tancok), akt->kategoria) == end(tancok))
		{ 
			tancok[i] = akt->kategoria;
			i++;
		}
		akt = akt->kovetkezo;
	}
	for each (string var in tancok) if (var != "") cout << var << endl;

	cout << "5. feladat:\nAdjon meg egy tancot: ";
	string tanc;
	cin >> tanc;
	cout << VilmaParja(lista, tanc)<<endl;

	Szotar* fiukLista = NULL;
	Szotar* lanyokLista = NULL;
	fiukLista = statisztika(lista, fiukLista, false);
	lanyokLista = statisztika(lista, lanyokLista, true);
	listaz(lista, fiukLista, lanyokLista);

	cout << "7. feladat:\nA legtobbszor szereplo fiu(k): " << maximumKeresSzotarban(fiukLista) << "\nA legtobbszor szereplo lany(ok): " << maximumKeresSzotarban(lanyokLista) << endl;
}