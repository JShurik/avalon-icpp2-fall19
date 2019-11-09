#include <iostream>
#include <limits>

using namespace std;

int main()
{	
	
	setlocale(LC_ALL, "rus");
	char empt[] = " ";
	char type[] = "��� ����������";
	char si[] = "������,";
	char b[] = "���";
	char znach[] = "��������";
	char min[] = "�����������";
	char max[] = "������������";
	char kol[] = "����������";
	char znached[] = "�������� ���";
	char line[] = "=======================================================================================";
	printf("%20s | %12s%5s | %18s%10s | %10s \n", type, si, empt, znach, empt, kol );
	printf("%-20s | %10s%7s | %12s%1s | %12s | %10s \n", empt, b, empt, min, empt, max, znached);
	printf("%72s \n", line);

	char bb[] = "bool";
	int bb1, bb2, bb3, bb4;
	bb1 = sizeof(bool);
	bb2 = numeric_limits<bool>::min();
	bb3 = numeric_limits<bool>::max();
	bb4 = numeric_limits<bool>::digits;
	printf("%-20s | %17d | %13d | %12d | %11d \n", bb, bb1, bb2 , bb3, bb4);

	char cc[] = "short";
	int c1, c2, c3, c4;
	c1 = sizeof(short);
	c2 = numeric_limits<short>::min();
	c3 = numeric_limits<short>::max();
	c4 = numeric_limits<short>::digits;
	printf("%-20s | %17d | %13d | %12d | %11d \n", cc, c1, c2, c3, c4);

	char us[] = "unsigned short";
	int us1, us2, us3, us4;
	us1 = sizeof(unsigned short);
	us2 = numeric_limits<unsigned short>::min();
	us3 = numeric_limits<unsigned short>::max();
	us4 = numeric_limits<unsigned short>::digits;
	printf("%-20s | %17d | %13d | %12d | %11d \n", us, us1, us2, us3, us4);

	char i[] = "int";
	int i1, i2, i3, i4;
	i1 = sizeof(int);
	i2 = numeric_limits<int>::min();
	i3 = numeric_limits<int>::max();
	i4 = numeric_limits<int>::digits;
	printf("%-20s | %17d | %13d | %12d | %11d \n", i, i1, i2, i3, i4);

	char ui[] = "unsigned int";
	unsigned int ui1, ui2, ui3, ui4;
	ui1 = sizeof(unsigned int);
	ui2 = numeric_limits<unsigned int>::min();
	ui3 = numeric_limits<unsigned int>::max();
	ui4 = numeric_limits<unsigned int>::digits;
	printf("%-20s | %17d | %13d | %12d | %11d \n", ui, ui1, ui2, ui3, ui4);

	char l[] = "long";
	long l1, l2, l3, l4;
	l1 = sizeof(long);
	l2 = numeric_limits<long>::min();
	l3 = numeric_limits<long>::max();
	l4 = numeric_limits<long>::digits;
	printf("%-20s | %17d | %13d | %12d | %11d \n", l, l1, l2, l3, l4);

	//char uu[] = "unsigned long";
	//i1 = sizeof(int);
	//i2 = numeric_limits<int>::min();
	//i3 = numeric_limits<int>::max();
	//i4 = numeric_limits<int>::digits;
	//printf("%-20s | %17d | %13d | %12d | %11d \n", uu, i1, i2, i3, i4);


	/*bool
	unsigned short
	short
	unsigned int
	int
	unsigned long
	long
	unsigned long long
	long long
	char
	float
	double*/
	/*������� #2
	�������� ��������� ������� ������� ������ � ��������� ��������� ��������� ������ �� �������. (���������� ������� 10)
	��� �������� ������ ������������ ��������� ������ �������� Nx12(������ - ��� 12 �������� ��������� ������ �� ������ ����������� �����,
		N - ���������� �������).
	������ � ������ ������������ �������� � �������� �� 1000 �� 100000.
	������, ��� ����� ���� ������, � ������� ������ �� ��������.���� ��� �� ���������� �� ������, ���� ��� ���������.
	����� ������ ���������� ��������� - 1 � �� ����������� ��� �������� �������.

	������������ ������� ��� ������������ ������.

	�������, ��� ��� ���������� �������� "����������".�� ���� ����� ��������,
	��� �������� ������ �������� ������ ����, �������� ������ - ������.
	���� �������� ������ �����, �� ������� - ��� ������� �������� ���� �������� "����������"
	��������, ���� ������� ��������� ����� ������ : 10, 6, 2, 14, 7, 9, �� ��� �������� "����������"
	��� 7 � 9. ������� �������� ����� 7 � 9 ��� 8 � ���� ������� ������� ������ ������.
	���������� ���������, ��� ������ ����� ���� ������ ��� ������� � �������� ����.*/



}
