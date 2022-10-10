#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;


int NextPrim(int n);

bool Prim(int j)
{
    int k = 2; 

    while (k * k <= j && j % k != 0)
    {
        k = NextPrim(k);
    }

    return (j % k == 0) ? false : true;
}

int NextPrim(int n)
{
    int p = n + 1;

    while (!Prim(p))
    {
        ++p;
    }

    return p;
}



bool isPrim(int n)
{
    int i = 2;
    bool isSimple = true;

    while (i * i <= n)
    {   
       
        if (n % i == 0) {
            
            isSimple = false;
        }
        /*out << "i: " << i << " квадрат i: " << i * i << endl;
        simple = (n % i == 0) ? false : true;*/
        i++;
    }
    
    return isSimple;
}

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int n = 2;
    cout << "Prim: " << NextPrim(n) << endl;
    cout << "isPrim: " << isPrim(n) << endl;
    
}


