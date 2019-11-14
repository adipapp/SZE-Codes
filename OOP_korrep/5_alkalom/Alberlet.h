#ifndef ALBERLET_H
#define ALBERLET_H

#include "Lakas.h"

#include <string>

using namespace std;

class Alberlet : public Lakas
{
public:
	Alberlet(string cim, int nm);
	virtual ~Alberlet();
	void szerzodik(string ujBerlo);
	Alberlet(const Alberlet& other) = delete;

private:

protected:
	string* alberlok;
	int alberlokDb;
};



#endif

