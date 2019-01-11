#include "tag.h"

using namespace std;

Tag::Tag(string tagTipus, string azonsito)
{
	tagName = tagTipus;
	id = azonsito;
}

Tag::~Tag()
{
	for (auto& i : nodes) {
		delete i;
	}
}

void Tag::appendChild(TreeNode* newNode)
{
	nodes.push_back(newNode);
}

string Tag::toHTML()
{
	string formatted = "<" + tagName + " id=" + id + ">";
	for (auto& i : nodes) {
		formatted += i->toHTML();
	}
	formatted += "</" + tagName + ">";
	return formatted;
}

Tag* Tag::getById(string idToSeek)
{
	if (idToSeek == id) return this;
	for (auto& i : nodes) {
		Tag* temp = dynamic_cast<Tag*>(i);
		if (temp != nullptr) {
			temp = temp->getById(idToSeek);
			if(temp != nullptr) return temp;
		}
	}
	return nullptr;
}
