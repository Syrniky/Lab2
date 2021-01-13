#pragma once
#include "Publisher.h"
#include <string>

enum Command {
	PRINT_ALL,
	ADD_PUBLICATION,
	DELETE_PUBLICATION,
	PRINT_ONE,
	COUNT,
	EXIT,
	NO_COMMAND
};

enum Publication_type {
	MAGAZINE,
	BOOK,
	SCHOOLBOOK,
	NO_TYPE
};

class App
{
private:
	Publisher* publisher;
	Command string_to_command(std::string command);
	Publication_type string_to_publication_type(std::string type);

public:
	App();
	~App();
	void execute();
private:
	void print_all();
	void add_publication();
	void delete_publication();
	void print_one();
	void count();
};

