#ifndef FILE_H
#define FILE_H

#include <string>

using namespace std;

class File
{
public:
	File(string name, string content = "");
	string getName();
	string getContent();

private:
	string name;
	string content;
};

#endif



