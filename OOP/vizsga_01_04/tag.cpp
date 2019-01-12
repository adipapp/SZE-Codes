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
	string formatted = "<" + tagName;
	for (auto i : attributes) {
		formatted += " " + i.first + "=\"" + i.second + "\" ";
	}
	if (id != "") formatted += " id=" + id + ">" + "\n";
	else formatted += ">\n";
	
	for (auto& i : nodes) {
		formatted += i->toHTML() + "\n";
	}
	formatted += "</" + tagName + ">" + "\n";
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

void Tag::setAttribute(string attrName, string attrValue)
{
	attributes[attrName] = attrValue;
}

string Tag::getAttribute(string attrName)
{
	return attributes[attrName];
}
