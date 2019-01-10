#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Termek
{
	string nev;
	int db;
	int ar;
	Termek* bal;
	Termek* jobb;
};

Termek* binfaKeres(Termek* gyoker, string nev, int db, int& keszletar){
	if (gyoker == NULL){
		gyoker = new Termek;
		gyoker->nev = nev;
		gyoker->db = db;
		gyoker->ar = 10 + rand() % 99991;
		gyoker->bal = gyoker->jobb = NULL;
	}
	else if (gyoker->nev > nev){
		gyoker->bal = binfaKeres(gyoker->bal, nev, db, keszletar);
	}
	else if (gyoker->nev < nev){
		gyoker->jobb = binfaKeres(gyoker->jobb, nev, db, keszletar);
	}
	else{
		gyoker->db += db;
		keszletar = gyoker->db*gyoker->ar;
	}
	return gyoker;
}

void binfaKiir(Termek* gyoker){
	if (gyoker != NULL){
		binfaKiir(gyoker->bal);
		cout << gyoker->nev << '\t' << gyoker->db << '\t' << gyoker->ar << endl;
		binfaKiir(gyoker->jobb);
	}
}

void binfaKivag(Termek* gyoker){
	if (gyoker != NULL){
		binfaKivag(gyoker->bal);
		binfaKivag(gyoker->jobb);
		delete gyoker;
	}
}

void main(){
	Termek* gyoker = NULL;
	string nev;
	int db, keszletar = 0;
	bool vege = false;
	srand(time(NULL));

	cout << "Raktarozas nyilvantartas\n--------------------"<<endl;
	do
	{
		cout << "\nAdjon meg egy termeknevet:"<<endl;
		getline(cin, nev); // getline tud whitespace-eket is olvasni(és ki is veszi õket a pufferbõl), de a cin önmagában nem
		if (nev != ""){ // ha nem entert(semmit/üres sort) olvasott be a getline
			cout << "\nAdja meg a fenti termek darabszamat: "<<endl;
			cin >> db; // cin után benntmarad a pufferben a sortörés
			cin.ignore(1); // ez kiveszi belõle
			gyoker = binfaKeres(gyoker, nev, db, keszletar);
			if (keszletar == 0) cout << "A termek nem szerepelt a nyilvantartasban, hozzaadasra kerult." << endl;
			else cout << "A termek szerepelt mar a nyilvantartasban, a tarolt keszlet erteke: " << keszletar << " Ft" << endl;
			keszletar = 0;
		}
		else break; //ez tudom hogy csúnya
	} while (true); //ez meg még csúnyább :)

	binfaKiir(gyoker);
	binfaKivag(gyoker);
}