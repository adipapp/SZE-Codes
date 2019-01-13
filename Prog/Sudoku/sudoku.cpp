#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int table[9][9];

void readfromfile() {
	ifstream f("tabla.txt");
	if (f.is_open()) {
		int row = 0;
		while (!f.eof())
		{
			string s;
			getline(f, s);
			for (unsigned int col = 0; col < s.length(); col++)
			{
				if (isdigit(s[col])) table[row][col] = s[col] - '0';
				else table[row][col] = 0;
			}
			row++;
		}
	}
	f.close();
}

void print() {
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0) {
			for (int k = 0; k < 11; k++) cout << "*";
			cout << endl;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0 && j != 0) cout << "*";
			if (table[i][j] != 0) cout << table[i][j];
			else cout << ' ';
		}
		cout << endl;
	}
}

bool goodvalues(int row, int column, int value) {
	if (row + 1 < 1 || row + 1 - 1 > 9 || column + 1 < 1 || column + 1 > 9 || value + 1 < 1 || column + 1 > 9) return false;
	if (table[row][column] != 0) return false;

	for (int i = 0; i < 9; i++)
	{
		if (table[row][i] == value || table[i][column] == value) return false;
	}

	for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++)
	{
		for (int j = (column / 3) * 3; j < (column / 3) * 3 + 3; j++)
		{
			if (table[i][j] == value) return false;
		}
	}

	table[row][column] = value;
	return true;
}

bool finish() {
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) if (table[i][j] == 0) return false;
	return true;
}

void main() {
	readfromfile();
	cout << "Sudoku\nAdjon meg szamharmasokat kulon sorokba az [1, 9] intervallumban sor oszlop ertek sorrendben!\n";
	bool end = false;
	do
	{
		print();
		int r, c, v;
		do
		{
			cout << "\n----\n";
			cin >> r;
			cin >> c;
			cin >> v;
			if (r == 0 && c == 0 && v == 0) end = true;
		} while (!goodvalues(r - 1, c - 1, v) && !end);

		if (finish()) {
			cout << "Gratulalok On nyert!\n";
			end = true;
		}
	} while (!end);
	cout << "Jatek vege!";
}