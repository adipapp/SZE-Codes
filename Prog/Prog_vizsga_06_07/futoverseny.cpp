#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Runner
{
	int number;
	int lastCheckPoint;
	int startInSeconds;
	int timeInSeconds;
	bool dqf;
};

Runner* initialize(int count){
	Runner* runners = new Runner[count];
	return runners;
}

int wasinarray(Runner* runners, int i, int number){
	for (int j = 0; j < i; j++)
	{
		if (runners[j].number == number) return j;
	}
	return -1;
}

Runner* readfromfile(string filename, int& count){
	ifstream f(filename);
	Runner* runners = NULL;
	if (f.is_open()){
		int a=1, time = 0, i = 0, number, lastcp, index;
		f >> count;
		runners = initialize(count);
		while (!f.eof())
		{
			int temp;
				switch (a)
				{
				case 1: f >> number; break;
				case 2: f >> lastcp; break;
				case 3: f >> temp; time += temp * 3600; break;
				case 4: f >> temp; time += temp * 60; break;
				case 5: f >> temp; time += temp;
					index = wasinarray(runners, count, number);
					if (index < 0){
						runners[i].number = number;
						runners[i].lastCheckPoint = lastcp;
						runners[i].startInSeconds = time;
						runners[i].dqf = false;
						i++;
					}
					else{
						runners[index].number = number;
						runners[index].timeInSeconds = time;
						runners[index].dqf = lastcp - 1 != runners[index].lastCheckPoint;
						runners[index].lastCheckPoint = lastcp;
					}
					a = 0, time = 0;
					break;
				}
				a++;
		}
	}
	else cout << "Fajl megnyitasi hiba!";
	return runners;
}

bool timespan(Runner runner, int& hours, int& minutes, int& seconds){
	if (runner.lastCheckPoint != 5) return false;
	else{
		int time = runner.timeInSeconds - runner.startInSeconds;
		hours = time / 3600; time -= hours * 3600;
		minutes = time / 60; time -= minutes * 60;
		seconds= time;
		return true;
	}
}

void print(Runner* runners, int count){
	for (int i = 0; i < count; i++)
	{
		int hours = 0, minutes = 0, seconds = 0;
		if (!runners[i].dqf){
			if (timespan(runners[i], hours, minutes, seconds)) cout << runners[i].number << " " << hours << ":" << minutes << ":" << seconds << endl;
			else cout << runners[i].number << " DNF" << endl;
		}
	}
}

Runner* sort(Runner* runners, int count){
	for (int i = 0; i < count; i++)
	{
		if (runners[i].lastCheckPoint != 5) runners[i].timeInSeconds = 99999999;
	}
	for (int i = count; i > 0; i--)
	{
		for (int j = 0; j < i-1; j++)
		{
			if (runners[j].timeInSeconds - runners[j].startInSeconds > runners[j + 1].timeInSeconds - runners[j + 1].startInSeconds){
				Runner temp = runners[j];
				runners[j] = runners[j + 1];
				runners[j + 1] = temp;
			}
		}
	}
	return runners;
}

void main(){
	int count = 0;
	Runner* runners = readfromfile("idomeres.txt", count);
	runners = sort(runners, count);
	print(runners, count);
	delete[] runners;
}