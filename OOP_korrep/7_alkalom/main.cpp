﻿/*

Készítsen egy C++ programot, amely egy egyszerűsített HTML dokumentum kezelését valósítja meg objektum-orientált módon.

Alapfeladat:

Kétféle HTML elem kezelését kell megvalósítani egy-egy osztállyal: Text és Tag, mindkettő egy absztrakt TreeNode osztályból öröklődjön. A TreeNode egy toHTML() függvény implementációját követleje meg a leszármazott osztályoktól, úgy, hogy az stringként adja vissza az objektumot leíró HTML kódot.

A Text egyszerű szöveges (string) tartalom tárolására alkalmas, melyet a konstruktorában kötelező megadni. A toHTML() adja vissza a tartalom szövegét formázás nélkül.

A Tag osztály egy általános HTML-taget tudjon kezelni: tárolja a nevet (pl. "img"), az id attribútumot (pl. id="abra") és a tag belsejében lévő csúcsokat (TreeNode-okat).
Ahogy a main()-ből látható, az appendChild(TreeNode*) tagfüggvény egy dinamikusan létrehozott TreeNode címét kapja, és adja hozzá a belső csúcsokhoz. Gondoskodjon a gyermek csúcsok megfelelő felszabadításáról!
A toHTML() függvény formázza meg a taget és adja vissza stringként (a belső csúcsokat is megformázva és összefűzve): <nev id="myid"> childrenHTML </nev>

A HTML dokumentum kezelésére készítsen egy HTML osztályt, ami egy <html><head/><body id="body"></body></html> kezdőstruktúrájú HTML dokumentumot tárol.
A body csúcshoz lehessen gyerek csúcsokat fűzni az addElement(Treenode*) tagfüggvénnyel, és lehessen lekérni Tag-eket az id-jük alapján a getTagById(string id)-vel, ami adjon vissza nullptr-t nem létező id esetén. A rekurzív kereséshez a Tag osztályban hozzon létre egy getById(string id) tagfüggvényt, ami rekurzívan bejárja a gyermek csúcsokat.


Plusz feladatok:

A teljes HTML dokumentumot formázva lehessen kiírni egy std::ostream objektumra (lásd main.cpp). (+1 jegy)

A Tag-nek lehessen tetszőleges számú és nevű argumentumot adni, amik megfelelően legyenek formázva, de a sorrendjük lényegtelen. (+2 jegy)

A HTML::getTagById() dobjon egy HTML::IdNotFound exceptiont, ha nincs ilyen id-jű csúcs a dokumentumban. Készítsen hozzá egy megfelelő try-catch blokkot is a main()-be! (+1 jegy)

Tegye lehetővé, hogy egy Tag objektum gyermek csúcsait az osztályon kívülről is be lehessen járni, anélkül, hogy a kifelé láthatóvá tenné az osztály belső tárolási logikáját. A main()-ben mutassa be a használatát is! (max. +2 jegy megvalósítástól függően)
Pontosítás: a Tag objektumok közvetlen gyerekei legyenek indexelhetőek a [] operátorral

*/

#include <iostream>
#include "html.h"
#include "tag.h"
#include "text.h"
#include <string>
#include <list>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    HTML test;

	test.addElement(new Tag("h1", "title"));
	test.getTagById("title")->appendChild(new Text("Szükséges feltételek OODB vizsgán"));

	test.addElement(new Tag("ul", "requirements"));
	const list<string> requirements({
	  "A kód csak standard C++11 elemeket használjon.",
	  "A kód warning nélkül forduljon le --Wall kapcsoló mellett is.",
	  "A bináris ne szemeteljen a memóriába.",
	  "A bináris semmilyen bemenet esetén nem segfaultolhat el."
		});
	for (const auto& req : requirements)
	{
		Tag* item = new Tag("li");
		item->appendChild(new Text(req));
		test.getTagById("requirements")->appendChild(item);
	}

	test.addElement(new Text("Megj.: A fenti feltételek csak szükségesek, de nem elégségesek a kettes szintjének eléréséhez."));

	//Attribútumok hozzáadása, kiolvasása
	test.getTagById("requirements")->setAttribute("style", "color:red;");

	/*Kiiratos plusz feladathoz*/

	cout << test;
	string filename;

	if (argc == 1) filename = "index.html";
	else filename = argv[1];

	ofstream output(filename);
	if (output.is_open())
	{
		output << test;
		output.close();
	}

	//IdNotFound Exeption tesztelése
	try {
		cout << test.getTagById("ilyennincs")->toHTML();
	}
	catch (HTML::IdNotFound e) {
		cerr << e.message() << endl;
	}
	   
	
	
    return 0;
}
