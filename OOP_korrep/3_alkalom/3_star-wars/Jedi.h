#ifndef JEDI_H
#define JEDI_H

#include <string>

#include "Karakter.h"

using namespace std;

class Jedi : public Karakter
{
public:
	Jedi(string nev, int ero, bool mesterE);

	bool getMesterE();
	void setMesterE(bool mE);

	virtual void print() const;

protected:


private:
	bool mesterE;
};



#endif
