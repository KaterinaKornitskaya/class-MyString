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
Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран и деструктор. Также нужно реализовать
статическую функцию-член, которая будет возвращать количество созданных объектов-строк.

В классе MyString перегрузить оператор + (он будет работать как конкатенация строк)
*/

int main()
{
	MyString str1;
	MyString();
	str1.print(1);

	MyString str2(10);
	str2.print(2);

	char* parametr_string = new char[15] {"Hello, world"};
	MyString str3(parametr_string);
	str3.print(3);

	//char user_string[50];
	//std::cout << "Enter string: ";
	//std::cin.getline(user_string, 50);
	//MyString str4(user_string);
	MyString str4;
	str4.set_string();
	str4.print(4);

	char* s1 = new char[6] {"Ivan "};        // строки для конкатенации
	char* s2 = new char [10] {"Ivanovich"};  // строки для конкатенации
	MyString str5(s1);
	MyString str6(s2);
	MyString str7 = str5 + str6;
	str7.print(5);

	std::cout << "Total number of objects-strings: "
		<< MyString::get_string_object() << '\n';

	delete[] parametr_string;
	delete[] s1;
	delete[] s2;

	return 0;
}
