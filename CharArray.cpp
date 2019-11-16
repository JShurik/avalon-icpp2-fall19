#include "CharArray.hpp"

namespace ext
{
	int length(CharArray first)
	{
		int length = 0;
		while (first[length] != '\0') ++length;
		return length;
	}

	char chracterAt(CharArray str, int number)
	{
		return str[number - 1];
	}

	void concatenate(CharArray & first, CharArray second)
	{
		int length1 = length(first);
		int length2 = length(second);  

		CharArray result = new char[length1 + length2 + 1];

		for (int i = 0; i < length1; ++i)
		{
			result[i] = first[i];
		}

		for (int i = 0; i < length2; ++i)
		{
			result[length1 + i] = second[i];
		}
		result[length1 + length2 + 1] = '\0';

		delete[] first;

		first = result;
	}


}