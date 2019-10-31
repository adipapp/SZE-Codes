#include "Vector.h"

Vector::Vector()
{
	dintomb = nullptr;
	meret = 0;
}

Vector::~Vector()
{
	delete[] dintomb;
}

int Vector::size()
{
	return meret;
}

void Vector::push(Lakas& l)
{
	Lakas* temp = new Lakas[meret+1];
	for (int i = 0; i < meret; i++) {
		temp[i] = dintomb[i];
	}
	temp[meret] = l;
	delete[] dintomb;
	dintomb = temp;
	meret++;
}

void Vector::pop()
{
	Lakas* temp = new Lakas[meret - 1];
	for (int i = 0; i < meret - 1; i++) {
		temp[i] = dintomb[i];
	}
	delete[] dintomb;
	dintomb = temp;
	meret--;
}

void Vector::clear()
{
	delete[] dintomb;
	dintomb = nullptr;
	meret = 0;
}

Lakas& Vector::operator[](int index)
{
	return dintomb[index];
}