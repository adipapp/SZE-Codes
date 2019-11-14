#include <iostream>

#include "Lakas.h"
#include "Alberlet.h"
#include "Vector.h"

#include <vector>

using namespace std;

int main() {
	Lakas::setArPerNm(210000);

	Lakas* l = new Lakas("9021 Gyor, Szechenyi ter 34.", 54);
	l->elad("Kiss Janos");
	l->elad("Kovacs Agnes");
	l->elad("Joó Laszlo");
	l->elad("Varga Denes");
	l->elad("Lengyel Bela");
	l->elad("Poor Tamas");
	cout << "A lakas erteke: " << l->vetelar() << endl;

	Lakas* a = new Alberlet("9022 Gyor, Batthyany ter 5.", 45);
	a->elad("Tamas Gabor");
	//a->szerzodik("Nagy Fruzsina");
	//a->szerzodik("Nemeth Dora");
	//a->szerzodik("Keri Robert");
	a->elad("Agoston Jozsef");
	cout << "Az alberlet erteke: " << a->vetelar() << endl;

	//Lakas ll = Lakas(*l);
	//Alberlet aa = Alberlet(*a);
	
	delete l;
	delete a;

	Lakas lakas1("9021 Gyor, Szent Istvan u. 7.", 56);
	Lakas lakas2("9021 Gyor, Szent Istvan u. 8.", 57);
	Lakas lakas3("9021 Gyor, Szent Istvan u. 9.", 58);
	Lakas lakas4("9021 Gyor, Szent Istvan u. 10.", 59);
	cout << lakas1;

	Lakas* lakaspointer = new Lakas("9021 Gyor, Arpad u. 5.", 98);
	cout << lakaspointer;

	Vector<Lakas> v;
	cout << v.size() << endl;
	v.push(lakas1);
	v.push(lakas2);
	v.push(lakas3);
	v.push(lakas4);
	cout << v.size() << endl;
	cout << v[2];
	v.pop();
	cout << v.size() << endl;
	v.clear();
	cout << v.size() << endl << endl;

	Vector<int> vi;
	cout << v.size() << endl;
	vi.push(100);
	vi.push(50);
	vi.push(30);
	vi.push(10);
	cout << vi.size() << endl;
	cout << vi[2] << endl;
	vi.pop();
	cout << vi.size() << endl;
	vi.clear();
	cout << vi.size() << endl;

	vector<int> vv;

	vv.push_back(100);
	vv.pop_back();
	vv.size();

	return 0;
}