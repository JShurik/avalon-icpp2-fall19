#include <iostream>
#include "CharArray.hpp"

using namespace ext;

int main()
{
	setlocale(LC_ALL, "rus");
	CharArray str = new char[6]{ "Hello" };
	CharArray str2 = new char[7]{ " World" };

	char result = chracterAt(str, 1);
	char result2 = chracterAt(str, 3);

	concatenate(str, str2);
}