#include "Ez.h"

Ez::Ez(int ePar) : e(new int(ePar))
{
}

Ez::~Ez()
{
	delete e;
}

Ez::Ez(const Ez & other)
{
	e = new int(other.getE());
}

Ez & Ez::operator=(const Ez & other)
{
	e = new int(other.getE());
	return *this;
}

void Ez::setE(int parE)
{
	*e = parE;
}

int Ez::getE() const
{
	return *e;
}