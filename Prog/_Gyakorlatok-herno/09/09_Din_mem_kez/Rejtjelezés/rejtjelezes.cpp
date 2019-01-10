#include <iostream>
#include <string>
using namespace std;

#define ABCMERETE 26

void main(){
	cout << "Kerem a kodszot: ";
	string kodszo;
	cin >> kodszo;
	for (int i = 0; i < kodszo.length(); i++)
	{
		kodszo[i] = toupper(kodszo[i]);//K�dsz� nagybet�ss� alak�t�sa
	}

	//Karakterek eltol�sa, honlapon le�r�s van hozz�
	char* tabla[ABCMERETE];
	for (int i = 0; i < ABCMERETE; i++)
	{
		tabla[i] = new char[kodszo.length()];
	}
	for (int oszlop = 0; oszlop < kodszo.length(); oszlop++)
	{
		int eltolas = kodszo[oszlop] - 'A';
		for (int sor = 0; sor < ABCMERETE; sor++)
		{
			while (eltolas < 0) eltolas += ABCMERETE;
			while (eltolas >= ABCMERETE) eltolas -= ABCMERETE;
			tabla[sor][oszlop] = 'A' + eltolas;
			eltolas++;
		}
	}

	//Ki�rat�s:
	for (int sor = 0; sor < ABCMERETE; sor++)
	{
		cout.put('A' + sor);
		cout << "|";
		for (int oszlop = 0; oszlop < kodszo.length(); oszlop++)
		{
			cout << tabla[sor][oszlop] << " ";
		}
		cout << "\n";
	}

	//Folytat�s, megold�ssal szint�n a honlaon!!!
}