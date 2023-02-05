#include "Header.h"

int MyString::string_object{ 0 };  // ������������� ������������ ����
// ����������� �� ���������, ����������� ������� ������ 
// ������ 80 ��������
MyString::MyString() : string{ nullptr }, len{ 81 }
{	
	string = new char[len];  // ��������� ������ ��� ������
	string[80] = '\0';       // �������� ��������� ������ ��� 0-����������
	string_object++;         // ���� ��������-����� ��� ����������� �-��					  
};

// �����������, ����������� ��������� ������ ������������� �������
// ��������� ���������� ��������, �� ������� ����� �������� ������ 
MyString::MyString(int string_len)
{
	len = string_len + 1;          // ������������� ������ �� ���������
	string = new char[len];        // ��������� ������ ��� ������
	string [string_len-1] = '\0';  // �������� ��������� ������ ��� 0-����������
	string_object++;			   // ���� ��������-����� ��� ����������� �-��
						
}

// �����������, ������� ������ ������ � �������������� � �������
// ���������� � ���� ��������� ����� ������������
MyString::MyString(const char* parametr_string)
{
	len = strlen(parametr_string + 1);  // ����� ������ �� ���������
	string = new char[len];				// ��������� ������ ��� ������
	strcpy(string, parametr_string);    // ����������� ������ �� ��������� � 
										// ��� ������-������
	string_object++;					// ���� ��������-����� ��� ����������� �-�� 
}

// �����������, ������� ������ ������ � �������������� � �������
// ���������� �� ������������ (� ����������)
MyString::MyString(char* user_string)
{
	len = strlen(user_string) + 1;  // ����� ������ �� ���������
	string = new char[len];			// ��������� ������ ��� ������
	strcpy(string, user_string);    // ����������� ������ �� ��������� � 
									// ��� ������-������
	string_object++;				// ���� ��������-����� ��� ����������� �-��
}

// ����������� �����������
MyString::MyString(const MyString& copy)
{
	std::cout << "\nCOPY CONSTRUCTOR\n";
	len = strlen(copy.string) + 1;
	string = new char[len];       // �������� ����� ������� ������ ��� �������-�����
	strcpy(string, copy.string);  // �������� ���������� � ��������� ������� ������
	string_object++;
}

// ����������� �����������
MyString::MyString(MyString&& obj)  // obj - ������, � �������� ������� ������
{
	std::cout << "\nMOVE CONSTRUCTOR\n";
	string = obj.string;            // ������ ����������� ������ ������� ��������
	len = obj.len;
	obj.string = nullptr;           // ��������� ��������� � ������������� ���������
	obj.len = 0;
}

// ����� ��� ����� ������ � ����������
void MyString::fill_string()
{
	if (string != nullptr) {  // ���� ������ �� ������ - 
		delete[] string;      // �������� ������
	}
	char buffer[256];				// ������� ����� (������)
	std::cout << "Enter your string: \n";
	std::cin.getline(buffer, 256);  // ����������� � ������������ ������
	len = strlen(buffer) + 1;		// ������� ������ ��������� ������
	string = new char[len];			// �������� ������ ��� ��������� ������
	strcpy(string, buffer);			// �������� �� ������ � ������-������
}

// ������� ��� ������������ ����� (���������� ��������� +)
MyString MyString::operator+ (const MyString& str)
{
	MyString temp;					   // �������� ���������� �������, � �������
									   // ����� �������� ����� ���� �����
	temp.len = len + str.len + 1;	   // ���������� ����� ����� ������
	temp.string = new char[temp.len];  // ��������� ������ ��� ����� ������
	strcpy(temp.string, string);       // �������� �� ��������� ������ ������,
									   // ��� ������� ������� �-��
	strcat(temp.string, str.string);   // ��������� ��������� ������-������ ��
									   // �������, ���������� ��� ��������
	return temp;
}

// ����� ����������� � ����� �������-������ ������ ������� 'x'
MyString MyString::operator++(int)
{	
	char* x = new char[2] {"x"};	   // ������ � �������� x
	MyString temp;					   // ��������� ������ ��� "������+�"
	temp.len = len + strlen(x) + 1;    // ����� ��������� ������ "������+�"
	temp.string = new char[temp.len];  // �������� ������ ��� ��������� ������
	strcpy(temp.string, string);	   // �������� � ��������� ������ ���� ������,
									   // ��� ������� ������� �-��
	strcat(temp.string, x);			   // ��������� ������ �

	string = new char[temp.len];	   // �������� ������ ��� ����� ������
	strcpy(string, temp.string);	   // �������� � ����� ������ ��������� ������
	delete[] x;                        // �������� ������
	return temp;					   // ������� ������
}

// ����� �������� ������ ������� �� ����� �������-������
MyString MyString::operator--(int)
{
	MyString temp;						// ��������� ������ 
	temp.len = strlen(string);			// ����� ��������� ������ 
	temp.string = new char[temp.len];   // �������� ������ ��� ��������� ������
	int i = 0;
	for (i = 0; i < temp.len - 1; i++)  // �������� ������ �� �������������� ��-��
	{
		temp.string[i] = string[i];		// �������������� ������
	}
	temp.string[i] = '\0';				// �������� ��������� ������ ��� 0-����������
	string = new char[temp.len];		// �������� ������ ��� ������
	strcpy(string, temp.string);		// �������� �� ���������� ������� 
										// � ������-������
	return *this;						// ���������� ��� ������, ��� ��������
}										// ���������� �-��

