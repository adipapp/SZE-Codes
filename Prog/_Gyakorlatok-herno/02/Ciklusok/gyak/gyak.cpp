#include <iostream>;
using namespace std;

void main(){
	// 1. feladat
	cout << "Elso feladat:\nfor\n";
	for (int i = 200; i >= 40; i -= 20)
	{
		cout << i << " ";
	}

	cout << "\nElso feladat:\nwhile\n";
	int j = 200;
	while (j >= 40)
	{
		cout << j << " ";
		j -= 20;
	}

	//2. feladat
	cout << "\nMasodik feladat:\nfor\n";
	for (int i = 100; i >= 40; i -= 20)
	{
		cout << i << "-" << i + 1 << " ";
	}

	cout << "\nMasodik feladat:\nwhile\n";
	int m = 100;
	while (m >= 40)
	{
		cout << m << "-" << m + 1 << " ";
		m -= 20;
	}
	cout << "\n";
}


