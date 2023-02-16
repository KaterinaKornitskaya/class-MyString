#include "Header.h"

int MyString::string_object{ 0 };  // инициализация статического поля
// Конструктор по умолчанию, позволяющий создать строку 
// длиной 80 символов
MyString::MyString() : string{ nullptr }, len{ 81 }
{	
	string = new char[len];  // выделение памяти для строки
	string[80] = '\0';       // отмечаем последний символ как 0-терминатор
	string_object++;         // счет объектов-строк для статической ф-ии					  
};

// Конструктор, позволяющий создавать строку произвольного размера
// принимает количество символов, из которых будет состоять строка 
MyString::MyString(int string_len)
{
	len = string_len + 1;          // инициализация длиной из параметра
	string = new char[len];        // выделение памяти для строки
	string [string_len-1] = '\0';  // отмечаем последний символ как 0-терминатор
	string_object++;			   // счет объектов-строк для статической ф-ии
						
}

// Конструктор, который создаёт строку и инициализирует её строкой
// полученной в виде параметра этого конструктора
MyString::MyString(const char* parametr_string)
{
	len = strlen(parametr_string + 1);  // длина строки из параметра
	string = new char[len];				// выделение памяти под строку
	strcpy(string, parametr_string);    // копирование строки из параметра в 
										// наш объект-строку
	string_object++;					// счет объектов-строк для статической ф-ии 
}

// Конструктор, который создаёт строку и инициализирует её строкой
// полученной от пользователя (с клавиатуры)
MyString::MyString(char* user_string)
{
	len = strlen(user_string) + 1;  // длина строки из параметра
	string = new char[len];			// выделение памяти под строку
	strcpy(string, user_string);    // копирование строки из параметра в 
									// наш объект-строку
	string_object++;				// счет объектов-строк для статической ф-ии
}

// Конструктор копирования
MyString::MyString(const MyString& copy)
{
	std::cout << "\nCOPY CONSTRUCTOR\n";
	len = strlen(copy.string) + 1;
	string = new char[len];       // выделяем новую область памяти для объекта-копии
	strcpy(string, copy.string);  // копируем содержимое в созданную область памяти
	string_object++;
}

// Конструктор перемещения
MyString::MyString(MyString&& obj)  // obj - объект, у которого забрали ресурс
{
	std::cout << "\nMOVE CONSTRUCTOR\n";
	string = obj.string;            // теперь создаваемый объект владеет ресурсом
	len = obj.len;
	obj.string = nullptr;           // оставляем указатель в согласованном состоянии
	obj.len = 0;
}

// метод для ввода строка с клавиатуры
void MyString::fill_string()
{
	if (string != nullptr) {  // если строка не пустая - 
		delete[] string;      // очистить строку
	}
	char buffer[256];				// создаем буфер (массив)
	std::cout << "Enter your string: \n";
	std::cin.getline(buffer, 256);  // запрашиваем у пользователя данные
	len = strlen(buffer) + 1;		// считаем размер введенной строки
	string = new char[len];			// выделяем память под введенную строку
	strcpy(string, buffer);			// копируем из буфера в объект-строку
}

// функция для конкатенации строк (перегрузка оператора +)
MyString MyString::operator+ (const MyString& str)
{
	MyString temp;					   // создание временного объекта, в котором
									   // будет хранится сумма двух строк
	temp.len = len + str.len + 1;	   // вычисление новой длины строки
	temp.string = new char[temp.len];  // выделение памяти под новую строку
	strcpy(temp.string, string);       // копируем во временный объект строку,
									   // для которой вызвана ф-ия
	strcat(temp.string, str.string);   // соединяем временный объект-строку со
									   // строкой, переданной как параметр
	return temp;
}

// метод добавлениея к концу объекта-строки одного символа 'x'
MyString MyString::operator++(int)
{	
	char* x = new char[2] {"x"};	   // строка с символом x
	MyString temp;					   // временный объект для "строка+х"
	temp.len = len + strlen(x) + 1;    // длина временной строки "строка+х"
	temp.string = new char[temp.len];  // выделяем память для временной строки
	strcpy(temp.string, string);	   // копируем в временную строку нашу строку,
									   // для которой вызвана ф-ия
	strcat(temp.string, x);			   // добавляем сомвол х

	string = new char[temp.len];	   // выделяем память для новой строки
	strcpy(string, temp.string);	   // копируем в новую строку временную строку
	delete[] x;                        // удаление памяти
	return temp;					   // возврат строки
}

// метод удаление одного символа из конца объекта-строки
MyString MyString::operator--(int)
{
	MyString temp;						// временный объект 
	temp.len = strlen(string);			// длина временной строки 
	temp.string = new char[temp.len];   // выделяем память для временной строки
	int i = 0;
	for (i = 0; i < temp.len - 1; i++)  // проходим циклом до предпоследнего эл-та
	{
		temp.string[i] = string[i];		// перезаписываем строку
	}
	temp.string[i] = '\0';				// отмечаем последний символ как 0-терминатор
	string = new char[temp.len];		// выделяем память под строку
	strcpy(string, temp.string);		// копируем из временного объекта 
										// в объект-строку
	return *this;						// возвращаем наш объект, для которого
}										// вызывалась ф-ия