// MyString-int (������� �� ����� ������� ����� ���-�� �������� 'x')
MyString MyString::operator-(int number)
{
	MyString temp;						   // ������� ��������� ������ 
	temp.len = strlen(string) - number;    // ����� ���������� �������-������ 
	temp.string = new char[temp.len + 1];  // �������� ������ ��� ��������� ������
	for (int i = 0; i <= temp.len; i++)    // ���� �� ��������
	{
		if (i < temp.len)				   // ��� ������� �� ������� ��������� - 
			temp.string[i] = string[i];    // ��������
		else if (i == temp.len)			   // ���� ��� ��������� ������ 
			temp.string[i] = { '\0' };     // ���������� ��� 0-����������
	}
	string_object++;                       // ���� ��������-����� ��� ����������� �-�� 
	return temp;
}

// MyString+int (�������� � ����� ������� ����� ���-�� �������� 'x')
MyString MyString::operator+(int number)
{
	char* x = new char[number+1];	   // ��������� ������ ��� ������� ��������
	for (int i = 0; i <= number; i++)  // ���� �� ��������
	{
		if (i < number) {			   // ��� ������� �� ������� ��������� - 
			x[i] = { 'x' };			   // ���������� ��� 'x'
		}
		else if (i == number) {		   // ���� ��� ��������� ������ 
			x[i] = { '\0' };		   // ���������� ��� 0-����������
		}
	}

	MyString temp;						   // ������� ��������� ������ 
	temp.len = len + strlen(x);			   // ����� ���������� �������-������
	temp.string = new char[temp.len + 1];  // ��������� ������
	strcpy(temp.string, string);		   // �������� �� ��������� ������ - ������,
										   // ��� ������� ���������� �-��
	strcat(temp.string, x);				   // ��������� ��������� ������ � ������ x

	string_object++;  // ���� ��������-����� ��� ����������� �-�� 
	delete[] x;		  // �������� ������
	return temp;
}

// ���������� ��������� ������������ � ������������
MyString& MyString::operator= (const MyString& obj)
{
	std::cout << "COPY ASSIGNMENT\n";
	if (!(this == &obj))            // ��������, ��� ����� �������, ��� �������� ���������� ����� (this)
	{                               // � ����� �������, ������� ��������� � ���� ��������� (&obj) �� �����
		                            // ����� ��� ������������� � �����o�����
		if (obj.string == nullptr)  // ��������, �� �������� �� ���� ������� obj ������ �������
		{                           // ���� ��������, �� ��������� ��������� �����������
			string = nullptr;
			len = obj.len;
			return *this;
		}
		if (string != nullptr)      // ���� ������ �� ������ - ����� 
		{                           // ���������� ������������� ������
			delete[] string;
		}
		string = new char[strlen(obj.string) + 1];             // ����� ���� �������� ���� �������� ����� �������.������
		strcpy_s(string, strlen(obj.string) + 1, obj.string);  // �������� ��� ������ �� �������, ������� ������ �� ��������� ������������
		len = obj.len;                                         // ��� ���� len ���������� ��������� �����������
	}
	return *this;  // ���������� ���������� ������
}

// ���������� ��������� ������������ � ������������
MyString& MyString::operator=(MyString&& obj)
{
	std::cout << "MOVE ASSIGNMENT\n";
	if (!(this == &obj))       // ��������, ��� ����� �������, ��� �������� ���������� ����� (this)
	{                          // � ����� �������, ������� ��������� � ���� ��������� (&obj) �� �����
						       // ����� ��� ������������� � �����������
		delete[] string;       // ����������� ������ � ������� ����� �� ������������
		string = obj.string;   // ���������� �������� �������� � ������, ������� ����� �� ��.������������
		len = obj.len;
		obj.string = nullptr;  // ���� string ������� obj, ������� ������ �� ��.��������., ��������� � ������������� ���������
		obj.len = 0;
	}
	return *this;              // ���������� ���������� ������, ������� ����� ����� �� ��.��������.
}

// ���������� ��������� < (��������� �����)
bool MyString::operator< (const MyString& str)
{
	return (strcmp(string, str.string) < 0)  // �-�� ��������� �����
		? true  // ���� ��������� < 0 - ������ 1�� ������ < 2o�
		: false;
}

// ���������� ���������� ��������� + (int + string)
MyString operator+(int num, MyString x) 
{
	MyString temp;  // ������� ��������� ������
	char* str_sym = new char[num + 1];  // ������ ��� �������� �
	for (int i{ 0 }; i <= num; ++i)     // ���� �� ���-�� ��������
	{
		if(i < num) str_sym[i] = 'x';        // ��������� �, ����� ����������
		else if (i==num) str_sym[i] = '\0';  // ��������� 0-����������
	}

	// ������ ��� ����� �����: ������� � + ���� ������ 
	char* sym_and_str = new char[strlen(str_sym) + strlen(x.get_str()) + 1];

	strcpy(sym_and_str, str_sym);      // � ����� ������ �������� ������-�
	strcat(sym_and_str, x.get_str());  // ��������� ����� ������ � string
	temp.set_str(sym_and_str);         // ������������� ���������� ������� 
								       // �������-����������� �-�� strcat

	delete[] str_sym;
	delete[] sym_and_str;

	return temp;
}
