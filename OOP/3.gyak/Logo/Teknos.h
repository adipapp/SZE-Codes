#ifndef TEKNOS_H
#define TEKNOS_H


class Teknos {
public:
	Teknos();

	void fd(double mennyit);
	void lt(double mennyit);
	void rt(double mennyit);

	const double getX();
	const double getY();
	const double getAlpha();

private:
	double X;
	double Y;
	double Alpha;
	double rad(double deg);
	void convertalpha();
};

#endif