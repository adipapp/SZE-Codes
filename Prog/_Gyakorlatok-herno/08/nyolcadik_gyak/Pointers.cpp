#include <iostream>
#include <string>

using namespace std;

struct Koord{
	double x, y;
};

struct Haromszog{
	Koord a, b, c;
};

//h�romsz�gre mutat�t kap, t�kr�zi az orig�ra, GTCreators
void Tukroz(Haromszog *haromszog){
	haromszog->a.x *= -1;
	haromszog->a.y *= -1;
	haromszog->b.x *= -1;
	haromszog->b.y *= -1;
	haromszog->c.x *= -1;
	haromszog->c.y *= -1;
	Haromszog tukorkep;
	*haromszog = tukorkep;
	//(*haromszog).a == h->a
	//*haromszog az maga egy h�romsz�g strukt�ra, haromszog pedig a mem�riac�m
}

void negyzetreEmel(double *szam){
	*szam = (*szam) * (*szam);
}


void Eltolas(Haromszog *h, Koord eltol){
	h->a.x += eltol.x;
	h->a.y += eltol.y;
	h->b.x += eltol.x;
	h->b.y += eltol.y;
	h->c.x += eltol.x;
	h->c.y += eltol.y;
}

void Main()
{
	/*int valt; intre mut.
	int* mutato;
	string* nevmutato;
	void* tipusnelkul; t�pus n�lk�li v�ltoz�ra mutat*/

	//int tomb[5] vagy int tomb[] = {0,0,0,0}
	int *array;
	cout << "Hany szamot fog megadni?";
	int meret;
	cin >> meret;
	int tomb[meret];
	int *tomb;
	//int* tomb, muatato => int *tomb,mutato sz�val helyesen: int *tomb, *mutato; 
	tomb = new int[meret];

	/*Haromszog *hmut = new Haromszog;
	Haromszog *hmut;
	if () hmut = new Haromszog;*/
	Haromszog *hmut = new Haromszog;
	delete hmut;
	delete[] tomb;

	for (int i = 0; i < meret; i++)
	{
		cin >> tomb[i];
	}

}