#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;


//void mirrorString()
//{  
//    ifstream inFile("f.txt");
//    ofstream outFile("g.txt");
//
//    string s; 
//
//    while (!inFile.eof())
//    {
//        getline(inFile, s);
//        
//        for (unsigned int i = 0; i < s.length() / 2; i++)
//        {
//            char a = s[i];
//            s[i] = s[s.length() - 1 - i];
//            s[s.length() - 1 - i] = a;
//        }
//        outFile << s << endl;
//        cout << s << endl;
//    }
//    
//    inFile.close();
//    outFile.close();
//}


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

// Выводим результаты функций
int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "_______________________mirrorString________________________\n" << endl;
    //mirrorString();
    cout << endl;

    //func2();
    //cPlus_func();

    cout << "_______________________func3________________________\n" << endl;
    func3();
    cout << endl;
}