#include "Filesystem.h"

Filesystem::Filesystem()
{
	wd = nullptr;
}

Filesystem::~Filesystem()
{
	for (auto& i : directories) {
		delete i;
	}
	for (auto& i : files) {
		delete i;
	}
	for (auto& i : path) {
		delete i;
	}
}

int Filesystem::mkdir(string dirname)
{
	if (path.empty()) {
		if (dirExists(dirname) != nullptr) return 1;
		directories.push_back(new Directory(dirname));
		return 0;
	}
	else return path.back()->mkdir(dirname);
}

int Filesystem::touchindir(string filename, string content, string dirname)
{
	if (dirname == "/") {
		for (auto& i : files) {
			if (i->getName() == filename) return 1;
		}
		files.push_back(new File(filename, content));
		return 0;
	}
	else {
		for (auto& i : directories) {
			if (i->getName() == dirname) {
				return i->touch(filename, content);
			}
		}
		return 2;
	}
}

string Filesystem::treelist()
{
	int depth = 0;
	string tree = "\n/\n";
	for (auto& i : directories) {
		tree += "\t" + i->getName() + "/\n" + i->ls(depth+1);
	}
	for (auto& i : files) {
		tree += "\t" + i->getName() + "\n";
	}
	return tree;
}

int Filesystem::cd(string dirname)
{
	if (dirname == "/") {
		path.clear();
		return 0;
	}
	if (dirname == ".."&&path.empty()) return 1;
	if (dirname == ".." && !path.empty()) {
		path.pop_back();
		return 0;
	}

	bool relative = dirname[0] != '/';
	list<string> dirs;
	string temp = "";

	for (unsigned int i = relative ? 0 : 1; i < dirname.length(); i++)
	{
		if (dirname[i] == '/') {
			dirs.push_back(temp);
			temp = "";
		}
		else temp += dirname[i];
	}
	if(temp!="") dirs.push_back(temp);

	if (!relative || path.empty()) {
		Directory* tempptr = dirExists(dirs.front());
		if (tempptr != nullptr) path.push_back(tempptr);
		else return 1;
		dirs.pop_front();
	}
	while (dirs.cbegin()!=dirs.cend())
	{
		Directory* tempptr = path.back()->dirExists(dirs.front());
		if (tempptr != nullptr) path.push_back(tempptr);
		else return 1;
		dirs.pop_front();
	}

	return 0;
}

string Filesystem::pwd()
{
	string actpath = "\nadampapp@zeus:";
	actpath += path.empty() ? "/" : "";
	for (auto& i : path) {
		actpath += "/" + i->getName();
	}
	return actpath + "# ";
}

Directory * Filesystem::dirExists(string dirname)
{
	for (auto& i : directories) {
		if (i->getName() == dirname) return i;
	}
	return nullptr;
}
