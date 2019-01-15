/*
Futball menedzser program
K�sz�tsen C++ oszt�lyokat focicsapatok �s focist�k adatainak t�rol�s�ra, az al�bbi specifik�ci�k alapj�n!


Legal�bb 2-es �rdemjegy�rt:
***
K�sz�tsen egy Jatekos oszt�lyt j�t�kosok adatainak t�rol�s�ra: n�v, sz�let�si �v.
Az adatokat ne lehessen az oszt�lyon k�v�lr�l m�dos�tani, csak getter f�ggv�nyekkel lek�rdezni.

K�sz�tsen egy Csapat oszt�lyt is. Minden csapatnak van neve (std::string), tov�bb� STL vektorban t�rolja, hogy a csapatban mely
j�t�kosok j�tszanak (std::vector<Jatekos*>). (seg�ts�g: https://en.cppreference.com/w/cpp/container/vector))
Ezeket az adattagokat k�v�lr�l szint�n nem lehet m�dos�tani, csak a nevet lek�rdezni.
A Csapat oszt�lyhoz az al�bbi met�dusokat k�sz�tse el:
- K�sz�tsen egy jatekosok() met�dust, amely console-ra kilist�zza a csapat j�t�kosait (fejl�cben a csapat nev�t, minden j�t�kos nev�t egy �j sorban).
A kilist�z�st v�gz� for-ciklusban haszn�ljon a vector t�pusnak megfelel� iteratort (seg�ts�g: p�lda itt tal�lhat� http://www.cplusplus.com/reference/vector/vector/begin/ )
- K�sz�tsen egy leigazol(Jatekos*) met�dust, amely lehet�v� teszi, hogy adott j�t�kos az adott csapathoz szerz�dj�n.
Egy j�t�kos egyszerre csak egy csapathoz szerz�dhet, ez�rt a Jatekos oszt�ly hivatkoz�st kell, hogy tartalmazzon arra a Csapat objektumra is,
amely csapatban a j�t�kos j�tszik (egy priv�t Csapat* pointerrel �s a megfelel� getter f�ggv�nnyel eg�sz�tse ki a Csapat oszt�lyt!).
Mindig a legfrissebb igazol�s sz�m�t, az aktu�lis Csapat* fel�l�rja a kor�bbit!
- K�sz�tsen egy elad() met�dust is. Erre akkor lesz sz�ks�g, amikor egy j�t�kos m�r j�tszik egy X csapatban, �s egy m�sik Y
csapathoz igazol. Ekkor az Y csapat leigazol() met�dusa megh�vja az X csapat elad() met�dus�t, hogy az adott j�t�kos az X csapat nyilv�ntart�s�b�l t�rl�sre
ker�lj�n. Megjegyz�s: Mivel elad() met�dust csak a leigazol() met�dus h�vja meg, amely szint�n a Csapat oszt�ly scope-j�ban van, ez�rt az elad() met�dust
�ll�tsa priv�tra!
Az elad() met�dus implement�l�sa sor�n hasz�lja az std::vector oszt�ly erase() met�dus�t a sz�ks�ges hivatkoz�sok t�rl�s�re
(seg�ts�g: https://en.cppreference.com/w/cpp/container/vector/erase). Vigy�zat: ha for ciklus k�zep�n t�rl�nk, a tov�bbi iter�torok invalid�l�sra ker�lnek,
ez�rt t�rl�s ut�n break utas�t�st kell h�vni!
�sszefoglal�an a leigazol() fv az al�bbi m�veleteket hajtja v�gre:
... a j�t�kos kor�bbi csapat�ra - ha van ilyen - megh�vja az elad() met�dust
... setterrel bejegyzi mag�t a j�t�koson, mint a j�t�kos �j csapat�t
�sszefoglal�an az elad() met�dus az std::vector oszt�ly erase() met�dusa seg�ts�g�vel t�rli a j�t�kost �s az �ltala szerzett g�lok sz�m�t a csapat nyilv�ntart�s�b�l
***

Jobb jegy�rt:
- A Jatekos objektum tartalmazzon egy PlayerStats objektumra val� hivatkoz�st is, amelyben benne van, mi a j�t�kos csapata �s h�ny g�lt l�tt a csapatban a j�t�kos.
Ha a j�t�kosnak m�g nincs csapata, legyen PlayerStats objektumra val� mutat� nullptr.
- PlayerStats objektum tartalmazzon opcion�lis hivatkoz�st az eggyel kor�bbi PlayerStats objektumra is, amennyiben a j�t�kos �tigazolt.
Ilyen m�don egy l�ncolt list�t hozhatunk l�tre minden j�t�koshoz, �s a teljes t�rt�net�ket nyomon k�vethetj�k.
- Jatekos osztalyban Csapat*-t t�r�lj�k (hiszen most m�r van PlayerStats*), �s ennek megfelel�en dolgozzuk �t a Csapat oszt�ly leigazol() met�dus�t is.
- A Jatekos oszt�ly r�szek�nt implement�ljunk egy gol() met�dust, amely 1-el n�veli az adott j�t�kos csapat�ban szerzett g�ljainak sz�m�t
- K�sz�tsen a Jatekos osztaly reszekent egy statisztika() metodust, amely kiirja, hogy melyik csapatban hany golt szerzett a jatekos.
- K�sz�tsen destruktort a Jatekos oszt�lyhoz, amivel t�r�lni lehet a j�t�kos statisztik�j�t (a l�ncolt list�t).
*/

//#include "stdafx.h"
#include "Jatekos.h"
#include "Csapat.h"
#include <iostream>

int main() {
	// Kettes szint tesztelese... Kettes szint ut�n kikommentelni!
	Jatekos cr = Jatekos("C. Ronaldo", 1985);
	Jatekos lm = Jatekos("L. Messi", 1987);
	Jatekos sr = Jatekos("S. Ramos", 1986);
	Jatekos km = Jatekos("K. Mbappe", 1998);
	Jatekos kb = Jatekos("K. Benzema", 1987);
	
	Csapat rma = Csapat("Real Madrid");
	Csapat psg = Csapat("Paris Saint Germain");
	Csapat juv = Csapat("Juventus");
	Csapat bar = Csapat("Barcelona");
	
	juv.leigazol(&cr);
	juv.leigazol(&kb);
	
	rma.leigazol(&lm);
	bar.leigazol(&lm); // megsem Real Madridban jatszik Lionel Messi
	rma.leigazol(&km);
	psg.leigazol(&km); // megsem Real Madridban jatszik Kylian Mbappe
	rma.leigazol(&kb); // megis Real Madridban jatszik Karim Benzema
	rma.leigazol(&sr); // Sergio Ramos is madridos...
	
	rma.jatekosok();
	//Kiirja, hogy:
	//***
	//Real Madrid csapat jatekosai:
	//K. Benzema
	//S. Ramos
	//***

	juv.jatekosok();
	// Csak C. Ronaldo
	
	return 0;
}