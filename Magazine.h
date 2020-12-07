#pragma once

#include "Print_publication.h"

class Magazine : public Print_publication
{
private:
	int month;

public:
	Magazine();
	Magazine(char*, int, int);
	Magazine(Magazine*);
	~Magazine();

	void set_month(int);
	int get_month();

	void read();
};