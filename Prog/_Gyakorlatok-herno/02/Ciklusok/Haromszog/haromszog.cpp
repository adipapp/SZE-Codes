// Kerje be egy haromszog mind3 oldalhosszat! Ismetelje  az oldalak bekereset pozitiv egesz eretekekig!
// Vegul irja ki hogy a haromszog megszerkesztheto-e!
// Csak megszerkeszteheto esetben lepjen ki, kulonben kerjen ujat!

#include <iostream>;
using namespace std;

void main(){
	int a, b, c;
	cout << "Adja meg a haromszog oldalhosszait! Csak megszerkesztheto haromszoget ill. pozitiv ertekeket adjon meg!\n";
	do
	{
		cout << "\na = ";
		cin >> a;
		cout << "\nb = ";
		cin >> b;
		cout << "\nc = ";
		cin >> c;
	} while (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a);
	cout << "Helyes ertekek!\n";
}