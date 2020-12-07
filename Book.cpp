#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"
#include <string.h>
#include <iostream>

Book::Book() : Print_publication()
{
	author = new char[] {"Default author"};
}

Book::Book(char* a_name, int a_year, char* a_author) : Print_publication(a_name, a_year)
{
	set_author(a_author);
}

Book::Book(Book* a_book) : Print_publication(a_book)
{
	set_author(a_book->get_author());
}

Book::~Book()
{
	delete[] author;
}

void Book::set_author(char* a_author)
{
	delete[] author;

	if (a_author != NULL)
	{
		author = new char[strlen(a_author) + 1];
		strcpy(author, a_author); // name = a_name;
	}
	else
	{
		name = new char[] {"Default name"};
	}
}

char* Book::get_author()
{
	return author;
}

void Book::read()
{
	std::cout << "You`re reading a book " 
		<< name << " from year " 
		<< year << " and author " 
		<< author << std::endl;
}