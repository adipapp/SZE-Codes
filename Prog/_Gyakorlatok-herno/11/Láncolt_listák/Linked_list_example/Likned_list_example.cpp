#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define EV 2018;//Idei �v konstansk�nt

struct Szemely{
	string monogram;
	int kor;
	int szEv;
	double magassag;
	Szemely *kov;
};

Szemely *listaLetrehoz(){
	Szemely *eleje = NULL;
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		int kor = rand() % 40;//0 �s 40 k�z�tti random eg�sz sz�m
		Szemely *uj = new Szemely;
		uj->kov = eleje;
		uj->kor = kor;
		uj->szEv = EV - kor;
		uj->monogram = "X.X.";
		uj->monogram[0] = rand() % 26 + 'A';//1. X bet� cser�je random bet�re
		uj->monogram[2] = rand() % 26 + 'A';
		uj->magassag = double(1600 + rand() % 600) / 10; // 160-220 cm k�z�tti random val�s �rt�k
	}
	return eleje;
}

void listaKiir(Szemely *elem){
	Szemely *iter;
	for (iter = elem; iter != NULL; iter=iter->kov)
	{
		cout << iter->monogram << " szuletett: " << iter->szEv << ", " << iter->magassag << " cm magas \n";
	} //Folyt. k�v.
}

void main(){
	Szemely *lis = listaLetrehoz();
	cout << "Szemelyek:\n";
	listaKiir(lis);
}