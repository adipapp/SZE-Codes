#include "html.h"

using namespace std;

HTML::HTML()
{
	body = new Tag("body", "body");
	kezdoStrukt = "<html><head/>";
	vegStrukt = "</html>";
}

HTML::~HTML()
{
	delete body;
}

void HTML::addElement(TreeNode* elem)
{
	body->appendChild(elem);
}

Tag* HTML::getTagById(string id)
{
	Tag* temp = body->getById(id);
	if(temp!= nullptr) return temp;
	else throw IdNotFound({ id });
}

ostream& operator<<(ostream& out, HTML& html) {
	out << html.getBegin() << endl;
	out << html.getTagById("body")->toHTML() << endl;
	out << html.getEnd() << endl;
	return out;
}