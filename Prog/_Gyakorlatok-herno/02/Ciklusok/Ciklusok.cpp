// Írja ki az elsõ tíz természtes számot és azok négyzetét!

#include <iostream>
using namespace std;

void main(){
	int szam = 1;
	while (szam <= 10)
	{
		cout << szam << "\t" << pow(szam,2) << "\n";
		szam++;
	}
	getchar();
}