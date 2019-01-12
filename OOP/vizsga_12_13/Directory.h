#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "File.h"
#include <string>
#include <list>

using namespace std;

class Directory
{
public:
	Directory(string dirname);
	~Directory();
	int touch(string filename, string content = "");
	string ls();
	int mkdir(string dirname);
	string getName();
	Directory* dirExists(string dirname);

private:
	string name;
	list<File*> files;
	list<Directory*> directories;
	
};

#endif // !DIRECTORY_H
