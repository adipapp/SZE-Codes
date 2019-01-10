#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct nevLista {
	string nev;
	unsigned int eletkor;
	double eredmeny;
	nevLista *kov;
};

bool ellenoriz(string nev) {
	if (nev.length() < 5)
		return false;
	int i = 0;
	while (i < nev.length() && nev[i] != ' ')
		i++;
	/*while (i < nev.length()) {
		if (nev[i] == ' ')
			return true;
	}
	return false;*/
	return i < nev.length();
}

nevLista *listaRendezveBeszur(nevLista *elso, double eredmeny, string nev, unsigned int eletkor) {
	nevLista *uj = new nevLista;
	uj->eredmeny = eredmeny;
	uj->nev = nev;
	uj->eletkor = eletkor;
	uj->kov = NULL;

	if (!elso) {
		return uj;
	}
	else {
		if (eredmeny < elso->eredmeny) { // beszurjuk az elejere
			uj->kov = elso;
			return uj;
		}
		else { // megkeressuk az utolsot, ami meg kisebb
			nevLista *akt = elso;
			while (akt->kov && akt->kov->eredmeny <= eredmeny) {
				akt = akt->kov;
			}
			uj->kov = akt->kov;
			akt->kov = uj;
		}
	}
	return elso;
}

nevLista *listaFeltolt() {
	nevLista *lista = NULL;

	ifstream be;
	be.open("verseny.txt");
	if (!be.is_open()) {
		lista = listaRendezveBeszur(NULL, 118.0, "Ferenczy Ferenc", 21);
		lista = listaRendezveBeszur(lista, 120.8, "Hirtelen Helga", 18);
		lista = listaRendezveBeszur(lista, 130.6, "Czenki Csaba", 20);
	}
	else {
		string nev;
		unsigned kor;
		double ido;
		while (!be.eof()) {
			getline(be, nev);
			if (nev.empty())
				return lista;
			be >> kor >> ido;
			be.ignore(1);
			lista = listaRendezveBeszur(lista, ido, nev, kor);
		}
	}
	return lista;
}

void kiir(nevLista *rekord) {
	cout << rekord->nev << " " << rekord->eletkor << " eves, ido: " << rekord->eredmeny << endl;
}

void top3kiir(nevLista *elso) {
	for (int i = 0; i < 3; i++, elso = elso->kov) {
		kiir(elso);
	}
}

bool legidosebbe(nevLista *elso) {
	nevLista *akt = elso->kov;
	while (akt && akt->eletkor <= elso->eletkor) {
		akt = akt->kov;
	}
	//return !akt;
	return akt == NULL;

	// maskeppen:
	while (akt) {
		if (akt->eletkor > elso->eletkor)
			return false;
		akt = akt->kov;
	}
	return true;
}

void legfiatalabbkiir(nevLista *elso) {
	nevLista *fiatal = elso;
	nevLista *akt = elso->kov;
	while (akt) {
		if (akt->eletkor < fiatal->eletkor)
			fiatal = akt;
		akt = akt->kov;
	}
	cout << "A legfiatalabb " << fiatal->nev << ", kora: " << fiatal->eletkor << " ev\n";
}

int main() {
	nevLista *lista = listaFeltolt();
	string nev;
	unsigned kor;
	double eredmeny;
	do {
		top3kiir(lista);
		// nev beolvasa
		cout << "Adja meg a nevet!\n";
		getline(cin, nev);
		if (nev.empty()) {
			break;
		}
		if (!ellenoriz(nev)) {
			cout << "Hibas nev!\n";
			continue;
		}
		cout << "Adja meg az eletkort!\n";
		cin >> kor;
		cout << "Adja meg az eredmenyt!\n";
		cin >> eredmeny;
		cin.ignore(1);

		// beszuras a listaba
		lista = listaRendezveBeszur(lista, eredmeny, nev, kor);
		legfiatalabbkiir(lista);
	} while (nev.length() > 0);
	if (legidosebbe(lista))
		cout << "A legidosebb nyert!\n";
	ofstream ki;
	ki.open("verseny.txt");
	nevLista *akt = lista;
	while (akt) {
		ki << akt->nev << endl << akt->eletkor << " " << akt->eredmeny << endl;
		nevLista *temp = akt->kov;
		delete akt;
		akt = temp;
	}
	return 0;
}
