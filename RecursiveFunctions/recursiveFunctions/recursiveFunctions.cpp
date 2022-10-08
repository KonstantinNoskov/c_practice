#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;


bool Prim(int j)
{
    int k = 2; 

    while (k * k <= j && j % k != 0)
    {
        k = NextPrim(k);
    }

    return (j % k == 0) ? false : true;
}


bool isPrim(int j)
{
    int k = 2;

    return (j % k == 0) ? false : true;
}

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << isPrim(21) << endl;
}


