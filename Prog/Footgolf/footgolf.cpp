#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Versenyzo
{
	string nev;
	bool kategoria_ferfi_e;
	string egyesulet;
	int pontok[8];
	Versenyzo* kovetkezo;
};

//struct Szotar
//{
//	string egyesulet;
//	int db;
//	Szotar* kovetkezo;
//};
//
//Szotar* szotaratLetrehozFeltolt(Versenyzo* lista){
//	Versenyzo* aktvers = lista;
//	Szotar* szotar = NULL;
//
//	while (aktvers!=NULL)
//	{
//		if (aktvers->egyesulet != "n.a."){
//			Szotar* aktszot = szotar;
//			while (aktszot->kovetkezo!=NULL)
//			{
//				if (aktszot->egyesulet == aktvers->egyesulet){
//					aktszot->db++;
//					break;
//				}
//				aktszot = aktszot->kovetkezo;
//			}
//			if (aktszot->egyesulet == aktvers->egyesulet) aktszot->db++;
//			else{
//				Szotar* uj = new Szotar;
//				uj->egyesulet = aktvers->egyesulet;
//				uj->db = 1;
//				uj->kovetkezo = NULL;
//				aktszot->kovetkezo = uj;
//			}
//		}
//		aktvers = aktvers->kovetkezo;
//	}
//	return szotar;
//}

Versenyzo* listabaBeszur(Versenyzo* elso, string sor){
	Versenyzo* uj = new Versenyzo;
	string splitted[11];
	string delimiter = ";";
	int pos = 0;
	for (int i = 0; i < 11; i++)
	{
		if (i == 10) splitted[i] = sor;
		else{
			pos = sor.find(delimiter);
			splitted[i] = sor.substr(0, pos);
			sor.erase(0, pos + delimiter.length());
		}
	}
	uj->nev = splitted[0];
	uj->kategoria_ferfi_e = splitted[1] != "Noi";
	uj->egyesulet = splitted[2];
	pos = 3;
	for (int i = 0; i < 8; i++, pos++) uj->pontok[i] = stoi(splitted[pos]);
	uj->kovetkezo = NULL;
	if (elso == NULL) return uj;
	Versenyzo* akt = elso;
	while (akt->kovetkezo!=NULL) akt = akt->kovetkezo;
	akt->kovetkezo = uj;
	return elso;
}

int nokSzama(Versenyzo* lista){
	Versenyzo* akt = lista;
	int nok = 0;
	while (akt!=NULL)
	{
		if (!akt->kategoria_ferfi_e) nok++;
		akt = akt->kovetkezo;
	}
	return nok;
}

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int osszpont(Versenyzo* versenyzo){
	if (versenyzo == NULL) return 0;
	int ossz = 0;
	for each (int var in versenyzo->pontok) ossz += var;
	qsort(versenyzo->pontok, 8, sizeof(int), compare);
	if (versenyzo->pontok[0] != 0) ossz += 10;
	if (versenyzo->pontok[1] != 0) ossz += 10;
	ossz = ossz - versenyzo->pontok[0] - versenyzo->pontok[1];
	return ossz;
}

void noiBajnokKiir(Versenyzo* lista){
	Versenyzo* akt = lista;
	Versenyzo* bajnok = NULL;
	while (akt != NULL)
	{
		if (!akt->kategoria_ferfi_e && osszpont(akt) > osszpont(bajnok)) bajnok = akt;
		akt = akt->kovetkezo;
	}
	cout << "6. feladat: A bajnok noi versenyzo\n\tNev: " << bajnok->nev << "\n\tEgyesulet: " << bajnok->egyesulet << "\n\tOsszpont: " << osszpont(bajnok) << endl;
}

void felszabadit(Versenyzo* lista){
	Versenyzo* akt = lista;
	lista = lista->kovetkezo;
	while (lista != NULL)
	{
		delete(akt);
		akt = lista;
		lista = lista->kovetkezo;
	}
	delete(akt);
}

void main(){
	int ossz = 0;
	Versenyzo* lista = NULL;
	ifstream f("fob2016.txt");
	if (f.is_open()){
		while (!f.eof())
		{
			string sor;
			getline(f, sor);
			lista = listabaBeszur(lista, sor);
			ossz++;
		}
	}
	else cout << "Nem sikerult a bemeneti fajlt megnyitni!!!";
	f.close();

	cout << "3. feladat: Versenyzok szama: " << ossz << endl;

	cout << "4. feladat: A noi versenyzok aranya: " << (double)nokSzama(lista) / ossz * 100 << "%" << endl;

	noiBajnokKiir(lista);

	ofstream out("osszpontFF.txt");
	if (out.is_open()){
		Versenyzo* akt = lista;
		while (akt!=NULL)
		{
			if (akt->kategoria_ferfi_e) out << akt->nev << ";" << osszpont(akt) << "\n";
			akt = akt->kovetkezo;
		}
	}
	else cout << "Kimeneti fajlt nem lehet megnyitni!!!";
	out.close();

	felszabadit(lista);
}