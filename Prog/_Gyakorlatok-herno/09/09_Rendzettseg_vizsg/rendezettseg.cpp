#include <iostream>;
using namespace std;

typedef enum{osszevissza, novekvo, csokkeno} SzigMon;

SzigMon Vizsgal(double *t, int meret){
	bool novo = true, csokken = true;
	for (int i = 0; i < meret-1; i++)
	{
		if (t[i]>t[i + 1]) novo = false;
		if (t[i]<t[i + 1]) csokken = false;
	}

	if (novo) return novekvo;
	if (csokken) return csokkeno;
	return osszevissza;
}

void main(){
	double t1[5] = { 5, 7, 10, 10, 76.1 };
	double t2[5] = { 56, 334, 10, 6.8, 6.1 };
	double t3[5] = { 5, 4, 110, 65.8, 76.1 };

	if (Vizsgal(t1, 5) == novekvo) cout << "t1 novekvo\n";
	if (Vizsgal(t2, 5) == csokkeno) cout << "t2 csokkeno\n";
	if (Vizsgal(t3, 5) == osszevissza) cout << "t3 osszevissza\n";
}