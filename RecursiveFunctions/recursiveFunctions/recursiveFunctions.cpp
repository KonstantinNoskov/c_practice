#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
#include <chrono>
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
string toUpperCase(string text)
{
    for (int i = 0; i < text.length(); i++) {

        if (text[i] == 'ё')
        {
            text[i] -= 16;
        }
        else if (text[i] >= 'а' && text[i] <= 'я')
        {
            text[i] -= 32;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] -= 32;
        }
    }

    return text;
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
string toLowerCase(string text)
{   
    for (int i = 0; i < text.length(); i++) {
        
        if (text[i] == 'Ё')
        {
            text[i] += 16;
        }
        else if (text[i] >= 'А' && text[i] <= 'Я')
        {
            text[i] += 32;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] += 32;
        }
    }
    return text;
}

class timer
{
    public:
        timer() {
            start = chrono::steady_clock::now();
        }
        ~timer() {
            end = chrono::steady_clock::now();
            chrono::duration<double> duration = end - start;
            cout << duration.count() << " сек" << endl;
        }

    private:
        std::chrono::time_point<std::chrono::steady_clock> start, end;
};


int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    timer st;

    int a = 4;
    int* b = &a;
    
    // Ветка до revert

    cout << a << "\t" << &a << "\t" << *b << endl;

}