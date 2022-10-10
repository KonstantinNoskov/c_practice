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



void isPrim(int num)
{
    int i = 2;
    bool isSimple = true;

    while (i <= sqrt(num))
    {   
        
        if (num % i == 0) {
            isSimple = false;
            break;    
        }
        cout << i << endl;
        i++;
    } 
   
    (isSimple) ? cout << num << " - это простое число." : cout << num << " - это сложное число.";
    cout << endl;  
}

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num = 18;

    cout << "Prim: " << Prim(num) << endl;
    cout << "isPrim: " << endl;
    isPrim(num);
    
 
}


