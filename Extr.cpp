#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	//До 2007 ISBN состоял 10 цифр(ISBN - 10). 9 из них произвольные и 1 - контрольная.
	//	Контрольная цифра предназначена для верификации правильности полученного номера.
	//	Она вычисляется по следующему правилу :
	//Пусть есть номер 030640615
	//	1. Высчитывается сумма, где каждое слагаемое это цифра умноженная на ее вес.Вес начинается с 10 и уменьшается до 2.
	//	0?10 + 3?9 + 0?8 + 6?7 + 4?6 + 0?5 + 6?4 + 1?3 + 5?2 = 130.
	//	2. Получаем остаток от деления на 11 полученной суммы.
	//	130 % 11 = 9
	//	3. Контрольная цифра это цифра которую необходимо добавить к полученной сумме, чтобы она стала делиться на 11 без остатка.
	//	11 - 9 = 2

	//	В итоге 0306406152 - действительный ISBN - 10

	//	В том случае, если к полученной сумме необходимо добавить 10 контрольной "цифрой" будет X

	//	Ваша задача, написать программу которая бы запрашивала у пользователя тип номера(ISBN - 10 или ISBN - 13) для проверки.
	//	Пользователь вводит некоторый номер.
	//	Программа должна провести его валидацию и сообщить, действителен ли данный номер.
	bool valid = false;
	long long ISBN, ISBNcopy, ISBNvalid;
	int type;
	cout << "Выберете тип номера: " << endl;
	cout << "1. ISBN-10" << endl << "2. ISBN-13" << endl;
	cin >> type;
	if (type == 1)
	{
		cout << "Введите ISBN   ";
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
		if (valid) cout << "       валиден" << endl;
		else cout << "       невалиден" << endl;
		cout << endl;
	}
	else
	{
		cout << "Введите ISBN   ";
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
		if (valid) cout << "       валиден" << endl;
		else cout << "       невалиден" << endl;
		cout << endl;
	}

}