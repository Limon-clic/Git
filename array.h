#pragma once
#include <iostream> // ƒл€ чтени€ или записи в стандартные потоки ввода-вывода
#include <iomanip>  // дл€ setw() (красивый вывод)
#include <time.h>   // дл€ rand()
#include <fstream>  // дл€ файла
#include <string>	// дл€ stoi() (перевод строки в число

using namespace std;
namespace masiwe
{
	void out(const int* mtx, const int& n, const string& name_txt);			// вывод всевозможных значений
	void output_txt(const int* mtx, string name_txt, const int& n);			// вывод массива в файл
	void output(const int* mtx, int n);										// вывод массива в консоль

	long arr_mult(int* mtx, const int& n);									// задача 136 г
	void filling(int* mtx, const int& n, const int& min, const int& max);	// заполнение массива случайными числами
	int Search_length(const string& name);									// поиск колличества эллемертов в файле
	void Read_File(int* mtx, const string& name, const int& n);				// чтение массива из файла

	void file_mass(int* mtx, const string& name, const string& name_txt);	// создание массива при помощи файла
	void rand_mass(int* mtx, const string& name_txt);						// создание массива при помощи случайных чисел
};