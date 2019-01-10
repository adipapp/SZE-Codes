#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	string tel;
	string cim;
	Node* kov;
};

Node* beszur(Node* elso, string tel, string cim){
	Node* uj = new Node;
	uj->tel = tel;
	uj->cim = cim;
	uj->kov = NULL;
	if (elso == NULL) return uj;
	else{
		Node* akt = elso;
		while (akt->kov!=NULL) akt = akt->kov;
		akt->kov = uj;
		return elso;
	}
}

string joszam(string s){
	string szam = "";
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i])) szam += s[i];
	}
	if (szam.length() == 8 || szam.length() == 9) return szam;
	else return "";
}

Node* keres(Node* elso, string tel){
	Node* akt = elso;
	while (akt!=NULL)
	{
		if (akt->tel == tel) return akt;
		akt = akt->kov;
	}
	return NULL;
}

Node* beolvas(char* fajlnev, Node* elso){
	ifstream f(fajlnev);
	while (!f.eof())
	{
		string s;
		getline(f, s);
		elso = beszur(elso, s.substr(0, s.find(" ")), s.substr(s.find(" ") + 1));
	}
	f.close();
	return elso;
}

void fajlbakiir(char* fajlnev, Node* elso){
	ofstream f(fajlnev);
	Node* akt = elso;
	while (akt!=NULL)
	{
		f << akt->tel << " " << akt->cim << endl;
		akt = akt->kov;
	}
	f.close();
}

void felszabadit(Node* elso){
	Node* akt = elso;
	while (elso!=NULL)
	{
		elso = akt->kov;
		delete akt;
		akt = elso;
	}
}

void main(int argc, char* argv[]){
	Node* lista = NULL;
	if (argc == 2) lista = beolvas(argv[1], lista);
	else lista = beolvas("telefoncimtar.txt", lista);
	cout << "Pizzeria telefonszam-cim nyilvantartas\n---------------------------" << endl;
	bool vege = false;
	bool sokadikinput = false;
	do
	{
		cout << "Adjon meg egy telefonszamot:" << endl;
		string tel;
		cin >> tel;
		if (tel != "vege"){
			tel = joszam(tel);
			if (tel != ""){
				Node* talalt = keres(lista, tel);
				if (talalt != NULL) cout << "A szamhoz tartozo cim: " << talalt->cim << endl;
				else{
					cout << "Ismeretlen szam, adja meg a cimet:" << endl;
					string cim;
					cin.ignore(1);
					getline(cin, cim);
					lista = beszur(lista, tel, cim);
				}
			}
			else cout << "Tul keves vagy tul sok szamjegy, probalja ujra!" << endl;
		}
		else vege = true;
	} while (!vege);
	if (argc == 2) fajlbakiir(argv[1], lista);
	else fajlbakiir("telefoncimtar.txt", lista);
	felszabadit(lista);
}