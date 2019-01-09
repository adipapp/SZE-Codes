#ifndef GAME2048_HPP
#define GAME2048_HPP

class Game2048 {
	int table[4][4];

	void insertnewrandom(int number = 2);
	void merge(int i, int j, int ii, int jj);
	void moveleft();
	void moveright();
	void movedown();
	void moveup();
	bool full();

public:
	Game2048();
	bool gameover() const;
	void print() const;
	void up();
	void down();
	void left();
	void right();
	bool win() const;
};

#endif