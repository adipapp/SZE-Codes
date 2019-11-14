#include <iostream>

#include "Matrix.h"

using namespace std;

int main() {
	Matrix<int> m1("Teljes int matrix");
	
	try
	{
		m1.beolvas("int1.txt");
		if (m1.teljes()) cout << "Teljes Matrix" << endl;
		else cout << "Nem teljes matrix" << endl;
		cout << m1 << endl;
		m1.rendez2();
		cout << m1 << endl;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}