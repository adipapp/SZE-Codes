#include "Filesystem.h"

Filesystem::~Filesystem()
{
	for (auto i : files)
	{
		delete i;
	}
	for (auto i : dirs)
	{
		delete i;
	}
}

int Filesystem::mkdir(string dirName)
{
	if (containsDir(dirName)) return 1;
	dirs.push_back(new Directory(dirName));
	return 0;
}

int Filesystem::touchindir(string fileName, string content, string dirName)
{
	if (dirName == "") {
		if (containsFile(fileName)) return 1;
		files.push_back(new File(fileName, content));
		return 0;
	}
	else {
		Directory* d = containsDir(dirName);
		if (d != nullptr) {
			return d->touch(fileName, content);
		}
		return 2;
	}
	return 0;
}

string Filesystem::treelist()
{
	string s = "";
	for (auto i : dirs) {
		s += i->getName() + "/\n";
		s += i->ls();
	}
	for (auto i : files) {
		s += i->getName() +"\n";
	}
	return s;
}

bool Filesystem::containsFile(string fileName)
{
	for (auto i : files)
	{
		if (i->getName() == fileName) return true;
	}
	return false;
}

Directory* Filesystem::containsDir(string dirName)
{
	for (auto i : dirs)
	{
		if (i->getName() == dirName) return i;
	}
	return nullptr;
}
