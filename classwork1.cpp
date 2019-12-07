#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Triangle
{
	string color;
	int a;
	int b;
	int c;
	double thikness;
};

int main()
{
	ofstream fout("out.bin", istream::out | istream::binary);

	int a = 5;
	fout.write(reinterpret_cast<char*>(&a), sizeof(int));

	fout.close();

	istream fin("out.bin", ifstream::in | ifstream::binary);
	int b;
	fin.read(reinterpret_cast<char*>(&b), sizeof(int));
}