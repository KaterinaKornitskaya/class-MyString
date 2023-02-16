// class String2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"

/*
Разработать класс MyString, который в дальнейшем будет
использоваться для работы со строками. Класс должен
содержать:
• Конструктор по умолчанию, позволяющий создать
строку длиной 80 символов;
• Конструктор, позволяющий создавать строку произвольного размера 
  (принимает количество символов, из которых будет состоять строка);
• Конструктор, который создаёт строку и инициализирует её строкой, 
  полученной в виде параметра этого конструктора;
• Конструктор, который создаёт строку и инициализирует её строкой, 
  полученной от пользователя (с клавиатуры).
Класс должен содержать методы для ввода строк с клавиатуры и вывода строк 
на экран и деструктор. 
Также нужно реализовать статическую функцию-член, которая будет возвращать 
количество созданных объектов-строк.

В классе MyString перегрузить оператор + (он будет работать как конкатенация строк)

Добавить в ваш класс MyString перегрузку операторов и конструкторы:
- "++" (добавление к концу нашего объекта-строки одного символа 'x'),
- "--" (удаление одного символа из конца нашего объекта-строки).
- MyString + int (например, добавление к концу нашего объекта
  определенного количества символов 'x', первоначальный объект не меняется)
- MyString - int (например, удаление определенного количества символов
  из конца нашего объекта, первоначальный объект не меняется)
- перегрузка оператора <
- глобальная перегрузка оператора "+" - увеличение строки на N символов 
  (символы записываются в начало)
- конструктор копирования
- конструктор перемещения
- перегрузка оператора присваивания копированием
- перегрузка оператора присваивания перемещением
- конструктор Initializer_list
*/

int main()
{
	MyString string1{ 'a', 'b', 'c', '\0'};
	string1.print();
	std::cout << std::endl;
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << string1[i] << std::endl;
	//}
	std::cout << "Constructor by defoult: allow to create 80-char string:\n";
	MyString str1;
	str1.print();
	std::cout << std::endl;

	std::cout << "Constructor with parametr: allow to create parametr-size string:\n";
	MyString str2(10);
	str2.print();
	std::cout << std::endl;

	std::cout << "Constructor with parametr: allow to create string from parametr:\n";
	char* parametr_string = new char[15] {"Hello, world"};
	MyString str3(parametr_string);
	str3.print();
	std::cout << std::endl;

	std::cout << "Constructor with parametr: allow to create string from user:\n";
	MyString str4;
	str4.fill_string();
	str4.print();
	std::cout << std::endl;

	std::cout << "Overloaded +, string concatenation:\n";
	char* s1 = new char[6] {"aaaaa"};    // строки для конкатенации
	char* s2 = new char [10] {"bbbbb"};  // строки для конкатенации
	MyString str5(s1);
	MyString str6(s2);
	MyString str7 = str5 + str6;
	str7.print();
	std::cout << std::endl;

	std::cout << "Overloaded ++: add a single 'x' char to the end of string:\n";
	MyString str8;
	str8.fill_string();
	str8++;
	str8.print();
	std::cout << std::endl;

	std::cout << "Overloaded --: remov one char from the end of string:\n";
	MyString str9;
	str9.fill_string();
	str9--;
	str9.print();
	std::cout << std::endl;

	std::cout << "Overloaded + (MyString+int): add 4 char 'x' to the end of string:\n";
	MyString str11;
	str11 = str9 + 4;
	str11.print();
	std::cout << std::endl;

	std::cout << "Overloaded - (MyString-int): delete 3 char from the end of string:\n";
	MyString str12;
	str12 = str9 - 3;
	str12.print();
	std::cout << std::endl;

	std::cout << "Overloaded < \n";
	bool result = str5 < str6;
	if (result == 1)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Overloaded + (int+MyString): add 3 char 'x' to the start of string:\n";
	MyString str16;
	str16 = 3 + str7;
	str16.print();
	std::cout << std::endl;

	std::cout << "Total number of objects-strings: "  // вывод кол-ва объектов-строк
		<< MyString::get_string_object() << '\n';     // считали в статической ф-ии
	std::cout << std::endl;

	delete[] parametr_string;  // удаление памяти
	delete[] s1;			   // удаление памяти
	delete[] s2;			   // удаление памяти

	return 0;
}
