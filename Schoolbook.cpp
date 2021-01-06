#include "Schoolbook.h"
#include <iostream>

Schoolbook::Schoolbook() : Book()
{
	grade = 5;
}

Schoolbook::Schoolbook(char* a_name, int a_year, char* a_author, int a_grade) 
	: Book(a_name, a_year, a_author)
{
	grade = a_grade;
}

Schoolbook::Schoolbook(Schoolbook* a_scoolbook) : Book(a_scoolbook)
{
	grade = a_scoolbook->get_grade();
}

Schoolbook::~Schoolbook()
{
}

void Schoolbook::set_grade(int a_grade)
{
	grade = a_grade;
}

int Schoolbook::get_grade()
{
	return grade;
}

void Schoolbook::read()
{
	std::cout << "Schoolbook. Name:" 
		<< name << " Year:" 
		<< year << " Author:" 
		<< author << " Grade:" 
		<< grade << std::endl;
}