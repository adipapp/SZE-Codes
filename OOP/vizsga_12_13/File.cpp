#include "File.h"

File::File(string filename, string text)
{
	name = filename;
}

string File::getName()
{
	return name;
}

string File::getContent()
{
	return content;
}
