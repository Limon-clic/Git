#include "array.h"

namespace masiwe
{
    void output_txt(const int* mtx, string name_txt, const int& n) // ����� ������� � ����
    {
        string s;   // ������ 
        ofstream f; // ����

        f.open(name_txt);   // ifstream::app - �������� � �����
        if (f.is_open())    // ���� � ��������� ����� �� �������� ������� 
        {
            for (int i = 0; i < n; i++) // �� 0 � �� ������� ������� -1
            {
                f << " ";       // ������� ������ ��� ���������� ����������
                f << mtx[i];    // ������� �������� � ����
            }
            f.close(); // ���������� ����  
        }
        else // ���� � ��������� ����� �������� ��������
            cout << "������ �������� �����\n";
    }

    long arr_mult(const int* mtx, const int& n) // ������ 136 �
    {
        long p = 1; // ��� ���������
        for (int i = 0; i < n; i++) // �� 0 �� ������� ������� -1
        {
            p = fabs(p * mtx[i]);   // �� ������
        }
        return p; // ���������� ��������
    }

    void filling(int* mtx, const int& n, const int& min, const int& max) // ���������� ������� ���������� �������
    {
        srand(time(NULL));  // ��� rand()
        for (int i = 0; i < n; i++) // �� 0 �� ��������� ������� �������-1
        {
            static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
            // ���������� ������������ ��������� ����� � ����� ���������
            mtx[i] = static_cast<int>(rand() * fraction * (max - min + 1) + min);
        }
    }

    void output(const int* mtx, int n) // ����� ������� � �������
    {
        for (int i = 0; i < n; i++)
        {
            cout << "|" << mtx[i] << "| ";
        }
        cout << endl;
    }

    int Search_length(const string& name) // ����� ����������� ���������� � �����
    {
        int k = 0;
        string s;   // ������ 
        ifstream f; // ����

        f.open(name); // ��������� ����
        if (f.is_open()) // ���� � ��������� ����� �� �������� ������� 
        {
            while (!f.eof())    // ���� �� ����� �����
            {
                f >> s; // ��������� � ����� �����
                k++;
            }
            f.close(); // ���������� ����
            return k;
        }
        else // ���� � ��������� ����� �������� ��������
        {
            throw runtime_error("������ �������� ��� ������ ����������� ����������");
        }
    }

    void Read_File(int* mtx, const string& name, const int& n) // ������ ������� �� �����
    {
        string s;   // ������ 
        ifstream f; // ����

        f.open(name);       //��������� ����
        if (f.is_open())    // ���� � ��������� ����� �� �������� ������� 
        {
            for (int i = 0; i < n; i++)
            {
                f >> s; // ������ ������
                mtx[i] = stoi(s);
            }
        }
        else    // ���� � ��������� ����� �������� ��������
        {
            throw runtime_error("������ �������� ��� ������ ������� �� �����");
        }
        f.close();  // ���������� ����  
    }

    void out(const int* mtx, const int& n, const string& name_txt) // ����� ������������ ��������
    {
        output(mtx, n);                 // ����� ������� � �������
        cout << "�����: " << arr_mult(mtx, n);
        output_txt(mtx, name_txt, n);   //����� ������� � ����
    }

    void file_mass(int* mtx, const string& name, const string& name_txt)
    {
        int n = 0;
        long p = 0;
        try                             // ������������ ������ �������� 
        {
            n = Search_length(name);    // ����� ����������� ���������� � �����
        }
        catch (runtime_error e)         // ����� ������
        {
            cout << endl << "Runtime error: " << e.what() << endl;
            exit(0);
        }

        mtx = new int[n]; // �������� ������� ������� n

        try                       // ������������ ������ �������� 
        {
            Read_File(mtx, name, n); //��������� ������ ���������� �����
        }
        catch (runtime_error e)   // ����� ������
        {
            cout << endl << "Runtime error: " << e.what() << endl;
            exit(0);
        }

        out(mtx, n, name_txt); // ����� ������������ ��������
        delete[] mtx; // ������� ������ �������
    }

    void rand_mass(int* mtx, const string& name_txt)
    {
        int n; // ������ �������
        cout << "������ �������= ";
        cin >> n;
        mtx = new int[n]; // �������� ������� ������� n
        int min = -15;
        int max = 22;
        filling(mtx, n, min, max); // ���������� ������� ���������� �������

        out(mtx, n, name_txt); // ����� ������������ ��������
        delete[] mtx; // ������� ������ �������
    }
};