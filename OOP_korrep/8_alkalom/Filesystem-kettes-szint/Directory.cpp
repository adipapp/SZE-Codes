#include "Directory.h"

Directory::Directory(string name) : name(name)
{
}

Directory::~Directory()
{
	for (auto i : files)
	{
		delete i;
	}
}

string Directory::getName()
{
	return name;
}

int Directory::touch(string FileName, string content)
{
	if (containsFile(FileName)) return 1;
	files.push_back(new File(FileName, content));
	return 0;
}

string Directory::ls()
{
	string s = "";
	for (auto i : files) {
		s += "\t" + i->getName() + "\n";
	}
	return s;
}

bool Directory::containsFile(string fileName)
{
	for (auto i : files)
	{
		if (i->getName() == fileName) return true;
	}
	return false;
}
