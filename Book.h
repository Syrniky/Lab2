#pragma once

#include "Print_publication.h"

class Book : public Print_publication
{
protected:
	char* author;
public:
	Book();
	Book(char*, int, char*);
	Book(Book*);
	~Book();

	void set_author(char*);
	char* get_author();

	void read();
};