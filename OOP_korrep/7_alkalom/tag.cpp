#include "tag.h"

void Tag::appendChild(TreeNode* newNode)
{
	content.push_back(newNode);
}

Tag::Tag(string tagname, string id) : tagname(tagname), id(id) {}

Tag::~Tag()
{
	for (auto i : content) {
		delete i;
	}
}

string Tag::toHTML()
{
	string startTag = "<" + tagname + " id=\"" + id + "\">";
	string endTag = "</" + tagname + ">";
	string childrenTag = "";
	for (auto i : content) {
		childrenTag += i->toHTML();
	}
	return startTag + childrenTag + endTag;
}

Tag* Tag::getById(string id)
{
	if (this->id == id) return this;
	for (auto i : content) {
		Tag* temp = dynamic_cast<Tag*>(i);
		if (temp != nullptr) {
			Tag* toReturn = temp->getById(id);
			if (toReturn != nullptr) return toReturn;
		}
	}
	return nullptr;
}
