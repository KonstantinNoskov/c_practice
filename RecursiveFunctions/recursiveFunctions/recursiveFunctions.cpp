#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;



void func2()
{

    ifstream in("f.txt");
    ofstream out("g.txt");

    int i;

    while (in >> i)
    {    

        if ((i >= 0) && (i % 3 == 0))
        {   
            out << setw(5) << i;
        }

    }
    in.close();
    out.close();
}

void cPlus_func()
{
    char symbol;
    ifstream in("f.txt");
    ofstream out("g.txt");

    while (in.peek() != EOF)
    {
        in.get(symbol);

        if (symbol == 'c' || symbol == 'C')
        {
            out << symbol << "++";
        }

        else
        {
            out << symbol;
        }
    }

    in.close();
    out.close();
}


void func3()
{
    ofstream out("f.dat", ios::binary);
    
    double 
        a = 0,
        b = 10,
        h = 0.5,
        i;
    
    for (i = a; i <= b; i += h)
    {
        out.write((char *)&i, sizeof(i));
    }

    out.close();


    ifstream in("f.dat", ios::binary);

    in.seekg(sizeof(double));

    while (in.peek() != EOF)
    {

        in.read((char*)&i, sizeof(double));

        cout << i << ' ';
       
        in.seekg(8, ios::cur);
    }

    in.close();

}


/*  Задача 1.1
        */  


void sumSpecString(char letter)
{
    ifstream in("in.txt");
    string str;

    char
        upperCase,
        lowerCase;

    int
        sum = 0;

    while (in.peek() != EOF)
    {   
        getline(in, str);

        if (str[0] == 'h' || str[0] == 'H')
        {
            sum++;
        }
    }

    in.close();
    cout << "Кол-во строк начинающихся с буквы '" << letter << "' = " << sum << endl;
}

// Выводим результаты функций
int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    cout << "_________________________sumSpecString_________________________" << endl;
    sumSpecString('h');
    cout << endl;

}