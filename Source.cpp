#include "Header.h"

int MyString::string_object{ 0 };  // ������������� ������������ ����

// ����������� �� ���������, ����������� ������� ������ 
// ������ 80 ��������
MyString::MyString() : string{ nullptr }, len{ 81 }
{
	string = new char[len];
	string_object++;
};

// �����������, ����������� ��������� ������ ������������� �������
// ��������� ���������� ��������, �� ������� ����� �������� ������ 
MyString::MyString(int string_len)
{
	len = string_len + 1;
	string = new char[len];
	string_object++;
}

// �����������, ������� ������ ������ � �������������� � �������
// ���������� � ���� ��������� ����� ������������
MyString::MyString(const char* parametr_string)
{
	len = strlen(parametr_string + 1);
	string = new char[len];
	strcpy(string, parametr_string);
	string_object++;
}

// �����������, ������� ������ ������ � �������������� � �������
// ���������� �� ������������ (� ����������)
MyString::MyString(char* user_string)
{
	len = strlen(user_string) + 1;
	string = new char[len];
	strcpy(string, user_string);
	string_object++;
}

// ����������� �����������
MyString::MyString(const MyString& object)
{
	len = object.len + 1;
	string = new char[len];
	strcpy(string, object.string);
}

// ����� ��� ����� ������ � ����������
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

// ������� ��� ������������ ����� (���������� ��������� +)
MyString MyString::operator+ (const MyString& str)
{
	MyString s;					   // �������� ���������� �������
	s.len = len + str.len + 1;     // ���������� ����� ����� ������
	s.string = new char[s.len];    // ��������� ������ ��� ����� ������
	strcpy(s.string, string);      // ������������� ������ ����� ������ 
	strcat(s.string, str.string);  // ������������� ������ ����� ������
	return s;
}