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

	// ����������� �����������
	MyString(MyString&& obj);

	// ����� ��� ����� ������ � ����������
	void fill_string();

	// ������ ��� ������
	void set_str(char* str)
	{
		len = strlen(str);
		string = new char[len + 1];
		if (str)
		{
			strcpy(string, str);
		}
	}

	// ����������� ������ ��� �������� ������
	char* get_str() const
	{
		return string;
	}

	// ����� ������ ������ �� �����
	void print()
	{
		std::cout << "RES STRING: " << string << std::endl;
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

	// ���������� ��������� ������������ � ������������
	MyString& operator= (const MyString& str);

	// ���������� ��������� ������������ � ������������
	MyString& operator=(MyString&& str);

	// ���������� ��������� < (��������� �����)
	bool operator< (const MyString& str);

	// ����������� initializer_list
	MyString(const std::initializer_list<char>& list)
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

	// ����������� initializer_list (������ �������)
	//MyString(const std::initializer_list<char>& list)
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

	~MyString()  // ����������
	{
		delete[] string;
		string_object--;
	}
};

// ���������� ���������� ��������� + (int + string)
MyString operator+(int num, MyString cont_string);
