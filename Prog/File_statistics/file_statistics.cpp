#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

struct Record
{
	char letter;
	int count;
};

#define ALPHABET 26

Record* initialize(){
	Record* statistics = new Record[ALPHABET];
	Record init;
	init.count = 0;
	for (int i = 0; i < ALPHABET; i++)
	{
		init.letter = (char)('a' + i);
		statistics[i] = init;
	}
	return statistics;
}

bool readfromfile(Record statistics[], char* filename){
	ifstream f(filename);
	if (f.is_open()){
		while (!f.eof())
		{
			char temp = f.get();
			if (isalpha(temp)){
				temp = tolower(temp);
				statistics[temp - 'a'].count++;
			}
		}
		f.close();
		return true;
	}
	else {
		cout << "Nem sikerult a kovetkezo fajlt megnyitni: " << filename;
		f.close();
		return false;
	}
}

int mostfrequentletterindex(Record statistics[]){
	int maxindex = 0;
	for (int i = 1; i < ALPHABET; i++)
	{
		if (statistics[i].count>statistics[maxindex].count) maxindex = i;
	}
	return maxindex;
}

void drawstatistics(Record statistics[], int mfli){
	double max = (double)statistics[mfli].count/10;
	for (int i = 0; i < ALPHABET; i++)
	{
		cout << statistics[i].letter << " ";
		double stars = round((double)statistics[i].count / max);
		if (i != mfli&&stars == 10)stars -= 1;
		for (int j = 1; j <= stars; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}

void writetofile(Record statistics[], int mfli, char* infilename, char* outfilename){
	ofstream f(outfilename);
	double max = (double)statistics[mfli].count / 10;
	for (int i = 0; i < ALPHABET; i++)
	{
		f << statistics[i].letter << " ";
		double stars = round((double)statistics[i].count / max);
		for (int j = 1; j <= stars; j++)
		{
			f << '*';
		}
		f << endl;
	}
	f << infilename << endl;
	f.close();
}

void main(int argc, char* argv[]){
	Record* statistics = initialize();
	//cout << statistics[17].letter;
	//argc = 2;
	//argv[1] = "szoveg.txt";
	if (argc == 1 || argc > 3){
		cout << "Hiba, rossz parameterezes!\n./File_statistics elemzendo_fajl_neve.kit [eredmeny_kimenetei_fajl.kit]";
	}
	else if (readfromfile(statistics, argv[1])){
		int mfli = mostfrequentletterindex(statistics);
		cout << "A legtobbszor elofordulo betu: " << statistics[mfli].letter << ", elofordulasok szama: " << statistics[mfli].count << endl;
		drawstatistics(statistics, mfli);
		if (argc == 3) writetofile(statistics, mfli, argv[1], argv[2]);
	}
	
	delete[] statistics;
}