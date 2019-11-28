#ifndef HTML_H
#define HTML_H

#include <string>
#include <iostream>
#include "tag.h"

using namespace std;

class HTML {
private:
	string startHtml;
	string endHtml;
	Tag* body;

public:
	HTML();
	~HTML();
	void addElement(TreeNode* newNode);
	Tag* getTagById(string id);
	friend ostream&  operator<<(ostream& out, HTML& htmldoc);
};

inline ostream&  operator<<(ostream& out, HTML& htmldoc) {
	out << htmldoc.startHtml;
	out << htmldoc.body->toHTML();
	out << htmldoc.endHtml;
	return out;
}

#endif
