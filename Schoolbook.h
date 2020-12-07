#pragma once

#include "Book.h"

class Schoolbook : public Book
{
private:
	int grade;

public:
	Schoolbook();
	Schoolbook(char*, int, char*, int);
	Schoolbook(Schoolbook*);
	~Schoolbook();

	void set_grade(int);
	int get_grade();

	void read();
};