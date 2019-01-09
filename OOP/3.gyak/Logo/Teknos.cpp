#define _USE_MATH_DEFINES
#include <math.h>
#include "Teknos.h"

Teknos::Teknos() {
	X = 0;
	Y = 0;
	Alpha = 90;
}

double Teknos::rad(double deg) {
	return 2 * M_PI * (deg / 360);
}

void Teknos::fd(double mennyit) {
	X = X + mennyit * cos(rad(Alpha));
	Y = Y + mennyit * sin(rad(Alpha));
}

void Teknos::convertalpha() {
	if (Alpha >= 360) Alpha = fmod(Alpha, 360);
	else if(Alpha<0) Alpha = 360 - fabs(fmod(Alpha, 360));
}

void Teknos::lt(double mennyit) {
	Alpha += mennyit;
	convertalpha();
}

void Teknos::rt(double mennyit) {
	Alpha -= mennyit;
	convertalpha();
}

const double Teknos::getX() {
	return X;
}

const double Teknos::getY() {
	return Y;
}

const double Teknos::getAlpha() {
	return Alpha;
}