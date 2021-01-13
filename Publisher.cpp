#define _CRT_SECURE_NO_WARNINGS

#include "Publisher.h"

Publisher::Publisher(char* a_name)
{
	set_name(a_name);
	publications = NULL;
}

Publisher::~Publisher()
{
	Node* to_delete = publications;
	Node* next;
	while (to_delete != NULL)
	{
		next = to_delete->next;
		delete to_delete;
		to_delete = next;
	}
}

void Publisher::set_name(char* a_name)
{
	delete[] name;

	if (a_name != NULL)
	{
		name = new char[strlen(a_name) + 1];
		strcpy(name, a_name); // name = a_name;
	}
	else
	{
		name = new char[] {"Default publisher"};
	}
}

char* Publisher::get_name()
{
	return name;
}

Print_publication* Publisher::get_by_number(int number)
{
	Node* node_iterator = publications;
	for (int i = 1; i < number; ++i)
	{
		if (node_iterator == NULL)
		{
			return NULL;
		}
		node_iterator = node_iterator->next;
	}
	if (node_iterator != NULL)
	{
		return node_iterator->value;
	}
	return NULL;
}

void Publisher::add_publication(Print_publication* publication)
{
	if (publications == NULL)
	{
		publications = new Node(publication);
	}
	else
	{
		Node* node_iterator = publications;
		while (node_iterator->next != NULL)
		{
			node_iterator = node_iterator->next;
		}
		node_iterator->next = new Node(publication);
	}
}

void Publisher::remove_and_delete_publication(Print_publication* publication)
{
	if (publication == NULL)
	{
		return;
	}
	Node* iterator = publications;
	if (publications->value == publication)
	{
		publications = publications->next;
		return;
	}
	while (iterator->next != NULL)
	{
		if (iterator->next->value == publication)
		{
			Node* new_next = iterator->next->next;
			delete iterator->next;
			iterator->next = new_next;
			return;
		}
		iterator = iterator->next;
	}
	//std::vector<Print_publication*>::iterator position = std::find(publications.begin(), publications.end(), publication);
	//if (position != publications.end()) // == myVector.end() means the element was not found
	//	publications.erase(position);
	//delete publication;
}

void Publisher::print_publisher_information()
{
	printf("Publisher %s, books:\n", name);
	this->for_each(Print_publication::print);
}

void Publisher::for_each(void(*function)(Print_publication*))
{
	Node* iterator = publications;

	while (iterator != NULL)
	{
		function(iterator->value);
		iterator = iterator->next;
	}
}

int Publisher::count()
{
	Node* iterator = publications;
	int counter = 0;
	while (iterator != NULL)
	{
		++counter;
		iterator = iterator->next;
	}
	return counter;
}

Publisher::Node::Node(Print_publication* a_value)
{
	value = a_value;
	next = NULL;
}

Publisher::Node::~Node()
{
	delete value;
}