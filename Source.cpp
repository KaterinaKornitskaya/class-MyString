#include "Header.h"

int MyString::string_object{ 0 };  // инициализаци€ статического пол€

//  онструктор по умолчанию, позвол€ющий создать строку 
// длиной 80 символов
MyString::MyString() : string{ nullptr }, len{ 81 }
{
	string = new char[len];
	string_object++;
};

//  онструктор, позвол€ющий создавать строку произвольного размера
// принимает количество символов, из которых будет состо€ть строка 
MyString::MyString(int string_len)
{
	len = string_len + 1;
	string = new char[len];
	string_object++;
}

//  онструктор, который создаЄт строку и инициализирует еЄ строкой
// полученной в виде параметра этого конструктора
MyString::MyString(const char* parametr_string)
{
	len = strlen(parametr_string + 1);
	string = new char[len];
	strcpy(string, parametr_string);
	string_object++;
}

//  онструктор, который создаЄт строку и инициализирует еЄ строкой
// полученной от пользовател€ (с клавиатуры)
MyString::MyString(char* user_string)
{
	len = strlen(user_string) + 1;
	string = new char[len];
	strcpy(string, user_string);
	string_object++;
}

//  онструктор копировани€
MyString::MyString(const MyString& object)
{
	len = object.len + 1;
	string = new char[len];
	strcpy(string, object.string);
}

// метод дл€ ввода строка с клавиатуры
void MyString::set_string()
{
	if (string != nullptr) {
		delete[] string;
	}

	char buffer[256];
	std::cout << "Enter your string: \n";
	std::cin.getline(buffer, 256);

	len = strlen(buffer) + 1;
	string = new char[len];
	strcpy(string, buffer);
}

// функци€ дл€ конкатенации строк (перегрузка оператора +)
MyString MyString::operator+ (const MyString& str)
{
	MyString s;					   // создание временного объекта
	s.len = len + str.len + 1;     // вычисление новой длины строки
	s.string = new char[s.len];    // выделение пам€ти под новую строку
	strcpy(s.string, string);      // инициализаци€ первой части строки 
	strcat(s.string, str.string);  // инициализаци€ второй части строки
	return s;
}