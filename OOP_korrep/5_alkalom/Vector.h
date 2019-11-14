#ifndef VECTOR_H
#define VECTOR_H

#include "Lakas.h"

template <class T>
class Vector
{
public:
	Vector() {
		dintomb = nullptr;
		meret = 0;
	}
	~Vector() {
		delete[] dintomb;
	}
	int size() {
		return meret;
	}
	void push(const T& l) {
		T* temp = new T[meret + 1];
		for (int i = 0; i < meret; i++) {
			temp[i] = dintomb[i];
		}
		temp[meret] = l;
		delete[] dintomb;
		dintomb = temp;
		meret++;
	}
	void pop() {
		T* temp = new T[meret - 1];
		for (int i = 0; i < meret - 1; i++) {
			temp[i] = dintomb[i];
		}
		delete[] dintomb;
		dintomb = temp;
		meret--;
	}
	void clear() {
		delete[] dintomb;
		dintomb = nullptr;
		meret = 0;
	}
	T& operator[](int index) {
		return dintomb[index];
	}

private:
	int meret;
	T* dintomb;
};


#endif // !VECTOR_H

