#ifndef EZ_H
#define EZ_H

class Ez
{
public:
	Ez(int ePar);
	~Ez();

	Ez(const Ez& other);
	Ez& operator=(const Ez& other);

	int getE() const;
	void setE(int parE);

private:
	int* e;
};

#endif





