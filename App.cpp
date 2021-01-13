#include "App.h"
#include <string>
#include <iostream>
#include "Magazine.h"
#include "Book.h"
#include "Schoolbook.h"
using namespace std;



Command App::string_to_command(string command)
{
	if (command == "printAll") 
	{
		return PRINT_ALL;
	}
	if (command == "add")
	{
		return ADD_PUBLICATION;
	}
	if (command == "delete")
	{
		return DELETE_PUBLICATION;
	}
	if (command == "printOne")
	{
		return PRINT_ONE;
	}
	if (command == "count")
	{
		return COUNT;
	}
	if (command == "exit")
	{
		return EXIT;
	}
	return NO_COMMAND;
}

Publication_type App::string_to_publication_type(std::string type)
{
	if (type == "magazine") 
	{
		return MAGAZINE;
	}
	if (type == "book")
	{
		return BOOK;
	}
	if (type == "schoolbook")
	{
		return SCHOOLBOOK;
	}
	return NO_TYPE;
}

App::App()
{
	char* name = new char[]{ "Publisher name" };
	publisher = new Publisher(name);
	delete[] name;
}

App::~App() {
	delete publisher;
}

void App::execute()
{

	string command_from_input;
	Command command = NO_COMMAND;
	while (command != EXIT)
	{
		cin >> command_from_input;
		command = string_to_command(command_from_input);

		switch (command)
		{
		case PRINT_ALL:
			print_all();
			break;
		case ADD_PUBLICATION:
			add_publication();
			break;
		case DELETE_PUBLICATION:
			delete_publication();
			break;
		case PRINT_ONE:
			print_one();
			break;
		case COUNT:
			count();
			break;
		case NO_COMMAND:
			cout << "There is no such command" << endl;
			break;
		}
	}
	
}

void App::print_all()
{
	publisher->print_publisher_information();
}

void App::add_publication()
{
	string type_from_input;
	cin >> type_from_input;
	Publication_type type = string_to_publication_type(type_from_input);

	char* a_name = new char[20];
	int a_year;
	int a_month;
	char* a_author = new char[20];
	int a_grade;

	switch (type)
	{
	case MAGAZINE:
		cin >> a_name;
		cin >> a_year;
		cin >> a_month;

		publisher->add_publication(new Magazine(a_name, a_year, a_month));
		break;
	case BOOK:	
		cin >> a_name;
		cin >> a_year;
		cin >> a_author;

		publisher->add_publication(new Book(a_name, a_year, a_author));
		break;
	case SCHOOLBOOK:
		cin >> a_name;
		cin >> a_year;
		cin >> a_author;
		cin >> a_grade;

		publisher->add_publication(new Schoolbook(a_name, a_year, a_author, a_grade));
		break;
	case NO_TYPE:
		cout << "There is no such type" << endl;
		break;
	}

	delete[] a_author;
	delete[] a_name;
}

void App::delete_publication()
{
	int number;
	cin >> number;
	publisher->remove_and_delete_publication(publisher->get_by_number(number));
}

void App::print_one()
{
	int number;
	cin >> number;
	Print_publication::print(publisher->get_by_number(number));
}

void App::count()
{
	cout << publisher->count() << endl;
}
