#pragma once
#include <iostream> // ��� ������ ��� ������ � ����������� ������ �����-������
#include <iomanip>  // ��� setw() (�������� �����)
#include <time.h>   // ��� rand()
#include <fstream>  // ��� �����
#include <string>	// ��� stoi() (������� ������ � �����

using namespace std;
namespace masiwe
{
	void out(const int* mtx, const int& n, const string& name_txt);			// ����� ������������ ��������
	void output_txt(const int* mtx, string name_txt, const int& n);			// ����� ������� � ����
	void output(const int* mtx, int n);										// ����� ������� � �������

	long arr_mult(int* mtx, const int& n);									// ������ 136 �
	void filling(int* mtx, const int& n, const int& min, const int& max);	// ���������� ������� ���������� �������
	int Search_length(const string& name);									// ����� ����������� ���������� � �����
	void Read_File(int* mtx, const string& name, const int& n);				// ������ ������� �� �����

	void file_mass(int* mtx, const string& name, const string& name_txt);	// �������� ������� ��� ������ �����
	void rand_mass(int* mtx, const string& name_txt);						// �������� ������� ��� ������ ��������� �����
};