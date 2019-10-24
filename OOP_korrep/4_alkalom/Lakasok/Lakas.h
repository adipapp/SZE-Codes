#ifndef LAKAS_H
#define LAKAS_H

#include <string>

using namespace std;

class Lakas
{
public:
	Lakas(string cim, int nm);
	virtual ~Lakas();
	int vetelar();
	void elad(string ujTulaj);
	Lakas(const Lakas& other) = delete;
	static void setArPerNm(int newAr);

private:

protected:
	int nm;
	string cim;
	static int arPerNm;
	string* tulajok;
	int tulajDb;

};



#endif
