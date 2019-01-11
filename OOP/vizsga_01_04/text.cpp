#include "text.h"

using namespace std;

Text::Text(string szoveg)
{
	text = szoveg;
}

Text::~Text()
{
}

string Text::toHTML()
{
	return text;
}
