#include "File.h"

File::File(string name, string content) : name(name), content(content)
{
}

string File::getName()
{
	return name;
}

string File::getContent()
{
	return content;
}
