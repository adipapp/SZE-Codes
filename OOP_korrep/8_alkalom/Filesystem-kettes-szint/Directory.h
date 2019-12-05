#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include "File.h"

using namespace std;

class Directory
{
public:
	Directory(string name);
	~Directory();
	string getName();
	int touch(string FileName, string content = "");
	string ls();

private:
	string name;
	vector<File*> files;
	bool containsFile(string fileName);
};



#endif
