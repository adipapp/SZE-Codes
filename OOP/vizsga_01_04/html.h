#ifndef HTML_H
#define HTML_H

#include "treenode.h"
#include "tag.h"
#include <string>
#include <iostream>

using namespace std;

class HTML
{
public:
	HTML();
	~HTML();
	void addElement(TreeNode* elem);
	Tag* getTagById(string id);
	string getBegin() { return kezdoStrukt; }
	string getEnd() { return vegStrukt; }
	struct IdNotFound
	{
		string id;
		string message() {
			return "Nem talalhato " + id + " id-val elem a dokumentumban!";
		}
	};

private:
	string kezdoStrukt;
	string vegStrukt;
	Tag* body;
};

ostream& operator<<(ostream& out, HTML& html);

#endif