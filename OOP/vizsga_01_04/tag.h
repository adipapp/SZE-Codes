#ifndef TAG_H
#define TAG_H

#include "treenode.h"
#include <list>

using namespace std;

class Tag : public TreeNode
{
public:
	Tag(string tagTipus, string azonsito = "");
	virtual ~Tag();
	void appendChild(TreeNode* newNode);
	virtual string toHTML();
	Tag* getById(string idToSeek);

private:
	string tagName;
	string id;
	list<TreeNode*> nodes;
};

#endif