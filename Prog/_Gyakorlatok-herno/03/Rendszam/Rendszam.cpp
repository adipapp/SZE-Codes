#include <iostream>
using namespace std;

void main(){
	//�rjon programot, amely egy string valid�ci�j�t v�gzi el.
	//A form�tum egyezzen meg a leggyakoribb magyar rendsz�m form�tum�val
	//7 karakter: els� 3 bet�, azt�n k�t�jel, majd az utols� 3 pedig sz�m(pl: SZE-001, abc-123)
	//A rendsz�mokat folyamatosan k�rj�k be
	//a program fut�sa 'k' bet� le�t�s�re fejez�dj�n be

	cout << "Rendszam ellenorzes"<<"\n";
	string s;
	bool ok = false;
	int i;
	while (s!="k")
	{
		cout << "Rendszam: ";
		cin >> s;
		if (s == "k"){
			cout << "A program futasanak vege";
		}
		else if (s.length() == 7){
			ok = true;
			for (i = 0; i < 3; i++) //bet�k ellen�rz�se
			{
				if (!isalpha(s[i])){
					ok = false; //i-edik bet� ellen�rz�se
					cout << "Hiba a betuknel: " << i + 1 << ". karakternel\n";
				}
			}
			if (s[i] != '-'){ //k�t�jel ellen�rz�se
				ok = false;
				cout << "Hiba a kotojelnel!\n";
			}
			for (i = 4; i < 7; i++)//sz�mok ellen�rz�se
			{
				if (!isdigit(s[i])){
					ok = false;
					cout << "Hiba a szamoknal: " << i + 1 << ". karakternel\n";
				}
			}
			if (ok){
				cout << "A " << s << "-ot elfogadtuk!";
			}
		}
		else{
			cout << "7 karakterbol kell allnia\n";
			ok = false;
		}
	}

	
}