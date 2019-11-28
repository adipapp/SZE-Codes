#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "treenode.h"

using namespace std;

class Text : public TreeNode {
private:
	string content;

public:
	Text(string content) : content (content) {}
	virtual string toHTML() {
		return content;
	}
};

#endif
