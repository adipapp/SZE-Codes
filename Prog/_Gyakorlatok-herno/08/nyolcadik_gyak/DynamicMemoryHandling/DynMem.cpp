#include <iostream>
#include <string>

using namespace std;

#define START 1900
#define END 2000

struct Szamlalo{
	int ertek;
	int db;
};

void Main(){
	int jegyek[END - START + 1] = {0};//Maradékot nullával tölti fel
	Szamlalo *szamlalok = new Szamlalo[4];
	int db = 0;

	int jegy;
	/*do
	{
		cin >> jegy;
		if (START == jegy){
			if (jegy >= START && jegy <= END) jegyek[jegy - START]++;
			else if (jegy != 0) cout << "Ervenytelen!\n";
		}
	} while (jegy!=END);*/

	do
	{
		cin >> jegy;
		if (jegy == 0) break;
		int index = 0;
		while (index<db&&szamlalok[index].ertek!=jegy)
		{
			index++;
			if(index<db) szamlalok[index].db++;
			else
			{
				if (db == 4){ // tele van a tömb
					Szamlalo *ujtomb = new Szamlalo[2 * 4];
					for (int i = 0; i < db; i++)
					{
						ujtomb[i] = szamlalok[i];
					}
				}
				szamlalok[db].ertek = jegy;
				szamlalok[db].db = 1;
				db++;
			}

		}
	} while (jegy!=0);

	/*for (int i = 0; i <= END-START; i++)
	{
		if(jegyek[i]!=0) cout << i + START << " " << jegyek[i] << "db\n";
	}
	for (int i = START; i <= END; i++)
	{
		if (jegyek[i - START] != 0) cout << i + START << " " << jegyek[i - START] << "db\n";
	}*/

	for (int i = 0; i < db; i++)
	{
		cout << szamlalok[i].ertek << " " << szamlalok[i].db << "db\n";
	}
	delete[] szamlalok;
}