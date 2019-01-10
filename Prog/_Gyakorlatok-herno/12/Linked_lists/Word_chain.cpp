#include <iostream>
#include <string>

using namespace std;

struct Node{
	string word;
	Node* next;
	Node* prev;
};

Node* Search(Node* from, string target, bool elore){
	Node* actnode = from;
	if (elore){
		while (from->next != NULL) actnode = actnode->next;
	}
	else{
		while (from->prev != NULL) actnode = actnode->prev;
	}
	return actnode;
}

void WriteOut(Node* first){
	Node* actpointer = first;
	while (actpointer->word != "exit")
	{
		cout << actpointer->word << "\n";
		actpointer = actpointer->next;
	}
}

void WriteOutReverse(Node* last){
	Node* actpointer = last;
	while (actpointer->word != "exit")
	{
		cout << actpointer->word << "\n";
		actpointer = actpointer->prev;
	}
}

void LinkNext(Node* first, string next){
	Node* actpointer = first;
	while (actpointer->next != NULL) actpointer = actpointer->next;
	Node* last = new Node;
	last->word = next;
	last->next = NULL;
	last->prev = actpointer;
	actpointer->next = last;
}

void LinkEnd(Node* last, string next){
	Node* act = new Node;
	act->word = next;
	act->next = NULL;
	act->prev = last;
	last->next = act;
}

void Felszabadit(Node* first){
	Node* actpointer = first;
	while (actpointer->next != NULL)
	{
		Node* temp = actpointer;
		actpointer = actpointer->next;
		delete(temp);
	}
}

void main(){
	cout << "Kerem adjon meg egy szot, mindaddig amig az nem \"exit\"\n";
	string actword;

	Node* first = new Node;
	cin >> first->word;
	first->next = NULL;
	
	Node* last = first;
	
	do
	{
		cin >> actword;
		LinkNext(last, actword);
	} while (actword != "exit");
	WriteOut(first);
	cout << "Adja meg a keresett szot!\n";
	string target;
	cin >> target;
	
	//Keresés meghívása
	Felszabadit(first);
}