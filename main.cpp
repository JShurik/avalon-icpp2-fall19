#include <iostream>
#include <fstream>
#include <string>
#include "Book.hpp"

using namespace std;
using namespace ext;

int main()
{
	Book bookss[5] = {
		{ 1, "Clarissa", "Samuel Richardson", 8.75, 1000 },
		{ 2, "Robinson Crusoe", "Daniel Defoe", 7.5, 1000 },
		{ 3, "Tom Jones", "Henry Fielding", 6.55, 1000 },
		{ 4, "Emma", "Jane Austen", 4.1625, 1000 },
		{ 5, "Frankenstein", "Mary Shelley", 1.425, 1000 },
	};

	ofstream fout("books.bin", istream::out | istream::binary);
	fout.write(reinterpret_cast<char*>(&bookss[0]), sizeof(Book) * 5);
	fout.close();
	int staff;
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
			fout.open("books.bin", istream::app);
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
			fin.open("Books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
			fin.close();
		}				
			break;
		case 2: //Редактирование данных о книге
		{
			ifstream fin("books.bin", istream::in | istream::binary);
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

			cout << endl;
			cout << "CHANGE INFORMATION" << endl;
			cout << endl;
			cout << "New book name: ";
			cin >> ptr->Title;
			cout << "Author: ";
			cin >> ptr->Author;
			cout << "New price: ";
			cin >> ptr->Price;
			cout << "Quantity: ";
			cin >> ptr->Quantity;
			cout << endl;
			
			fout.open("Books.bin", ios_base::out | istream::binary);
			fout.write(reinterpret_cast<char*>(&book), sizeof(Book) * count);
			fout.close();
			//fin.open("Books.bin", ios_base::out);
			//fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
			//fin.close();
		}
			break;
		case 3: //Поиск нужной книги по названию
			FindBook();

			break;
		case 4: //Посмотреть отсортированный список книг
			

			

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