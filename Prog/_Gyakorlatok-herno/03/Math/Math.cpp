#include <iostream>
#include <cmath> //Math oszt�ly
using namespace std;

void main(){
	double d;
	d = 121.87;
	cout << sqrt(d) << "\n" << pow(2,10) <<"\n";

	for (d= 1; d <= 10; d++) cout << pow(2, d) <<"\n"; //2 hatv�nyai
	
	/*for (d = -4; d < 3.14; d+=0.1)
	{
		cout << d << "\t" << abs(d) << "\t" << sin(d) << "\n";
	}*/
	
	for (d = 0.5; d  < 8.5; d+=1.2)
	{
		cout << d << "\t" << round(d) << "\t" << int(d) << "\n";
		//int()-tel t�puskoverzi� double-b�l int-t�

	}
	d = 121.1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 28*sin(d)+28; j++)
		{
			cout << "*";
		}
		d += 0.1;
		cout << "\n";
	}

	//Olvassuk be a b �s c egy�tthat�kat szabv�ny bemenetr�l
	//Amennyiben a bel�l�k alkotott m�sodfok� egyenletnek van megold�sa, akkor �rjuk ki
	//K�l�nben pedig "Az egyenletnek nincs val�s megold�sa" sz�veget �rjuk ki

	cout << "\nMasodfoku egyenlet megoldasa";
	int a, b, c;
	double D;
	cout << "\na = ";
	cin >> a;
	cout << "\nb = ";
	cin >> b;
	cout << "\nc = ";
	cin >> c;
	D = pow(b, 2) - 4 * a * c;
	if (D > 0){
		cout << "\nx1 = " << ((-b + sqrt(D)) / (2 * a));
		cout << "\nx2 = " << ((-b - sqrt(D)) / (2 * a));
	}
	else if (D == 0){
		cout << "\nx = " << ((-b) / (2 * a));
	}
	else{
		cout << "\n" << "Nincs valos megoldasa az egyenletnek";
	}
}