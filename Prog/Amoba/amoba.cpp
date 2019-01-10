#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char** lefoglal(int meret){
	char** lepesek = new char* [meret];
	for (int i = 0; i < meret; i++)
	{
		lepesek[i] = new char[meret];
		for (int j = 0; j < meret; j++) lepesek[i][j] = '.';
	}
	return lepesek;
}

bool jolepes(int sor, string oszlop, int meret, char** lepesek){
	if (sor >= 1 && sor <= meret && oszlop.length() == 1 && oszlop[0] >= 'A' && oszlop[0] <= (char)('A' + meret - 1)
		&& lepesek[sor-1][oszlop[0] - 'A'] == '.') return true;
	return false;
}

void tablaKiir(char** lepesek, int meret){
	cout << "\n  ";
	for (int i = 0; i < meret; i++) cout << (char)('A' + i);

	for (int i = 0; i < meret; i++)
	{
		printf("\n%02d", i + 1);
		for (int j = 0; j < meret; j++)cout << lepesek[i][j];
	}
	cout << endl;
}

bool vege(char** lepesek, int meret){
	for (int i = 0; i < meret; i++)
	{
		for (int j = 0; j < meret-4; j++)
		{
			bool folytonos = true;
			if (lepesek[i][j] != '.'){
				for (int k = j+1; k < j+5 && folytonos; k++) if (lepesek[i][k] != lepesek[i][j]) folytonos = false;
				if (folytonos) return true;
			}
		}
	}

	for (int i = 0; i < meret-4; i++)
	{
		for (int j = 0; j < meret; j++)
		{
			bool folytonos = true;
			if (lepesek[i][j] != '.'){
				for (int k = i + 1; k < i + 5 && folytonos; k++) if (lepesek[k][j] != lepesek[i][j]) folytonos = false;
				if (folytonos) return true;
			}
		}
	}

	for (int i = 0; i < meret - 4; i++)
	{
		for (int j = 0; j < meret-4; j++)
		{
			bool folytonos = true;
			if (lepesek[i][j] != '.'){
				for (int k = i + 1, l=j+1; k < i + 5 && l < j+5 && folytonos; k++, l++) if (lepesek[k][l] != lepesek[i][j]) folytonos = false;
				if (folytonos) return true;
			}
		}
	}

	for (int i = 0; i < meret - 4; i++)
	{
		for (int j = meret-1; j > 4; j--)
		{
			bool folytonos = true;
			if (lepesek[i][j] != '.'){
				for (int k = i + 1, l = j - 1; k < i + 5 && l > j - 5 && folytonos; k++, l--) if (lepesek[k][l] != lepesek[i][j]) folytonos = false;
				if (folytonos) return true;
			}
		}
	}

	return false;
}

void felszabadit(char** lepesek, int meret){
	for (int i = 0; i < meret; i++) delete[] lepesek[i];
	delete[] lepesek;
}

void mentesFajlba(char** lepesek, int meret){
	ofstream f("amoba.txt");
	f << meret << endl;
	for (int i = 0; i < meret; i++)
	{
		for (int j = 0; j < meret; j++) f << lepesek[i][j];
		f << endl;
	}
	f.close();
}

char** betoltFajlbol(int& meret, int& foglaltmezokszama){
	char** lepesek;
	ifstream f;
	f.open("amoba.txt");
	if (f.is_open()){
		f >> meret;
		lepesek = new char*[meret];
		for (int i = 0; i < meret; i++)
		{
			lepesek[i] = new char[meret];
			for (int j = 0; j < meret; j++)
			{
				f>>lepesek[i][j];
				if (lepesek[i][j] != '.') foglaltmezokszama++;
			}
		}
	}
	else{
		lepesek = lefoglal(7);
		cout << "Nem sikerult a fajlt betolteni!";
	}
	f.close();
	return lepesek;
}

void main(int argc, char* argv[]){
	int meret;
	char** lepesek;
	int foglaltmezokszama = 0;
	cout << "Amoba jatek"<<endl;

	if (argc == 1){
		do
		{
			cout << "Adja meg a palya meretet a[7, 20] tartomanyban: ";
			cin >> meret;
		} while (meret<7 || meret>20);
		lepesek = lefoglal(meret);
	}
	else if(string(argv[1])=="betolt") lepesek = betoltFajlbol(meret, foglaltmezokszama);
	else{
		cout << "Ervenytelen kapcsolo!\nHasznalat: ./Amoba.exe [betolt]";
		return;
	}
	
	do
	{
		if (vege(lepesek, meret)) break;
		tablaKiir(lepesek, meret);
		int sor;
		string oszlop;
		do
		{
			if (foglaltmezokszama % 2 == 0) cout << "Elso jatekos lepese, sor: ";
			else cout << "Masodik jatekos lepese, sor: ";
			cin >> sor;
			cout << "Oszlop: ";
			cin >> oszlop;
		} while (!jolepes(sor,oszlop,meret,lepesek));
		lepesek[sor-1][oszlop[0] - 'A'] = foglaltmezokszama % 2 == 0 ? 'X' : 'O';
		mentesFajlba(lepesek, meret);
		foglaltmezokszama++;
	} while (foglaltmezokszama < meret*meret && !vege(lepesek, meret));
	tablaKiir(lepesek, meret);

	if (foglaltmezokszama == meret*meret) cout << "\nAz eredmeny: DONTETLEN, mivel betelt a tabla!";
	else if (foglaltmezokszama%2==1) cout << "\nAz eredmeny: ELSO JATEKOS GYOZOTT!";
	else cout << "\nAz eredmeny: MASODIK JATEKOS GYOZOTT!";

	felszabadit(lepesek, meret);
}