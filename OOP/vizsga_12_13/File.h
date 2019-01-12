#ifndef FILE_H
#define FILE_H

#include <string>

using namespace std;

class File
{
public:
	File(string filename, string text="");
	
	string getName();
	string getContent();

private:
	string name;
	string content;
};

#endif // !FILE_H

