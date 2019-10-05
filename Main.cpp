#include <iostream>
#include <string>
#include "Ex.hpp"

using namespace ext;
using namespace std;

////int findMax(int a[], int size)
////{
////	int max = 0;
////	for (int i = 0; i < size; i++)
////	{
////		if (a[i] > max)
////		{
////			max = a[i];
////		}
////	}
////}
//
////int findModa(int a[], int size)
////{
////	for (int i = 0; i < size; ++i)
////	{
////		int current = a[i];
////		int count = 1;
////		for (int j = 0; j < size; ++j)
////		{
////
////		}
////	}
////}
//
//void sortData(int data[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size - 1; j++)
//		{
//			if (data[j] > data[j + 1])
//			{
//			int temp = data[j];
//			data[j] = data[j + 1];
//			data[j + 1] = temp;
//			}		
//		}
//	}
//}
//
//int findModasort(int data[], int size)
//{
//	int countMax = 1;
//	int value = data[0];
//	int count = 0;
//	for (int i = 1; i, size; ++i)
//	{
//		if (data[i] == value)
//		{
//			++countMax;
//		}
//		else
//		{
//			value = data[i];
//			if (count > countMax)
//			{
//				countMax = count;
//				count = 1;
//			}
//		}
//	}
//
//}
//
//int findModa()
//{
//
//}
//
//void PrintData2d(int* a[], int sizeX, int sizeY)
//{
//	for (int i = 0; i < sizeY; ++i)
//	{
//		for (int j = 0; i < sizeX; ++i)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	int a[2][3] = { {2,4,6}, {4,8,10} };
//	
//	int data[] = { 4,7,3,8,9,7,3,9,9,3,3,10 };
//
//
//	sortData(data, sizeof(data) / sizeof(int));
//
//
//	cout << findModasort(data, sizeof(data) / sizeof(int));
//}

int main()
{
	struct Student
	{
		int Id;
		int Grade;
		string Name;
	};
	//Для всех задач данные следует генерировать с помощью библиотеки "Extention.hpp"
	//	Задание #1
	//	Напишите программу которая сортирует массив из структур Student. (N = 100)
	//	struct Student
	//Критерий сортировки необходимо спрашивать у пользователя. (по Id, по Grade, или по Name)
	//	Id в диапазоне от 1 до 1000, Grade от 0 до 100, Name состоит от 3 до 6 английских символов;
	Student abc[100];
	for (int i = 0; i < 100; ++i)
	{
		abc[i].Grade = GetRandomValue(0, 100);
	}
	for (int i = 0; i < 100; ++i))
	{
		int length = GetRandomValue(3, 6);
		abc[i].Name += GetRandomValue('A', 'Z');
		for (int j = 1; j < length; ++j)
		{
			abc[i].Name += GetRandomValue('a', 'z');
		}
	}

	string data[4];
	for (int i = 0; i < 4; i++)
	{
		int length = GetRandomValue(3, 6);
		string current;		
		current += GetRandomValue('A', 'Z');
		for (int j = 1; j < length; ++j)
		{
			current += GetRandomValue('a', 'z');
		}
	}



	//Задание #2
	//	Напишите программу, которая анализирует массив студентов и определяет, какие оценки необходимо получить,
	//	чтобы стать лучше 25 % студентов, 50 % студентов, 75 % студентов.




}