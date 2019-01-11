#ifndef TEXT_H
#define TEXT_H

#include "treenode.h"

using namespace std;

class Text : public TreeNode
{
public:
	Text(string szoveg);
	virtual ~Text();
	virtual string toHTML();

private:
	string text;
};

#endif