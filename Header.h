#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyString
{
	char* string;			   // ������
	int len;				   // ����� ������
	static int string_object;  // ���-�� ��������-�����
public:
	// ����������� �� ���������, ����������� ������� ������ 
	// ������ 80 ��������
	MyString();

	// �����������, ����������� ��������� ������ ������������� �������
	// ��������� ���������� ��������, �� ������� ����� �������� ������ 
	MyString(int string_len);

	// �����������, ������� ������ ������ � �������������� � �������
	// ���������� � ���� ��������� ����� ������������
	MyString(const char* parametr_string);

	// �����������, ������� ������ ������ � �������������� � �������
	// ���������� �� ������������ (� ����������)
	MyString(char* user_string);

	// ����������� �����������
	MyString(const MyString& object);

	// ����� ��� ����� ������ � ����������
	void set_string();

	// ����� ������ ������ �� �����
	void print(int number)
	{
		std::cout << "RES STRING " << number << ": " << string << std::endl;
	}

	// ����������� �����, ���������� ���-�� ��������� ��������-�����
	static int get_string_object()
	{
		return string_object;
	}

	// ������� ��� ������������ ����� (���������� ��������� +)
	MyString operator+ (const MyString&);

	// ����� ����������� � ����� �������-������ ������ ������� 'x'
	MyString operator++(int);

	// ����� �������� ������ ������� �� ����� �������-������
	MyString operator--(int);

	// MyString+int (�������� � ����� ������� ����� ���-�� �������� 'x')
	MyString operator+(int number);

	// MyString-int (������� �� ����� ������� ����� ���-�� �������� 'x')
	MyString operator-(int number);

	// ���������� ��������� ������������, ����������� ���������� ������������
	MyString& operator= (const MyString& str);

	~MyString()  // ����������
	{
		delete[] string;
		string_object--;
	}
};
