#pragma once


class Print_publication
{
protected:
	static Print_publication* begin;
	char* name;
	int year;
	Print_publication* next;

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

	void add();
	void delete_from_list();

	static void print_all();
};
