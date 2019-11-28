#include "html.h"

HTML::HTML() : startHtml("<html><head/>"), endHtml("</html>"), body(new Tag("body")) {}

HTML::~HTML()
{
	delete body;
}

void HTML::addElement(TreeNode* newNode)
{
	body->appendChild(newNode);
}

Tag* HTML::getTagById(string id)
{
	return body->getById(id);
}
