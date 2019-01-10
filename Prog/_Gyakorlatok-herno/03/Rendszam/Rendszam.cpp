#include <iostream>
using namespace std;

void main(){
	//Írjon programot, amely egy string validációját végzi el.
	//A formátum egyezzen meg a leggyakoribb magyar rendszám formátumával
	//7 karakter: elsõ 3 betû, aztán kötõjel, majd az utolsó 3 pedig szám(pl: SZE-001, abc-123)
	//A rendszámokat folyamatosan kérjük be
	//a program futása 'k' betû leütésére fejezõdjön be

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
			for (i = 0; i < 3; i++) //betûk ellenõrzése
			{
				if (!isalpha(s[i])){
					ok = false; //i-edik betû ellenõrzése
					cout << "Hiba a betuknel: " << i + 1 << ". karakternel\n";
				}
			}
			if (s[i] != '-'){ //kötõjel ellenõrzése
				ok = false;
				cout << "Hiba a kotojelnel!\n";
			}
			for (i = 4; i < 7; i++)//számok ellenõrzése
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