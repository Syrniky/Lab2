#pragma once


class Print_publication
{
protected:
	char* name;
	int year;

public:
	Print_publication();
	Print_publication(char*, int);
	Print_publication(Print_publication*);
	virtual ~Print_publication();

	void set_name(char*);
	void set_year(int);
	char* get_name();
	int get_year();

	virtual void read() = 0;

	static void print(Print_publication* publication);
};
