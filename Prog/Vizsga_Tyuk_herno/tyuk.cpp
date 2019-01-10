#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

struct Allat{
	string tipus;
	int db;
	Allat* kovetkezo;
};

bool joAllat(string nev){
	int i = 0;
	for each (char item in nev)
	{
		if ((item >= 'A'&&item <= 'Z') || (item >= 'a'&&item <= 'z')) i++;
		else return false;
	}
	if (i >= 3 && i <= 15) return true;
	else return false;
}

bool joDb(int db){
	if (db >= 1 && db <= 40) return true;
	else return false;
}

Allat* beszur(Allat* elso, string tipus, int db){
	if (elso->tipus == ""){
		elso->tipus = tipus;
		elso->db = db;
		return elso;
	}

	Allat* akt = elso;
	while (akt->tipus != tipus && akt->kovetkezo != NULL) akt = akt->kovetkezo;
	if (akt->tipus == tipus) {
		akt->db += db;
		return elso;
	}

	Allat* uj = new Allat;
	uj->tipus = tipus;
	uj->db = db;
	uj->kovetkezo = NULL;
	akt->kovetkezo = uj;
	return elso;
}

Allat* beolvas(ifstream& file, Allat* elso){
	int i = 1;
	string tipus;
	int db;
	while (!file.eof())
	{
		string szo;
		file >> szo;
		switch (i % 3)
		{
		case 1: tipus = szo; break;
		case 2: db = stoi(szo); break;
		case 0: beszur(elso, tipus, db); break;
		}
		i++;
	}
	return elso;
}

void main(int argc, char* argv[]){
	cout << "Baromfik nyilvantartasa\n----------------------" << endl;
	Allat* elso = new Allat;
	elso->tipus = "";
	elso->db = 0;
	elso->kovetkezo = NULL;
	bool vege = false, sokadikinput = false;

	ifstream udvar("udvar.txt");
	if (udvar.is_open()) beolvas(udvar, elso);
	udvar.close();

	if (argc == 2){
		string arg = argv[1];
		ifstream inputfile(arg);
		if (inputfile.is_open()) beolvas(inputfile, elso); 
		inputfile.close();
	}

	while (!vege)
	{
		string tipus;
		int db;
		do
		{
			cout << "Kerem az allat tipusat: ";
			if (sokadikinput) cin.ignore();
			else sokadikinput = true;
			getline(cin, tipus);
			if (tipus.empty()) vege = true;
		} while (!joAllat(tipus) && !vege);
		if (vege) continue;
		do
		{
			cout << "Kerem az allat darabszamat: ";
			cin >> db;
		} while (!joDb(db));
		elso = beszur(elso, tipus, db);
	}

	ofstream f("udvar.txt");
	if (f.is_open() && elso->tipus!=""){
		Allat* akt = elso;
		while (akt!=NULL)
		{
			f << akt->tipus << "\t" << akt->db << " db\n";
			akt = akt->kovetkezo;
			delete(elso);
			elso = akt;
		}
	}
	f.close();
}