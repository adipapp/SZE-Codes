#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int** initialize(int rows){
	int** bingo = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		bingo[i] = new int[5];
	}
	return bingo;
}

int** readfile(char* filename, int& rows){
	ifstream f(filename);
	string s;
	f >> s;
	rows = stoi(s);
	int** bingo = initialize(rows);
	int column = 0, row = 0;
	while (!f.eof())
	{
		f >> s;
		bingo[row][column] = stoi(s);
		column++;
		if (column % 5 == 0){
			row++;
			column = 0;
		}
	}
	f.close();
	return bingo;
}

bool wasnumber(int* chosennum, int num, int steps){
	if (chosennum == NULL) return false;
	for (int i = 0; i < steps; i++)
	{
		if (chosennum[i] == num) return true;
	}
	return false;
}

int generaterandomgood(int* chosennum, int steps){
	int r;
	do
	{
		r = 1 + rand() % 75;
	} while (wasnumber(chosennum, r, steps));
	return r;
}

int goodnumber(string s, int* chosennum, int steps){
	int num;
	for (unsigned int i = 0; i < s.length(); i++) if (!isdigit(s[i])) return -1;
	num = stoi(s);
	if (num == 0){
		int r = generaterandomgood(chosennum, steps);
		cout << "\nVeletlen szam: " << r << endl;
		return r;
	}
	if (num>75 || num < 1 || wasnumber(chosennum, num, steps)) return -1;
	return num;
}

void print(int** bingo, int* chosennum, int rows, int steps){
	char text[] = { 'B', 'I', 'N', 'G', 'O' };
	cout << endl;
	for each (char var in text) cout << setw(3) << var;
	cout << "\n --------------" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (!wasnumber(chosennum, bingo[i][j], steps)) cout << setw(3) << bingo[i][j];
			else cout << setw(3) << text[j];
		}
		cout << endl;
	}
}

int* success(int** bingo, int* chosennum, int num, int rows, bool& match, int steps){
	bool stop = false;
	for (int i = 0; i < rows && !stop; i++)
	{
		for (int j = 0; j < 5 && !stop; j++)
		{
			if (bingo[i][j] == num) stop = true;
		}
	}
	int* ext = new int[steps+1];
	int i = 0;
	for (; i < steps; i++)
	{
		ext[i] = chosennum[i];
	}
	ext[i] = num;
	delete[] chosennum;
	if(stop) match = true;
	return ext;
}

bool end(int** bingo, int* chosennum, int rows, int steps){
	//Sorok
	for (int i = 0; i < rows; i++)
	{
		if (wasnumber(chosennum, bingo[i][0], steps)){
			int j = 1;
			for (; j < 5; j++)
			{
				if (!wasnumber(chosennum, bingo[i][j], steps)) break;
			}
			if (j == 5) return true;
		}
	}

	//Foatlo menti
	for (int i = 0; i < rows-4; i++)
	{
		if (wasnumber(chosennum, bingo[i][0], steps)){
			int j = i+1, k = 1;
			for (; k < 5; j++, k++)
			{
				if (!wasnumber(chosennum, bingo[j][k], steps)) break;
			}
			if (k == 5) return true;
		}
	}
	//Mellekatlo menti
	for (int i = 4; i < rows; i++)
	{
		if (wasnumber(chosennum, bingo[i][0], steps)){
			int j = i - 1, k = 1;
			for (; k < 5; j--, k++)
			{
				if (!wasnumber(chosennum, bingo[j][k], steps)) break;
			}
			if (k == 5) return true;
		}
	}

	return false;
}

void deletebingo(int** bingo, int rows){
	for (int i = 0; i < rows; i++)
	{
		delete[] bingo[i];
	}
	delete[] bingo;
}

void main(int argc, char* argv[]){
	int rows = 0;
	int steps = 0;
	int** bingo;
	int* chosennum = NULL;
	srand(time(NULL));
	if (argc == 2) bingo = readfile(argv[1], rows);
	else bingo = readfile("bingo.txt", rows);
	print(bingo, chosennum, rows, steps);

	do
	{
		int num;
		string s;
		bool match = false;
		do
		{
			cout << "Adjon meg egy szamot: ";
			cin >> s;
		} while ((num=goodnumber(s,chosennum, steps))<0);
		chosennum = success(bingo, chosennum, num, rows, match, steps);
		steps++;
		print(bingo, chosennum, rows, steps);
		if (match) cout << "\nTalalt!" << endl;
		else cout << "\nNem talalt!" << endl;
	} while (!end(bingo, chosennum, rows, steps));
	cout << "Vege a jateknak On NYERT " << steps << " lepes utan\nKilepes..." << endl;
	deletebingo(bingo, rows);
}