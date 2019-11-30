#include "charString.hpp"
#include <iostream>

namespace ext
{
	void append(charString*& str, char symbol)
	{
		charString* ptr = new charString{ symbol };

		if (str == nullptr)
		{
			str = ptr;
			return;
		}

		charString* temp = str;

		while (temp->nextSymbol != nullptr)
		{
			temp = temp->nextSymbol;
		}
		temp->nextSymbol = ptr;
	}

	void print(charString* str)
	{
		while (str != nullptr)
		{
			std::cout << str->symbol;
			str = str->nextSymbol;
		}
	}

	void removeChars(charString* str, int position, int num)
	{
		int count = 1;
		while (count != position - 1)
		{
			str = str->nextSymbol;
			++count;
		}
	
		for (int i = 0; i < num; ++i)
		{
			delete[] str;
			charString* temp = str->nextSymbol;
			temp = str->nextSymbol;

		}
	}
}