#pragma once
#include <vector>
#include "Print_publication.h"
class Publisher
{
private:
	struct Node
	{
		Print_publication* value;
		Node* next;

		Node(Print_publication* a_value);
		~Node();
	};

	Node* publications;
	char* name;

public:
	Publisher(char* a_name);
	~Publisher();

	void set_name(char* a_name);
	char* get_name();

	Print_publication* get_by_number(int number);
	
	void add_publication(Print_publication* publication);
	void remove_and_delete_publication(Print_publication* publication);
	void print_publisher_information();
	void for_each(void (*function)(Print_publication*));
	int count();
};


