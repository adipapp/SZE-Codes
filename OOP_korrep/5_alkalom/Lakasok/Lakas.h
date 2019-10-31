#ifndef LAKAS_H
#define LAKAS_H

#include <string>

using namespace std;

class Lakas
{
public:
	Lakas(string cim, int nm);
	Lakas(){}
	virtual ~Lakas();
	int vetelar();
	void elad(string ujTulaj);
	Lakas(const Lakas& other) = delete;
	static void setArPerNm(int newAr);

	friend ostream& operator<<(ostream& out, Lakas& l);
	friend ostream& operator<<(ostream& out, Lakas* l);

private:

protected:
	int nm;
	string cim;
	static int arPerNm;
	string* tulajok;
	int tulajDb;

};

inline ostream& operator<<(ostream& out, Lakas& l) {
	out << l.cim << "\t" << l.nm << endl;
	return out;
}

ostream& operator<<(ostream& out, Lakas* l);

#endif