// MyString-int (удалить из конца объекта некое кол-во символов 'x')
MyString MyString::operator-(int number)
{
	MyString temp;						   // создаем временный объект 
	temp.len = strlen(string) - number;    // длина временного объекта-строки 
	temp.string = new char[temp.len + 1];  // выделяем память для временной строки
	for (int i = 0; i <= temp.len; i++)    // цикл по символам
	{
		if (i < temp.len)				   // все семволы НЕ включая последний - 
			temp.string[i] = string[i];    // копируем
		else if (i == temp.len)			   // если это последний символ 
			temp.string[i] = { '\0' };     // определить как 0-терминатор
	}
	string_object++;                       // счет объектов-строк для статической ф-ии 
	return temp;
}

// MyString+int (добавить к концу объекта некое кол-во символов 'x')
MyString MyString::operator+(int number)
{
	char* x = new char[number+1];	   // выделение памяти для массива символов
	for (int i = 0; i <= number; i++)  // цикл по символам
	{
		if (i < number) {			   // все семволы НЕ включая последний - 
			x[i] = { 'x' };			   // записываем как 'x'
		}
		else if (i == number) {		   // если это последний символ 
			x[i] = { '\0' };		   // определить как 0-терминатор
		}
	}

	MyString temp;						   // создаем временный объект 
	temp.len = len + strlen(x);			   // длина временного объекта-строки
	temp.string = new char[temp.len + 1];  // выделение памяти
	strcpy(temp.string, string);		   // копируем во временную строку - строку,
										   // для которой вызывается ф-ия
	strcat(temp.string, x);				   // соединяем временную строку и строку x

	string_object++;  // счет объектов-строк для статической ф-ии 
	delete[] x;		  // удаление памяти
	return temp;
}

// перегрузка оператора присваивания с копированием
MyString& MyString::operator= (const MyString& obj)
{
	std::cout << "COPY ASSIGNMENT\n";
	if (!(this == &obj))            // проверка, что адрес объекта, для которого вызывается метод (this)
	{                               // и адрес объекта, который поступает в виде параметра (&obj) не равны
		                            // иначе нет необходимости в копирoвании
		if (obj.string == nullptr)  // проверка, не является ли поле объекта obj пустой строкой
		{                           // если является, то выполняем побитовте копирование
			string = nullptr;
			len = obj.len;
			return *this;
		}
		if (string != nullptr)      // если строка не пустая - нужно 
		{                           // освободить динамическуюю память
			delete[] string;
		}
		string = new char[strlen(obj.string) + 1];             // после всех проверок выше выделяем новую динамич.память
		strcpy_s(string, strlen(obj.string) + 1, obj.string);  // копируем все данные из объекта, который справа от оператора присваивания
		len = obj.len;                                         // для поля len используем побитовое копирование
	}
	return *this;  // возвращаем измененный объект
}

// перегрузка оператора присваивания с перемещением
MyString& MyString::operator=(MyString&& obj)
{
	std::cout << "MOVE ASSIGNMENT\n";
	if (!(this == &obj))       // проверка, что адрес объекта, для которого вызывается метод (this)
	{                          // и адрес объекта, который поступает в виде параметра (&obj) не равны
						       // иначе нет необходимости в перемещении
		delete[] string;       // освобождвем память в объекте слева от присваивания
		string = obj.string;   // перемещаем владение ресурсом в объект, который слева от оп.присваивания
		len = obj.len;
		obj.string = nullptr;  // поле string объекта obj, который справа от оп.присваив., оставляем в согласованном состоянии
		obj.len = 0;
	}
	return *this;              // возвращаем измененный объект, который стоит слева от оп.присваив.
}

// перегрузка оператора < (сравнение строк)
bool MyString::operator< (const MyString& str)
{
	return (strcmp(string, str.string) < 0)  // ф-ия сравнения строк
		? true  // если результат < 0 - значит 1ая строка < 2oй
		: false;
}

// глобальная перегрузка оператора + (int + string)
MyString operator+(int num, MyString x) 
{
	MyString temp;  // создаем временный объект
	char* str_sym = new char[num + 1];  // стркоа для символов х
	for (int i{ 0 }; i <= num; ++i)     // цикл по кол-ву символов
	{
		if(i < num) str_sym[i] = 'x';        // заполняем х, кроме последнего
		else if (i==num) str_sym[i] = '\0';  // последний 0-терминатор
	}

	// строка для суммы строк: символы х + наша строка 
	char* sym_and_str = new char[strlen(str_sym) + strlen(x.get_str()) + 1];

	strcpy(sym_and_str, str_sym);      // в нувую строку копируем строку-х
	strcat(sym_and_str, x.get_str());  // соединяем новую строку с string
	temp.set_str(sym_and_str);         // инициализация временного объекта 
								       // строкой-результатом ф-ии strcat

	delete[] str_sym;
	delete[] sym_and_str;

	return temp;
}

// конструктор initializer_list
MyString::MyString(const std::initializer_list<char>& list)
	: MyString(list.size())
{
	len = list.size();
	std::cout << "INITIALIZER LIST\n";
	for (auto ptr = list.begin(); ptr != list.end(); ptr++)
	{
		*string = *ptr;
		string++;
	}
	string -= len;
}

//// конструктор initializer_list(второй вариант)
//MyString::MyString(const std::initializer_list<char>& list)
//	: MyString(list.size())
//{
//	std::cout << "INITIALIZER LIST\n";
//	int i = 0;
//	for (auto element : list)
//	{
//		string[i] = element;
//		i++;
//	}
//}

