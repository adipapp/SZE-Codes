#include <iostream>
#include "matrix.h"
using namespace std;

template <class T>
bool compare(const map<int, T>& a, const map<int, T>& b) {
	T sumA = a.begin()->second;
	T sumB = b.begin()->second;
	for (auto i: a) sumA += i.second;
	for (auto i : b) sumB += i.second;
	return (sumA-a.begin()->second) < (sumB-b.begin()->second);
}

int main() {
	Matrix<int> matrix;
	matrix.beolvas("1.txt");
	matrix.sort(compare<int>);
	cout << matrix << endl;

	Matrix<int> matrix2;
	matrix2.beolvas("2.txt");
	matrix2.sort(compare<int>);
	cout << matrix2 << endl;

	Matrix<char> matrix3;
	matrix3.beolvas("3.txt");
	matrix3.sort(compare<char>);
	cout << matrix3 << endl;

	return 0;
}