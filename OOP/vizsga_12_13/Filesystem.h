#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "File.h"
#include "Directory.h"
#include <string>
#include <list>

using namespace std;

class Filesystem
{
public:
	Filesystem();
	~Filesystem();
	int mkdir(string dirname);
	int touchindir(string filename, string content = "", string dirname = "/");
	string treelist();
	int cd(string dirname);
	string pwd();
	Directory* dirExists(string dirname);

private:
	list<File*> files;
	list<Directory*> directories;
	Directory* wd;
	list<Directory*> path;
};

#endif // !FILESYSTEM_H
