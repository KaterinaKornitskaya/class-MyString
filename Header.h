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
	void fill_string();

	void set_str(char* str)
	{
		len = strlen(str);
		string = new char[len + 1];
		if (str)
		{
			strcpy(string, str);
		}
	}

	char* get_str() const
	{
		return string;
	}

	// метод вывода строки на экран
	void print(int number)
	{
		std::cout << "RES STRING " << number << ": " << string << std::endl;
	}

	// статический метод, возвращает кол-во созданных объектов-строк
	static int get_string_object()
	{
		return string_object;
	}

	// функция для конкатенации строк (перегрузка оператора +)
	MyString operator+ (const MyString&);

	// метод добавлениея к концу объекта-строки одного символа 'x'
	MyString operator++(int);

	// метод удаление одного символа из конца объекта-строки
	MyString operator--(int);

	// MyString+int (добавить к концу объекта некое кол-во символов 'x')
	MyString operator+(int number);

	// MyString-int (удалить из конца объекта некое кол-во символов 'x')
	MyString operator-(int number);

	// перегрузка оператора присваивания, реализующая безопасное присваивание
	MyString& operator= (const MyString& str);

	// перегрузка оператора < (сравнение строк)
	bool operator< (const MyString& str);

	~MyString()  // деструктор
	{
		delete[] string;
		string_object--;
	}
};

// глобальная перегрузка оператора + (int + string)
MyString operator+(int num, MyString cont_string);
