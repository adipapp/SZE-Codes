#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Leaf
{
	string word;
	int count;
	bool tukorszo;
	Leaf* left;
	Leaf* right;
};

bool simmetricword(string word){
	for (int i = 0, j = word.length()-1; i < j; i++, j--)
	{
		if (word[i] != word[j]) return false;
	}
	return true;
}

Leaf* insert(Leaf* root, string word){
	if (root == NULL){
		root = new Leaf;
		root->word = word;
		root->tukorszo = simmetricword(word);
		root->count = 1;
		root->left = root->right = NULL;
	}
	else if (word < root->word){
		root->left = insert(root->left, word);
	}
	else if (word>root->word){
		root->right = insert(root->right, word);
	}
	else{
		root->count++;
	}
	return root;
}

void writeoutinorder(Leaf* root){
	if (root != NULL){
		writeoutinorder(root->left);
		cout << root->word;
		if (root->tukorszo) cout << "*";
		if (root->count>1) cout << " - " << root->count;
		cout << endl;
		writeoutinorder(root->right);
	}
}

void cutoffbinarytree(Leaf* root){
	if (root != NULL){
		cutoffbinarytree(root->left);
		cutoffbinarytree(root->right);
		delete root;
	}
}

void writeoutinorder2(Leaf* root, ofstream& f){
	if (root != NULL){
		writeoutinorder2(root->left, f);
		f << root->word;
		if (root->tukorszo) f << "*";
		if (root->count>1) f << " - " << root->count;
		f << endl;
		writeoutinorder2(root->right, f);
	}
}

bool writeoutfile(Leaf* root, char* filename){
	ofstream f(filename);
	if (f.is_open()){
		writeoutinorder2(root, f);
		f.close();
		return true;
	}
	else{
		cout << "Kimeneti fajl megnyitasi hiba!" << endl;
		f.close();
		return false;
	}
}

string trim(string word){
	string trimmed = "";
	for (int i = 0; i < word.length(); i++)
	{
		if (isalpha(word[i])) trimmed += word[i];
	}
	return trimmed;
}

void main(int argc, char* argv[]){
	Leaf* root = NULL;
	cout << "Adjon meg szavakat, ENTERrel(soremeles) elvalasztva!\n Csak betukaraktereket hasznaljon es soronkent 1 szot irjon!" << 
		"\n '-'(kotojel karakter idezojelek nelkul) bevitele eseten a bekeres veget er." << endl;
	bool end = false;
	while (!end)
	{
		string temp, temp2;
		cin >> temp;
		temp2 = trim(temp);
		if (temp != "-") root = insert(root, temp2);
		else end = true;
	}
	cout << "A megadott szavak abc rendben: (* jeloli a tukorszavakat)" << endl;
	writeoutinorder(root);

	if (argc == 2 && writeoutfile(root, argv[1])) cout << "Sikeresen kiirva fajlba az eredmeny." << endl;

	cutoffbinarytree(root);
}