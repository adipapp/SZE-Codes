#include <fstream>
#include <iostream>
#include <string>

#include "BST.h"

using namespace std;

int main() {
	cout << "Helyesiras ellenorzo inditasa...\n";

	ifstream szotarf;
	string szfilename = "szotar.txt";
	cout << "Kerem a szotar fajl eleresi utvonalat!\n";
	//cin >> szfilename;
	szotarf.open(szfilename);
	if (!szotarf.is_open()) {
		cout << "Nem talalhato a szotar fajl!\n";
		return 1;
	}
	BST *szotar = NULL;
	while (!szotarf.eof()) {
		string szo;
		szotarf >> szo;
		if (szo != "") {
			// szo felvetele a szotarba
			szotar = beszur(szotar, szo);
		}
	}

	ifstream szovegf;
	string szovfname = "szoveg.txt";
	szovegf.open(szovfname);
	if (!szovegf.is_open()) {
		cout << "Nem talalhato a szoveg fajl!\n";
		return 1;
	}
	ofstream result;
	result.open("result.txt");
	if (!result.is_open()) {
		cout << "Nem sikerult a fajl letrehozasa!\n";
		return 1;
	}

	while (!szovegf.eof()) {
		string szo;
		szovegf >> szo;
		if (szo != "") {
			// szo megkeresese a szotarban
			if (!keres(szotar, szo)) {
				cout << szo << " nincs a szotarban!" << endl;
				for (int i = 0; i < szo.length(); i++)
					szo[i] = (char)toupper(szo[i]);
			}
			result << szo << ' ';
		}
	}
	result << endl;

	szotarf.close();
	szovegf.close();
	result.close();

	felszabadit(szotar);

	cout << "Helyesiras ellenorzes befejezodott.\n";

	return 0;
}