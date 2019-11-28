#ifndef TAG_H
#define TAG_H

#include <string>
#include <vector>
#include "treenode.h"

using namespace std;

class Tag : public TreeNode {
private:
	string tagname;
	string id;
	vector<TreeNode*> content;

public:
	void appendChild(TreeNode*);
	Tag(string tagname, string id="");
	~Tag();
	virtual string toHTML();
	Tag* getById(string id);
};

#endif
