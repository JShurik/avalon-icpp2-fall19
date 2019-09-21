#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	//�� 2007 ISBN ������� 10 ����(ISBN - 10). 9 �� ��� ������������ � 1 - �����������.
	//	����������� ����� ������������� ��� ����������� ������������ ����������� ������.
	//	��� ����������� �� ���������� ������� :
	//����� ���� ����� 030640615
	//	1. ������������� �����, ��� ������ ��������� ��� ����� ���������� �� �� ���.��� ���������� � 10 � ����������� �� 2.
	//	0?10 + 3?9 + 0?8 + 6?7 + 4?6 + 0?5 + 6?4 + 1?3 + 5?2 = 130.
	//	2. �������� ������� �� ������� �� 11 ���������� �����.
	//	130 % 11 = 9
	//	3. ����������� ����� ��� ����� ������� ���������� �������� � ���������� �����, ����� ��� ����� �������� �� 11 ��� �������.
	//	11 - 9 = 2

	//	� ����� 0306406152 - �������������� ISBN - 10

	//	� ��� ������, ���� � ���������� ����� ���������� �������� 10 ����������� "������" ����� X

	//	���� ������, �������� ��������� ������� �� ����������� � ������������ ��� ������(ISBN - 10 ��� ISBN - 13) ��� ��������.
	//	������������ ������ ��������� �����.
	//	��������� ������ �������� ��� ��������� � ��������, ������������ �� ������ �����.
	bool valid = false;
	long long ISBN, ISBNcopy, ISBNvalid;
	int type;
	cout << "�������� ��� ������: " << endl;
	cout << "1. ISBN-10" << endl << "2. ISBN-13" << endl;
	cin >> type;
	if (type == 1)
	{
		cout << "������� ISBN   ";
		cin >> ISBN;
		ISBNcopy = ISBN % 10;
		ISBN /= 10;
		ISBNvalid = 0;
		for (int j = 2; j <= 10; ++j)
		{
			ISBNvalid += (ISBN % 10) * j;
			ISBN /= 10;
		}
		ISBNvalid %= 11;
		ISBNvalid = 11 - ISBNvalid;
		valid = ISBNcopy == ISBNvalid;
		if (valid) cout << "       �������" << endl;
		else cout << "       ���������" << endl;
		cout << endl;
	}
	else
	{
		cout << "������� ISBN   ";
		cin >> ISBN;
		ISBNcopy = ISBN % 10;
		ISBN /= 10;
		ISBNvalid = 0;
		for (int j = 1; j <= 12; ++j)
		{
			if (j % 2 == 1)	ISBNvalid += (ISBN % 10) * 3;
			else ISBNvalid += (ISBN % 10) * 1;
			ISBN /= 10;
		}
		ISBNvalid %= 10;
		ISBNvalid = 10 - ISBNvalid;
		valid = ISBNcopy == ISBNvalid;
		if (valid) cout << "       �������" << endl;
		else cout << "       ���������" << endl;
		cout << endl;
	}

}