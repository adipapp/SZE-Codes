// �rja ki az els� t�z term�sztes sz�mot �s azok n�gyzet�t!

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