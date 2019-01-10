#include <iostream>;
using namespace std;

void main(){
	cout << "Adja meg hogy hany soros legyen a Pascal haromszog: ";
	int n;
	cin >> n;

	int** pascal = new int*[n];
	for (int i = 0; i < n; i++)
	{
		pascal[i] = new int[i + 1]; //Soronk�nt i+1 db elem l�trehoz�sa
	}
	pascal[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		pascal[i][0] = 1; //Els� index csak pointereket tart., a m�sodik az adott sorra mutat� j-edik elem
		pascal[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}

	//Ki�rat�s
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << pascal[i][j] << " ";
		}
		cout << "\n";
		delete[] pascal[i]; //i-edik sor felszaba�t�sa
	}
	delete[] pascal; //A marad�k eg�sz pscal h�romsz�g felszabad�t�sa
}