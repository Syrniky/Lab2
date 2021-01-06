// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Print_publication.h"
#include "Magazine.h"
#include "Book.h"
#include "Schoolbook.h"
#include "Publisher.h"

using namespace std;

int main()
{
    Print_publication* magazine = new Magazine();
    char* name = new char[] {"Name"};
    char* author = new char[] {"Author"};
    char* publisher_name = new char[] {"Publisher"};
    Print_publication* book = new Schoolbook(name, 2005, author, 5);
    Publisher* publisher = new Publisher(publisher_name);
    publisher->add_publication(magazine);
    publisher->add_publication(book);
    publisher->print_publisher_information();
    cout << "--------------------------------------\n";
   
    publisher->remove_and_delete_publication(book);

    publisher->print_publisher_information();
    delete publisher;
    delete[] name;
    delete[] author;
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
