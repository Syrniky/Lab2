#include "Magazine.h"
#include <iostream>

Magazine::Magazine() : Print_publication()
{
	month = 1;
}

Magazine::Magazine(char* a_name, int a_year, int a_month) : Print_publication(a_name, a_year)
{
	month = a_month;
}

Magazine::Magazine(Magazine* a_magazine) : Print_publication(a_magazine)
{
	month = a_magazine->get_month();
}

Magazine::~Magazine() 
{	
}

void Magazine::set_month(int a_month)
{
	month = a_month;
}

int Magazine::get_month()
{
	return month;
}

void Magazine::read() {
	std::cout << "Magazine. Name:" 
		<< name << " Year:" 
		<< year << " Month:" 
		<< month << std::endl;
}