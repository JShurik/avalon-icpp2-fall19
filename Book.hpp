#pragma once
#include <fstream>
#include <iostream>

using namespace std;

//добавлять книгу
//редактировать книгу(по id)
//искать книгу(по названию)
//просматривать список книг(отсортированный по автору и затем по названию)
//показывать статистику(всего книг в библиотеке, общая стоимость всех книг)

namespace ext
{
	struct Book
	{
		static const int BUFFER_SIZE = 20;
		int Id;
		char Title[BUFFER_SIZE];
		char Author[BUFFER_SIZE];
		float Price;
		int Quantity;
	};

	//void swap(Book* book1, Book* book2)
	//{
	//	Book *temp;
	//	temp = book2;
	//	book2 = book1;
	//	book1 = temp;
	//}

	void FindBook() 
	{
		ifstream fin("books.bin", istream::in | istream::binary);
		fin.seekg(0, ios_base::end);
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);
		Book* book = new Book[count];
		fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
		fin.close();

		string title;
		cout << "Enter the book name: ";
		cin >> title;
		Book* ptr = nullptr;
		for (int i = 0; i < count; ++i)
		{
			string temp(book[i].Title);
			if (title == temp)
			{
				ptr = &book[i];
				break;
			}
		}
		if (ptr == nullptr)
		{
			cout << "Book <" << title << "> was not found" << endl;
		}
		else
		{
			cout << endl;
			cout << "INFORMATION" << endl;
			cout << "Book ID: " << ptr->Id << endl;
			cout << "Author: " << ptr->Author <<  endl;
			cout << "Price: " << ptr->Price << endl;
			cout << "Quantity: " << ptr->Quantity << endl;
		}
	}


}

