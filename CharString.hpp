#pragma once
namespace ext
{
	struct charString
	{
		char symbol;
		charString* nextSymbol;
	};

	void append(charString*& str, char symbol);
	void print(charString* str);
	void removeChars(charString* str, int position, int num);
}