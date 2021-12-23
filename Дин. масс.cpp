#include "array.h"

using namespace masiwe;

int main()
{
    int e = 2; // выбор пользователя
    string name = "myfile.txt"; //файл для чтения
    string name_txt= "my_file.txt"; //файл для записи

    system("chcp 1251"); // русский язык в консоли

    cout << "Изменения для ветки 'work'" << endl;
    // выбор пользователем того, как создавать массив
    cout << "Введите 1, если хотите прочесть массив из файла";
    cout << endl;
    cout << "Введите 2, если хотите заполнить массив случайными числами\n";
    cin >> e;

    // int* mtx = new int[0]; // так надо, иначе компилятор жалуется
    int* mtx = NULL; // указатель в никуда, как бы заглушка

    if (e == 1) // массив из файла
    {
        file_mass(mtx, name, name_txt);
    }  
    else // массив случайных чисел
    {
        rand_mass(mtx,name_txt);
    }

    return 0;
}