#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class Matrix
{
public:
	Matrix(string nev) : nev(nev){}

	bool teljes() {
		int meret = sorok.front().size();
		/*for (int i = 0; i < sorok.size(); i++)
		{
			if (sorok[i].size() != meret) return false;
		}

		for (auto& i = sorok.begin(); i != sorok.end(); i++)
		{
			if (i.size() != meret) return false;
		}*/

		for (auto& i : sorok) {
			if (i.size() != meret) return false;
		}
		return true;
	}

	void beolvas(string fajlnev) {
		ifstream f(fajlnev);
		if (f.is_open()) {
			while (!f.eof())
			{
				string sor;
				getline(f, sor);
				sorok.push_back(sorfeldolgozo(sor));
			}
		}
		else {
			throw exception("A fajl megnyitasa sikertelen!");
		}
	}

	friend ostream& operator<<(ostream& cout, Matrix<T>& m) {
		cout << m.nev << endl;
		for (auto& s : m.sorok) {
			for (auto& e : s) {
				cout << e << " ";
			}
			cout << endl;
		}
		return cout;
	}

	void rendez1() {
		for (auto& s : sorok) {
			for (int i = s.size()-1; i > 0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if (s[j] > s[j + 1]) {
						T temp = s[j];
						s[j] = s[j + 1];
						s[j + 1] = temp;
					}
				}
			}
		}
	}

	void rendez2() {
		for (auto& s : sorok) {
			sort(s.begin(), s.end());
		}
	}

private:
	string nev;
	vector<vector<T>> sorok;

	vector<T> sorfeldolgozo(string sor) {
		istringstream ss(sor);
		vector<T> sorelemei;
		T temp;
		while (ss >> temp) sorelemei.push_back(temp);
		return sorelemei;
	}
};

#endif