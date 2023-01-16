#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyString
{
	char* string;			   // строка
	int len;				   // длина строки
	static int string_object;  // кол-во объектов-строк
public:
	// Конструктор по умолчанию, позволяющий создать строку 
	// длиной 80 символов
	MyString();

	// Конструктор, позволяющий создавать строку произвольного размера
	// принимает количество символов, из которых будет состоять строка 
	MyString(int string_len);

	// Конструктор, который создаёт строку и инициализирует её строкой
	// полученной в виде параметра этого конструктора
	MyString(const char* parametr_string);

	// Конструктор, который создаёт строку и инициализирует её строкой
	// полученной от пользователя (с клавиатуры)
	MyString(char* user_string);

	// Конструктор копирования
	MyString(const MyString& object);

	// метод для ввода строка с клавиатуры
	void set_string();

	// константный метод-гэттер
	const char* get_string() const
	{
		return string;
	}

	// метод вывода строки на экран
	void print(int number)
	{
		std::cout << "RESULT " << number << ": " << string << std::endl;
	}

	// статический метод, возвращает кол-во созданных объектов-строк
	static int get_string_object()
	{
		return string_object;
	}

	// функция для конкатенации строк (перегрузка оператора +)
	MyString operator+ (const MyString&);

	~MyString()  // деструктор
	{
		delete[] string;
	}
};
