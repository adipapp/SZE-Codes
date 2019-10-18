#include <iostream>
#include "Ez.h"
using namespace std;

int main() {
	Ez e1 = Ez(12);
	Ez e2 = Ez(3);

	cout << e1.getE() << endl;
	cout << e2.getE() << endl;

	e2 = e1;
	//Ez e2 = e1;

	cout << e1.getE() << endl;
	cout << e2.getE() << endl;

	e1.setE(5);

	cout << e1.getE() << endl;
	cout << e2.getE() << endl;

	return 0;
}
