#include <iostream>
#include <math.h>
#include <string>
using namespace std;

struct  Koord
{
	double szelesseg, hosszusag;
};

struct Varos
{
	string varosnev;
	Koord pozicio;
};

void Kiir(Koord hely){
	if (hely.szelesseg >= 0) cout << "Eszaki szelesseg: " << hely.szelesseg << endl;
	else cout << "Deli szelesseg: " << hely.szelesseg << endl;
	if (hely.hosszusag >= 0) cout << "Keleti szelesseg: " << hely.hosszusag << endl;
	else cout << "Nyugati szelesseg: " << hely.hosszusag << endl;
}

Koord Kozeppont(Koord egyik, Koord masik){
	Koord kozep;
	kozep.szelesseg = (egyik.szelesseg + masik.szelesseg) / 2;
	kozep.hosszusag = (egyik.hosszusag + masik.hosszusag) / 2;
	return kozep;
}

double Tavolsag(Koord egyik, Koord masik){ //Kisbetuvel illik
	double szel = masik.szelesseg - egyik.szelesseg;
	double hossz = masik.hosszusag - egyik.hosszusag;
	return sqrt(pow(szel, 2) + pow(hossz, 2));
}

int Legeszakibb(Varos cities[], int db){
	int maxindex = 0;
	for (int i = 1; i < db; i++)
	{
		if (cities[i].pozicio.szelesseg>cities[maxindex].pozicio.szelesseg) maxindex = i;
	}
	return maxindex;
}

int Legkozelebbi(Varos city, Varos cities[], int db){ //city-hez legkozelebbi varos indexe a cities tombbol
	int minindex = 0;
	for (int i = 1; i < db; i++)
	{
		if (Tavolsag(city.pozicio, cities[i].pozicio) < Tavolsag(city.pozicio, cities[minindex].pozicio)) minindex = i;
	}
	return minindex;
}

void main(){
	Koord hely; //Struktúra deklarációja
	hely = { 0, 0 }; //Struktúra definíciója
	Koord helyek[3] = { { 12.3, -8 }, { -98, 0 }, { -36, 254.9 } }; //Struktúra tömb
	for (int i = 0; i < 3; i++) Kiir(helyek[i]);

	cout << "\n";
	Kiir(Kozeppont(helyek[0], helyek[1]));

	cout << "\n";
	cout << "A ket elso koordinata tavolsaga: " << Tavolsag(helyek[0], helyek[1]);

	Varos varosok[3];
	varosok[0].varosnev = "Gyor";
	varosok[0].pozicio = hely;
	varosok[1] = { "Budapest", helyek[0] };
	varosok[2] = { "London", {91,-31.12} };

	cout << "\n";
	int db = sizeof(varosok) / sizeof(Varos);
	int index = Legeszakibb(varosok, db);
	cout << "A legeszekibb varos: " << varosok[index].varosnev;

	cout << "\n";
	Varos city = { "Sopron", { -123, -0.12 } };
	cout << "Egy varoshoz legkozelebbi masik varos: " << varosok[Legkozelebbi(city, varosok, db)].varosnev;
	/*cout << "Kerem a szelessegi fokot: ";
	cin >> hely.szelesseg;
	cout << "Kerem a hosszusagi fokot: ";
	cin >> hely.hosszusag;*/
}