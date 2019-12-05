#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <vector>
#include "Directory.h"
#include "File.h"

using namespace std;

class Filesystem {
public:
	~Filesystem();
	int mkdir(string dirName);
	int touchindir(string fileName, string content = "", string dirName = "");
	string treelist();

private:
	vector<File*> files;
	vector<Directory*> dirs;
	bool containsFile(string fileName);
	Directory* containsDir(string dirName);
};

#endif
