#ifndef KARAKTER_H
#define KARAKTER_H

#include <string>

using namespace std;

class Karakter
{
public:
	Karakter(string nev, int ero);
	
	string getNev() const;
	int getEro() const;
	void setEro(int e);

	virtual void print() const;

protected:
	string nev;
	int ero;

private:

};



#endif

