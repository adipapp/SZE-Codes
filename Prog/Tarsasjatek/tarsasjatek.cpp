#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Game
{
	string name;
	int min;
	int max;
	int played;
};

Game** readfromfile(char* filename, int& count){
	ifstream f(filename);
	Game** games = NULL;
	if (f.is_open()){
		Game* g = new Game;
		games = new Game*[100];
		int actcount = 0;
		while (!f.eof())
		{
			string s;
			f >> s;
			switch (actcount % 4)
			{
			case 0: g->name = s.substr(0, s.length() - 1); break;
			case 1: g->min = stoi(s.substr(0, s.length() - 1)); break;
			case 2: g->max = stoi(s.substr(0, s.length() - 1)); break;
			case 3: g->played = stoi(s); games[count] = g; g = new Game; count++; break;
			}
			actcount++;
		}
		
	}
	f.close();
	return games;
}

bool isdigitown(string s){
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i])) return false;
	}
	return true;
}

void writetoscreen(Game** games, int count){
	int wcount = 1;
	for (int i = 0; i < count; i++)
	{
		cout << wcount << ".\t" << games[i]->name << "\t" << games[i]->min << "\t" << games[i]->max << "\t" << games[i]->played << endl;
		wcount++;
	}
}

int writetoscreen2(Game** games, int count, int uservalue){
	int wcount = 1;
	for (int i = 0; i < count; i++)
	{
		if (games[i]->max >= uservalue&&games[i]->min <= uservalue){
			cout << wcount << ".\t" << games[i]->name << "\t" << games[i]->min << "\t" << games[i]->max << "\t" << games[i]->played << endl;
			wcount++;
		}
	}
	return wcount;
}

void rewritefile(char* filename, Game** games, int count){
	ofstream f(filename);
	for (int i = 0; i < count; i++)
	{
		f << games[i]->name << "; " << games[i]->min << "; " << games[i]->max << "; " << games[i]->played << endl;
	}
	f.close();
}

void main(int argc, char* argv[]){
	Game** games = NULL;
	int count = 0;
	if (argc == 2){
		if (!isdigitown(argv[1])){
			cout << "Hibas 2. parameter!" << endl;
			return;
		}
		games = readfromfile("tarsasjatek.txt", count);
	}
	else if (argc == 3){
		if (!isdigitown(argv[1])){
			cout << "Hibas 2. parameter!" << endl;
			return;
		}
		games = readfromfile("tarsasjatek.txt", count);
	}
	else{
		cout << "Hianyos parameterezes!";
		return;
	}
	if (games == NULL){
		cout << "Bemeneti fajl megnyitasi hiba!";
		return;
	}

	string s;
	bool vege = false;
	do
	{
		int wcount = writetoscreen2(games, count, stoi(argv[1]));
		//writetoscreen(games, count);
		cout << "Adja meg a fenti jatekok kozul egynek a sorszamat(amennyiben 0-at ad meg a fenti adatokkal a fajl felulirodik): ";
		cin >> s;
		if (isdigitown(s) && stoi(s) <= wcount && stoi(s) >= 1){
			games[stoi(s) - 1]->played++;
		}
		else if (isdigitown(s) && stoi(s) == 0){
			rewritefile(argc == 3 ? argv[2] : "tarsasjatek.txt", games, count);
			cout << "Kiirva fajlba!"<<endl;
			vege = true;
		}
	} while (!vege);
	delete[] games;
}