#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Album
{
	string eloado;
	string cim;
	string kiado;
	int megjelenes;
	Album* kovetkezo;
};

Album* beszur(Album* elso, string eloado, string cim, string kiado, int megjelenes){
	Album* uj = new Album;
	uj->megjelenes = megjelenes;
	uj->cim = cim;
	uj->eloado = eloado;
	uj->kiado = kiado;
	uj->kovetkezo = NULL;
	if (elso == NULL) return uj;
	Album* akt = elso;
	while (akt->kovetkezo != NULL) akt = akt->kovetkezo;
	akt->kovetkezo = uj;
	return elso;
}

Album* rendezvebeszur(Album* elso, string eloado, string cim, string kiado, int megjelenes){
	Album* uj = new Album;
	uj->megjelenes = megjelenes;
	uj->cim = cim;
	uj->eloado = eloado;
	uj->kiado = kiado;
	uj->kovetkezo = NULL;
	if (elso == NULL || elso->cim >= cim){
		uj->kovetkezo = elso;
		elso = uj;
	}
	else
	{
		Album* akt = elso;
		while (akt->kovetkezo != NULL && akt->kovetkezo->cim <= cim) akt = akt->kovetkezo;
		if (akt->kovetkezo == NULL) akt->kovetkezo = uj;
		else{
			uj->kovetkezo = akt->kovetkezo;
			akt->kovetkezo = uj;
		}
	}
	return elso;
}

void kiir(Album* elso){
	Album* akt = elso;
	cout << "Eloado\tCim\tKiado\tMegjelenes" << endl << "-----------------------------------------------------" << endl;
	while (akt != NULL)
	{
		cout << akt->eloado << '\t' << akt->cim << '\t' << akt->kiado << '\t' << akt->megjelenes << endl;
		akt = akt->kovetkezo;
	}
}

void listaz(Album* elso, string eloado){
	Album* akt = elso;
	while (akt!=NULL)
	{
		if (akt->eloado == eloado) cout << akt->eloado << '\t' << akt->cim << '\t' << akt->kiado << '\t' << akt->megjelenes << endl;
		akt = akt->kovetkezo;
	}
}

Album* beolvas(char* fajlnev){
	Album* elso = NULL;
	ifstream f(fajlnev);
	if (f.is_open()){
		int i = 1;
		string cim, eloado, kiado, fajlnev;
		int megjelenes;
		while (!f.eof())
		{
			switch (i % 4)
			{
			case 1: f >> eloado; break;
			case 2: f >> cim; break;
			case 3: f >> kiado; break;
			case 0: f >> megjelenes; elso = rendezvebeszur(elso, eloado, cim, kiado, megjelenes); i = 0; break;
			}
			i++;
		}
		cout << "Fajl sikeresen beolvasva!";
	}
	else cout << "Fajlt nem sikerult megnyitni!"<<endl;
	f.close();
	return elso;
}

void fajlbakiir(Album* elso, const char* fajlnev){
	ofstream f(fajlnev);
	if (f.is_open()){
		Album* akt = elso;
		int i = 1;
		while (akt!=NULL)
		{
			switch (i%4)
			{
			case 1: f<<akt->eloado<<" "; break;
			case 2: f << akt->cim << " "; break;
			case 3: f << akt->kiado << " "; break;
			case 0: f << akt->megjelenes << endl; i = 0; akt = akt->kovetkezo; break;
			}
			i++;
		}
		cout << "Fajlba az adatok sikeresen kiirva!" << endl;
	}
	else cout << "A fajlt nem sikerult megnyitni, az adatok sajnos elvesztek!" << endl;
	f.close();
}

void felszabadit(Album* elso){
	Album* akt = elso;
	while (akt!=NULL)
	{
		elso = akt->kovetkezo;
		delete akt;
		akt = elso;
	}
}

void main(int argc, char* argv[]){
	Album* lista = NULL;
	if (argc == 2) lista = beolvas(argv[1]);
	string cim, eloado, kiado, fajlnev, megjelenes;
	int db = 0;

	do
	{
		cout << "Adja meg az eloadot(ures sor eseten befejez):" << endl;
		getline(cin, eloado);
		if (eloado == "") continue;
		cout << "Adja meg az album cimet:" << endl;
		getline(cin, cim);
		cout << "Adja meg a kiadot:" << endl;
		getline(cin, kiado);
		cout << "Adja meg a megjelenes evet:" << endl;
		getline(cin, megjelenes);
		lista = rendezvebeszur(lista, eloado, cim, kiado, stoi(megjelenes));
		db++;
	} while (db<5 || eloado!="");

	kiir(lista);
	cout << "Adja meg az eloado nevet, amelynek albumait szeretne listazni:" << endl;
	getline(cin, eloado);
	listaz(lista, eloado);
	cout << "\nHa szeretne kiirni fajba az eddigi adatokat, adja meg a fajlnevet(ures sor eseten nem irja ki): "<<endl;
	getline(cin, fajlnev);
	if (fajlnev != "") fajlbakiir(lista, fajlnev.c_str());
	felszabadit(lista);
}