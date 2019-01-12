#ifndef TAG_H
#define TAG_H

#include "treenode.h"
#include <list>
#include <map>

using namespace std;

class Tag : public TreeNode
{
public:
	Tag(string tagTipus, string azonsito = "");
	virtual ~Tag();
	void appendChild(TreeNode* newNode);
	virtual string toHTML();
	Tag* getById(string idToSeek);
	void setAttribute(string attrName, string attrValue);
	string getAttribute(string attrName);

private:
	string tagName;
	string id;
	list<TreeNode*> nodes;
	map<string, string> attributes;
};

#endif