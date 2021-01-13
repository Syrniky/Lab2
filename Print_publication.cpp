#define _CRT_SECURE_NO_WARNINGS

#include "Print_publication.h"
#include <string.h>
#include <iostream>

Print_publication::Print_publication()
{
	name = new char[] {"Default name"};
	year = 2020;
}

Print_publication::Print_publication(char* a_name, int a_year)
{
	set_name(a_name);
	year = a_year;
}

Print_publication::Print_publication(Print_publication* a_print_publication)
{
	set_name(a_print_publication->get_name());
	year = a_print_publication->get_year();
}

Print_publication::~Print_publication() 
{
	delete[] name;
}

void Print_publication::set_name(char* a_name) 
{
	delete[] name;

	if (a_name != NULL)
	{
		name = new char[strlen(a_name) + 1];
		strcpy(name, a_name); // name = a_name;
	}
	else
	{
		name = new char[] {"Default name"};
	}
}

void Print_publication::set_year(int a_year)
{
	year = a_year;
}

char* Print_publication::get_name()
{
	return name;
}

int Print_publication::get_year()
{
	return year;
}

void Print_publication::print(Print_publication* publication)
{
	if (publication != NULL)
	{
		publication->read();
	}
}


