#ifndef TREENODE_H
#define TREENODE_H

#include <string>

using namespace std;

class TreeNode
{
public:
	virtual ~TreeNode(){}
	virtual string toHTML() = 0;
};

#endif