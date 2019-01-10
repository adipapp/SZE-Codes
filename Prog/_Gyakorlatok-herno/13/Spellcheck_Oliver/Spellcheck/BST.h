#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

struct BST {
	string szo;
	BST *bal;
	BST *jobb;
};

BST* beszur(BST *gyoker, string szo);

void felszabadit(BST *gyoker);

bool keres(BST *gyoker, string szo);

BST* maxElem(BST *gyoker);

BST* torol(BST *gyoker, string szo);

#endif