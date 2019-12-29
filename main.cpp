#include <iostream>
#include <fstream>
#include <string>
#include "Book.hpp"

using namespace std;
using namespace ext;

int main()
{
	Book bookss[5] = {
		{ 1, "Clarissa", "Richardson", 8.75, 1000 },
		{ 2, "RobinsonCrusoe", "Defoe", 7.5, 1000 },
		{ 3, "TomJones", "Fielding", 6.55, 1000 },
		{ 4, "Emma", "JaneAusten", 4.1625, 1000 },
		{ 5, "Frankenstein", "Shelley", 1.425, 1000 },
	};

	ofstream fout("books.bin", istream::out | istream::binary);
	fout.write(reinterpret_cast<char*>(&bookss[0]), sizeof(Book) * 5);
	fout.close();
	int choice = 0;

	while (choice != 6)
	{
		ifstream fin("books.bin", istream::in | istream::binary);
		fin.seekg(0, ios_base::end);
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);

		Book* books = new Book[count];
		float sum_price = 0;
		int sum_quantity = 0;
		cout << "=========== MAIN ============ " << endl;	
		cout << "1. Add a Book" << endl;
		cout << "2. Change Book" << endl;
		cout << "3. Find Book" << endl;
		cout << "4. Show list" << endl;
		cout << "5. Show stat" << endl;
		cout << "6. End programm" << endl;
		cout << "Make your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: //Добавление книги в бинарный файл
		{
			fout.open("books.bin", istream::binary | istream::out | istream::app);
			Book book{};
			cout << "Enter ID: ";
			cin >> book.Id;
			cout << "Enter Title: ";
			cin >> book.Title;
			cout << "Enter Author: ";
			cin >> book.Author;
			cout << "Enter Price: ";
			cin >> book.Price;
			cout << "Enter Quantity: ";
			cin >> book.Quantity;

			fout.write(reinterpret_cast<char*>(&book), sizeof(Book));
			fout.close();
			/*fin.open("Books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
			fin.close();*/
		}				
			break;
		case 2: //Редактирование данных о книге
		{
			ifstream fin("Books.bin", istream::in | istream::binary);

			fin.seekg(0, ios_base::end);
			int size = fin.tellg();
			int count = size / sizeof(Book);
			fin.seekg(0, ios_base::beg);

			Book* book = new Book[count];
			fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
			fin.close();
			int id;
			cout << "Enter ID: ";
			cin >> id;
			cout << endl;


			Book* ptr = nullptr;
			for (int i = 0; i < count; ++i)
			{
				if (id == book[i].Id)
				{
					ptr = &book[i];
					break;
				}
			}

			if (ptr == nullptr)
			{

			}
			else
			{
				cout << " CHANGE INFORMATION" << endl;
				cout << endl;
				cout << "Name: ";
				cin >> ptr->Title;
				cout << "Autor: ";
				cin >> ptr->Author;
				cout << "Price: ";
				cin >> ptr->Price;
				cout << "Quantity: ";
				cin >> ptr->Quantity;
				cout << endl;
				fout.open("books.bin", istream::binary | istream::out);
				fout.write(reinterpret_cast<char*>(book), sizeof(Book) * count);
				fout.close();				
			}			
		}
			break;
		case 3: //Поиск нужной книги по названию
			FindBook();
			break;
		case 4: //Посмотреть отсортированный список книг
		{
			ifstream fin("Books.bin", istream::in | istream::binary);

			fin.seekg(0, ios_base::end);
			int size = fin.tellg();
			int count = size / sizeof(Book);
			fin.seekg(0, ios_base::beg);

			Book* book = new Book[count];
			fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
			fin.close();
			int k = 0;
			cout << endl;
			cout << " LIST" << endl;
			for (int i = 0; i < count; i++) {
				for (int j = count - 1; j > i; j--) {
					string temp1(book[j-1].Author);
					temp1 += string(book[j-1].Title);
					string temp2(book[j].Author);
					temp2 += string(book[j].Title);
					if (temp1 > temp2) {
						swap(book[j-1], book[j]);
					}
				}
			}
			for (int i = 0; count > i; i++) {
				cout << book[i].Id << ": <" << book[i].Title << "> " << book[i].Author << "; " << book[i].Price << "; " << book[i].Quantity << endl;
			}
		}
			break;
		case 5: //Показать статистику
			fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
			fin.close();
			cout << endl;
			for (int i = 0; i < count; ++i)
			{
				sum_price += books[i].Price;
				sum_quantity += books[i].Quantity;
			}
			cout << "Summary price of books: " << sum_price << endl;
			cout << "Summary quantity: " << sum_quantity << endl;

			break;
		case 6: //Пустой case для завершения программы
			break;
		default:
			cout << "Error" << endl;
			break;
		}
		cout << endl;
	}
}