#include <iostream>
#include "Ex.hpp"
#include <string>

using namespace std;
using namespace ext;

struct Student
{
	int ID;
	int Grade;
	string Name;
};

int main() {
	//Çàäàíèå #1
	setlocale(LC_ALL, "rus");
	Student band[100];
	string dd;
	int choose;
	for (int i = 0; i < 100; i++)
	{
		band[i].Grade = GetRandomValue(0, 100);
		band[i].ID = GetRandomValue(1, 1000);
		int length = GetRandomValue(3, 6);
		char letter = GetRandomValue('A', 'Z');
		dd += letter;
		for (int j = 1; j < length; ++j) {
			dd += GetRandomValue('a', 'z');
		}
		band[i].Name += dd;
		dd = "";
	}
	cout << "Â êàêîì âèäå ïðîèçâåñòè ñîðòèðîâêó? (Ââåäèòå íîìåð)" << endl;
	cout << "1. ID" << endl;
	cout << "2. Grade" << endl;
	cout << "3. Name" << endl;
	cin >> choose;
	if (choose == 1)
	{
		for (int j = 0; j < 100; ++j) 
		{
			for (int k = 0; k < 99; ++k) {
				if (band[k].ID < band[k - 1].ID) swap(band[k], band[k - 1]);
			}
		}
	}
	else if (choose == 2)
	{
		for (int j = 0; j < 100; ++j) 
		{
			for (int k = 99; k < 99; ++k) {
				if (band[k].Grade < band[k - 1].Grade) swap(band[k], band[k - 1]);
			}
		}
	}
	else if (choose == 3)
	{
		for (int j = 0; j < 100; ++j) {
			for (int k = 0; k < 99; ++k) {
				if (band[k].Name < band[k - 1].Name) swap(band[k], band[k - 1]);
			}
		}

	}
	else
	{
		cout << "Ââåäåíû íåêîððåêòíûå äàííûå" << endl;
	}
	for (int i = 0; i < 100; i++) {
		cout << band[i].ID << " " << band[i].Grade << " " << band[i].Name << endl;
	}
	cout << endl;

	//Çàäàíèå #2
	int Mark[100][5];
	float Mid[100];
	int sum;
	sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 5; j++) {
			Mark[i][j] = GetRandomValue(2, 5);
			sum += Mark[i][j];
		}
		Mid[i] = static_cast<float>(sum) / 5;
		sum = 0;
	}
	for (int j = 0; j < 100; j++) {
		for (int k = 0; k < 99; k++) {
			if (Mid[k] > Mid[k + 1]) {
				swap(Mark[k], Mark[k + 1]);
				swap(Mid[k], Mid[k + 1]);
			}
		}
	}
	cout << "Âàì íóæíî ïîëó÷èòü ñëåäóþùèå îöåíêè, ÷òîáû áûòü ëó÷øå 25% ñòóäåíòîâ: ";
	for (int j = 0; j < 5; j++) cout << Mark[26][j] << " ";
	cout << endl;

	cout << "Âàì íóæíî ïîëó÷èòü ñëåäóþùèå îöåíêè, ÷òîáû áûòü ëó÷øå 50% ñòóäåíòîâ: ";
	for (int j = 0; j < 5; j++) cout << Mark[51][j] << " ";
	cout << endl;

	cout << "Âàì íóæíî ïîëó÷èòü ñëåäóþùèå îöåíêè, ÷òîáû áûòü ëó÷øå 75% ñòóäåíòîâ: ";
	for (int j = 0; j < 5; j++) cout << Mark[76][j] << " ";
	cout << endl;
}