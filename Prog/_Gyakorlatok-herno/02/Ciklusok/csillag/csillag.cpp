#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main(){
	//Kereszt:
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			//cout << (i == 10 || j == 10) ? "." : "*";
			if (i == 10 || j == 10) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}

	cout << "\n";
	//Csillag:
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//cout << (i == j) ? "." : "*";
			if (i == j || i + j + 1 == 20) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}

	char s;
	string t;
	ofstream f("szavak.txt");
	
	s = cin.get();
	while (s!='\n')
	{
		cin >> t;
		f << s+t << endl;
	}
	f.close();
}