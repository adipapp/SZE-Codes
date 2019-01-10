#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define EV 2018;//Idei év konstansként

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
		int kor = rand() % 40;//0 és 40 közötti random egész szám
		Szemely *uj = new Szemely;
		uj->kov = eleje;
		uj->kor = kor;
		uj->szEv = EV - kor;
		uj->monogram = "X.X.";
		uj->monogram[0] = rand() % 26 + 'A';//1. X betû cseréje random betûre
		uj->monogram[2] = rand() % 26 + 'A';
		uj->magassag = double(1600 + rand() % 600) / 10; // 160-220 cm közötti random valós érték
	}
	return eleje;
}

void listaKiir(Szemely *elem){
	Szemely *iter;
	for (iter = elem; iter != NULL; iter=iter->kov)
	{
		cout << iter->monogram << " szuletett: " << iter->szEv << ", " << iter->magassag << " cm magas \n";
	} //Folyt. köv.
}

void main(){
	Szemely *lis = listaLetrehoz();
	cout << "Szemelyek:\n";
	listaKiir(lis);
}