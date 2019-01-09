#include "Game2048.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

Game2048::Game2048() {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) table[i][j] = 0;
	for (int i = 0; i < 3; i++) insertnewrandom();
}

bool Game2048::gameover() const {
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			if (table[i][j] == table[i-1][j] || table[i][j] == table[i + 1][j] ||
				table[i][j] == table[i][j - 1] || table[i][j] == table[i][j + 1]) return false;
		}
	}
	return true;
}

void Game2048::print() const {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (table[i][j] == 0) cout << "\t" << "*";
			else cout <<"\t"<< table[i][j];
		}
		cout << endl;
	}
}

bool Game2048::win() const {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if (table[i][j] == 2048) return true;
	return false;
}

void Game2048::merge(int i, int j, int ii, int jj) {
	table[ii][jj] = table[i][j] * 2;
	table[i][j] = 0;
}

void Game2048::moveleft() {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (table[i][j] != 0) {
				for (int k = 0; k < j; k++)
				{
					if (table[i][k] == 0) {
						table[i][k] = table[i][j];
						table[i][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void Game2048::moveright() {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (table[i][j] != 0) {
				for (int k = 3; k > j; k--)
				{
					if (table[i][k] == 0) {
						table[i][k] = table[i][j];
						table[i][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void Game2048::moveup() {
	for (int j = 0; j < 4; j++)
	{
		for (int i = 1; i < 4; i++)
		{
			if (table[i][j] != 0) {
				for (int k = 0; k < i; k++)
				{
					if (table[k][j] == 0) {
						table[k][j] = table[i][j];
						table[i][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void Game2048::movedown() {
	for (int j = 0; j < 4; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (table[i][j] != 0) {
				for (int k = 3; k > i; k--)
				{
					if (table[k][j] == 0) {
						table[k][j] = table[i][j];
						table[i][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void Game2048::insertnewrandom(int num) {
	srand((unsigned)time(NULL));
	int ri, rj;
	do
	{
		ri = rand() % 4;
		rj = rand() % 4;
	} while (table[ri][rj]!=0);
	table[ri][rj] = num;
}

bool Game2048::full() {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if (table[i][j] == 0) return false;
	return true;
}

void Game2048::up() {
	moveup();
	for (int j = 0; j < 4; j++)
	{
		for (int i = 1; i < 4; i++)
		{
			if (table[i][j] == table[i - 1][j]) merge(i, j, i - 1, j);
		}
	}
	moveup();
	if (!gameover()) insertnewrandom();
}

void Game2048::down() {
	movedown();
	for (int j = 0; j < 4; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (table[i][j] == table[i + 1][j]) merge(i, j, i + 1, j);
		}
	}
	movedown();
	if (!full()) insertnewrandom();
}

void Game2048::left() {
	moveleft();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (table[i][j] == table[i][j - 1]) merge(i, j, i, j - 1);
		}
	}
	moveleft();
	if(!full()) insertnewrandom();
}

void Game2048::right() {
	moveright();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (table[i][j] == table[i][j + 1]) merge(i, j, i, j + 1);
		}
	}
	moveright();
	if (!full()) insertnewrandom();
}