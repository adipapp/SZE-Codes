#include <iostream>
#include <string>

using namespace std;

struct Koord{
	double x, y;
};

struct Haromszog{
	Koord a, b, c;
};

//háromszögre mutatót kap, tükrözi az origóra, GTCreators
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
	//*haromszog az maga egy háromszög struktúra, haromszog pedig a memóriacím
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
	void* tipusnelkul; típus nélküli változóra mutat*/

	//int tomb[5] vagy int tomb[] = {0,0,0,0}
	int *array;
	cout << "Hany szamot fog megadni?";
	int meret;
	cin >> meret;
	int tomb[meret];
	int *tomb;
	//int* tomb, muatato => int *tomb,mutato szóval helyesen: int *tomb, *mutato; 
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