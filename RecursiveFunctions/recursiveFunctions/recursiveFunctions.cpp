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


struct mas {
    int key;
    string fio;

};

struct employee {
    
    string fio;
    int year;

    void print() {
        cout << setw(10) << fio << setw(10) << year << endl;
    }
};


void writeDataIn() {

    ifstream input("input.txt");
    ofstream output("output.txt");

    mas dataArray[20];

    int n = 0;

    if (!input) {

        cout << "Ошибка!" << endl;
    }

    else {

        while (input.peek() != EOF) {

            input >> dataArray[n].fio;
            input >> dataArray[n].key;
            n++;

            employee.print();
        }
    }

}


void sort (mas* a, int n) {

    mas temp;

    

    int i, j;

   



    for (i = 0; i < n - 1; i++) {

        for (j = n - 1; j > i; j--) {
            
            if (a[j].key < a[j - 1].key) {
                
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            
            }
        }
    }
}



int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    timer st;

    
   

       
}