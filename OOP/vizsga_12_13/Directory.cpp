#include "Directory.h"

Directory::Directory(string dirname)
{
	name = dirname;
}

Directory::~Directory()
{
	for (auto& i : directories) {
		delete i;
	}
	for (auto& i : files) {
		delete i;
	}
}

int Directory::touch(string filename, string content)
{
	for (auto& i : files) {
		if (i->getName() == filename) return 1;
	}
	files.push_back(new File(filename, content));
	return 0;
}

string Directory::ls(int depth)
{
	string dircontent = "";
	for (auto& i : directories) {
		for (int j = 0; j <= depth; j++) dircontent += "\t";
		dircontent += i->getName() + "/\n" + i->ls(depth+1);
	}
	for (auto& i : files) {
		for (int j = 0; j <= depth; j++) dircontent += "\t";
		dircontent += i->getName() + "\n";
	}
	return dircontent;
}


string Directory::getName()
{
	return name;
}

int Directory::mkdir(string dirname)
{
	for (auto& i : directories) {
		if (i->getName() == dirname) return 1;
	}
	directories.push_back(new Directory(dirname));
	return 0;
}

Directory* Directory::dirExists(string dirname) {
	for (auto& i : directories) {
		if (i->getName() == dirname) return i;
	}
	return nullptr;
}