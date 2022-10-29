#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;


char toUpperCase(char letter)
{   
    if (letter == 'ё')
    {
        letter -= 16;
    }
    else if (letter >= 'а' && letter <= 'я')
    {
        letter -= 32;
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        letter -= 32;
    }

    return letter;
}

char toLowerCase(char letter)
{
    if (letter == 'Ё')
    {
        letter += 16;
    }
    else if (letter >= 'А' && letter <= 'Я')
    {
        letter += 32;
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        letter += 32;
    }

    return letter;
}


/*void func2()
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

} */


// Задача 1.1 Поменять местами целые числа двух файлов.
        
void sumSpecString(int n)
{   

    string
        inOutMidPath = "inOutMiddle.txt",
        inOut1Path = "inOut1.txt",
        inOut2Path = "inOut2.txt",
        bin1Path = "bin1.dat",
        bin2Path = "bin2.dat";

    fstream 
        inOut1(inOut1Path),
        inOut2(inOut2Path),
        inOutMid(inOutMidPath),
        bin2(bin2Path);


    ifstream bin1(bin1Path, ios::binary);

    int
        i;

   /* for (i = 1; i <= n; i++)
    {
        bin1.write((char *)&i, sizeof(int));
    }*/

    bin1.read((char*)&i, sizeof(int));

   
    cout << i << endl;

    inOut1.close();
    inOut2.close();
    inOutMid.close();
    bin1.close();
    bin2.close();
}

// Выводим результаты функций
int main()
{   
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    
    sumSpecString(5);
    cout << endl;

}