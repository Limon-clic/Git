#include "array.h"

namespace masiwe
{
    void output_txt(const int* mtx, string name_txt, const int& n) // вывод массива в файл
    {
        string s;   // читаем 
        ofstream f; // файл

        f.open(name_txt);   // ifstream::app - дописать в конец
        if (f.is_open())    // если с открытием файла не возникло проблем 
        {
            for (int i = 0; i < n; i++) // от 0 и до размера массива -1
            {
                f << " ";       // выводим пробел для разделения эллементов
                f << mtx[i];    // выводим эллемент в файл
            }
            f.close(); // закрывваем файл  
        }
        else // если с открытием файла возникли проблемы
            cout << "Ошибка открытия файла\n";
    }

    long arr_mult(const int* mtx, const int& n) // задача 136 г
    {
        long p = 1; // для умножения
        for (int i = 0; i < n; i++) // от 0 до размера массива -1
        {
            p = fabs(p * mtx[i]);   // по задаче
        }
        return p; // возвращаем значение
    }

    void filling(int* mtx, const int& n, const int& min, const int& max) // заполнение массива случайными числами
    {
        srand(time(NULL));  // для rand()
        for (int i = 0; i < n; i++) // от 0 до введённого размера массива-1
        {
            static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
            // Равномерно распределяем рандомное число в нашем диапазоне
            mtx[i] = static_cast<int>(rand() * fraction * (max - min + 1) + min);
        }
    }

    void output(const int* mtx, int n) // вывод массива в консоль
    {
        for (int i = 0; i < n; i++)
        {
            cout << "|" << mtx[i] << "| ";
        }
        cout << endl;
    }

    int Search_length(const string& name) // поиск колличества эллемертов в файле
    {
        int k = 0;
        string s;   // читаем 
        ifstream f; // файл

        f.open(name); // открываем файл
        if (f.is_open()) // если с открытием файла не возникло проблем 
        {
            while (!f.eof())    // пока не конец файла
            {
                f >> s; // смещаемся к концу файла
                k++;
            }
            f.close(); // закрывваем файл
            return k;
        }
        else // если с открытием файла возникли проблемы
        {
            throw runtime_error("Ошибка открытия при поиске колличества эллементов");
        }
    }

    void Read_File(int* mtx, const string& name, const int& n) // чтение массива из файла
    {
        string s;   // читаем 
        ifstream f; // файл

        f.open(name);       //открываем файл
        if (f.is_open())    // если с открытием файла не возникло проблем 
        {
            for (int i = 0; i < n; i++)
            {
                f >> s; // читаем строку
                mtx[i] = stoi(s);
            }
        }
        else    // если с открытием файла возникли проблемы
        {
            throw runtime_error("Ошибка открытия при чтении массива из файла");
        }
        f.close();  // закрывваем файл  
    }

    void out(const int* mtx, const int& n, const string& name_txt) // вывод всевозможных значений
    {
        output(mtx, n);                 // вывод массива в консоль
        cout << "Ответ: " << arr_mult(mtx, n);
        output_txt(mtx, name_txt, n);   //вывод массива в файл
    }

    void file_mass(int* mtx, const string& name, const string& name_txt)
    {
        int n = 0;
        long p = 0;
        try                             // обрабатываем ошибку открытия 
        {
            n = Search_length(name);    // поиск колличества эллемертов в файле
        }
        catch (runtime_error e)         // ловим ошибку
        {
            cout << endl << "Runtime error: " << e.what() << endl;
            exit(0);
        }

        mtx = new int[n]; // создание массива длинной n

        try                       // обрабатываем ошибку открытия 
        {
            Read_File(mtx, name, n); //заполняем массив элементами файла
        }
        catch (runtime_error e)   // ловим ошибку
        {
            cout << endl << "Runtime error: " << e.what() << endl;
            exit(0);
        }

        out(mtx, n, name_txt); // вывод всевозможных значений
        delete[] mtx; // очистка памяти массива
    }

    void rand_mass(int* mtx, const string& name_txt)
    {
        int n; // размер массива
        cout << "Размер массива= ";
        cin >> n;
        mtx = new int[n]; // создание массива длинной n
        int min = -15;
        int max = 22;
        filling(mtx, n, min, max); // заполнение массива случайными числами

        out(mtx, n, name_txt); // вывод всевозможных значений
        delete[] mtx; // очистка памяти массива
    }
};