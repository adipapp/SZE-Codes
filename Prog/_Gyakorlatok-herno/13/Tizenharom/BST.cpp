#include "BST.h"

#include <iostream>

BST* beszur(BST *gyoker, string szo) {
	if (!gyoker) { // ures a fa
		BST *uj = new BST;
		uj->szo = szo;
		uj->bal = uj->jobb = NULL;
		return uj;
	}
	else if (szo < gyoker->szo) { // kisebb az uj szo
		if (gyoker->bal)
			beszur(gyoker->bal, szo);
		else {
			BST *uj = new BST;
			uj->szo = szo;
			uj->bal = uj->jobb = NULL;
			gyoker->bal = uj;
		}
	}
	else if (szo > gyoker->szo) { // nagyobb az uj szo
		if (gyoker->jobb)
			beszur(gyoker->jobb, szo);
		else {
			BST *uj = new BST;
			uj->szo = szo;
			uj->bal = uj->jobb = NULL;
			gyoker->jobb = uj;
		}
	}
	return gyoker;
}

void felszabadit(BST *gyoker) {
	if (!gyoker)
		return;
	//cout << gyoker->szo << " torlese\n";
	felszabadit(gyoker->bal);
	felszabadit(gyoker->jobb);
	delete gyoker;
}

bool keres(BST *gyoker, string szo) {
	if (!gyoker) { // ures a fa
		return false;
	}
	else if (szo < gyoker->szo) { // kisebb a keresett szo
		return keres(gyoker->bal, szo);
	}
	else if (szo > gyoker->szo) { // nagyobb a keresett szo
		return keres(gyoker->jobb, szo);
	}
	else { // megtalaltuk
		return true;
	}
}