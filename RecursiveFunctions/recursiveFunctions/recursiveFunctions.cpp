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

// Структура содержит координаты точки в x,y,z плоскостях
struct point { 
    double x, y, z;
};// содержит координаты точки в x,y,z плоскостях

double dlina(point a, point b) { // вспомогательная функция высчитывает расстояние между точками а и б

    double
        result = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));

    //cout << result << "\n" << endl;
    return result;
}

 //Функция находит все точки которые находятся в радиусе шара
void PointsInRadius(double pointCenter, double radius, int num) {
    point
        circle,
        newPoints[10],
        radius3;

    int
        k = 0;

    double newPoint = pointCenter;

    circle.x = pointCenter;
    circle.y = pointCenter;
    circle.z = pointCenter;

    radius3.x = radius;
    radius3.y = radius;
    radius3.z = radius;



    for (int i = 0; i < num; i++) {
       
        newPoints[i].x = newPoint;
        newPoints[i].y = newPoint;
        newPoints[i].z = newPoint;
        
        newPoint += 1;
    }

    cout << "Расстояние текущей точки от центра окружности:" << endl;

    for (int i = 0; i < num; i++) {
        cout << "Точка №" << k + 1 << endl;
        if (dlina(circle, newPoints[i]) <= dlina(circle, radius3)) {
            k++; 
        }
    }

    cout << "Кол-во точек в радиусе " << radius << " составляет: " << k << endl;   
    cout << "Время исполнения функции: ";
}

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