#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template <class T>
class Matrix
{
public:
	void beolvas(string filename) {
		nev = filename;
		ifstream f(filename);
		if (!f.is_open()) cerr << "Problema a fajl megnyitasakor!";
		else {
			while (!f.eof())
			{
				string temp;
				getline(f, temp);
				sorfeldolgozo(temp);
			}
			f.close();
		}
	}

	friend ostream& operator<<(ostream& out, Matrix m) {
		if (!m.teljes()) cerr << "Nem teljes a " << m.nev << " matrix!" << endl;
		else m.kiir(out);
		return out;
	}

	void sort(bool compare(const map<int, T>& a, const map<int, T>& b)) {
		matrix.sort(compare);
	}

private:
	string nev;
	list<map<int, T>> matrix;

	void sorfeldolgozo(string sor) {
		T temp;
		int hanyadik = 0;
		map<int, T> myMap;
		string t = "";
		for (unsigned int i = 0; i < sor.length(); i++)
		{
			if (!isspace(sor[i])) t += sor[i];
			else {
				stringstream ss(t);
				ss >> temp;
				t = "";
				myMap[hanyadik] = temp;
				hanyadik++;
			}
		}
		stringstream ss(t);
		ss >> temp;
		t = "";
		myMap[hanyadik] = temp;
		matrix.push_back(myMap);
	}

	bool teljes() {
		int meret = matrix.front().size();
		for (auto i : matrix) {
			if (meret != i.size()) return false;
		}
		return true;
	}

	ostream& kiir(ostream& out) {
		out << nev << endl;
		for (auto i : matrix) {
			for (auto j : i) {
				out << j.second << " ";
			}
			out << endl;
		}
		return out;
	}
};
#endif // !MATRIX_H

