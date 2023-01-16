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

	// ����������� �����-������
	const char* get_string() const
	{
		return string;
	}

	// ����� ������ ������ �� �����
	void print(int number)
	{
		std::cout << "RESULT " << number << ": " << string << std::endl;
	}

	// ����������� �����, ���������� ���-�� ��������� ��������-�����
	static int get_string_object()
	{
		return string_object;
	}

	// ������� ��� ������������ ����� (���������� ��������� +)
	MyString operator+ (const MyString&);

	~MyString()  // ����������
	{
		delete[] string;
	}
};