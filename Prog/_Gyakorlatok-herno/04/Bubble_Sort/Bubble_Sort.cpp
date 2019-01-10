#include <iostream>
using namespace std;

void main(){
	int tomb[6];
	int n = sizeof(tomb) / sizeof(tomb[0]); // tömb elemszáma, sizeof: mekkora helyet foglal a memóriában
	cout << "A tomb elemszama: " << n << "\n";
	cout << "\n" << "Adja meg a tomb elemeit(6 db):";

	for (int i = 0; i < 6; i++)
	{
		cout << "\nx" << i + 1 << "= ";
		cin >> tomb[i];
	}
	
	cout << "\n" << "A kiindulo tomb:" << "\n";
	for (int i = 0; i < n; i++) cout << tomb[i] << "\t";
	int i = n - 1;

	while (i >= 1)
	{
		int k = 0;
		while (k < i)
		{
			if (tomb[k] > tomb[k + 1])
			{
				int csere = tomb[k];
				tomb[k] = tomb[k + 1];
				tomb[k + 1] = csere;
			}
			k++;
		}
		i--;
	}
	cout << "\n" << "A rendezett tomb:" << "\n";
	for each (int var in tomb) cout << var << "\t";


}