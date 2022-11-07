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

// Функция находит все точки которые находятся в радиусе шара
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

ifstream
    input("input.txt");
ofstream
    output("output.txt");

struct bibl {
    int
        id,
        year;
    char
        family[20],
        nazv[50];

    void show();
    void print();
};
void bibl::show() {
    cout << setw(8) << id << setw(10) << family << setw(8) << nazv << setw(8) << year << endl;
}
void bibl::print() {
    output << setw(8) << id << setw(10) << family << setw(8) << nazv << setw(8) << year << endl;
}
void deleteBook() {
    bibl 
        books[10];

    int
        num, i, j,
        n = 0;

    if (!input) {
        cout << "Ошибка при открытии файла input.txt\n";
    }
    else {
        while (input.peek() != EOF) {
            input >> books[n].id;
            input >> books[n].family;
            input >> books[n].nazv;
            input >> books[n].year;

            books[n].show();

            n++;
        }
    }
    
    cout << "\nВведите ID книги, которую\n";
    cout << "нужно убрать из списка:";

    cin >> num;

    if (!output) {
        cout << "Ошибка при открытии файла input.txt\n";
    }
    else {
        j = 0;

        for (i = 0; i < n && !j; i++) {

            if (books[i].id == num) {

                for (j = i; j < n - 1; j++) {
books[j] = books[j + 1];
                }

                n--;
            }
        }

        for (i = 0; i < n; i++) {
            books[i].print();
        }
    }

    input.close();
    output.close();
}


void DistancePoint(int num, int centerPos) {
    point
        center,
        pointArray[11];

    int
        step = 1,
        n = num,
        minPoint = 0;

    double
        FirstMaxDistance = 0,
        SecondMaxDistance = 0;

    center.x = centerPos;
    center.y = centerPos;
    center.z = centerPos;

    cout << "Расстояние от центра до точки: " << endl;

    for (int i = 0; i < n; i++) {

        cin >> step;

        pointArray[i].x = step;
        pointArray[i].y = step;
        pointArray[i].z = step;

        cout << i + 1 << ".\t" << dlina(center, pointArray[i]) << endl;

        if (dlina(center, pointArray[i]) > FirstMaxDistance) {

            FirstMaxDistance = dlina(center, pointArray[i]);
        }
    }

    cout << "\nСамая удаленная точка: " << FirstMaxDistance << endl;

    for (int i = 0; i < n; i++) {

        if (dlina(center, pointArray[i]) > SecondMaxDistance && dlina(center, pointArray[i]) < FirstMaxDistance) {

            SecondMaxDistance = dlina(center, pointArray[i]);
        }
    }

    cout << "Вторая по удаленности точка: " << SecondMaxDistance << endl;

}



void MaxDistanceBetween(int num) {
    point
        pointArray[5],
        center;

    center.x = 0;
    center.y = 0;
    center.z = 0;

    int
        n = num,
        step;

    double maxDistance = 0;

    cout << "Введите координаты точек: " << endl;

    for (int i = 0; i < n; i++) {


        cin >> step;
        pointArray[i].x = step;
        pointArray[i].y = step;
        pointArray[i].z = step;

        cout << "Дистанция от центра: " << dlina(center, pointArray[i]) << endl;

    }

    for (int i = 0; i < n; i++) {
      
        for (int j = i+1; j < n; j++) {
            
            if (dlina(pointArray[i], pointArray[j]) > maxDistance){

                maxDistance = dlina(pointArray[i], pointArray[j]);
            }
        }
    }

    cout << "Расстояние между наиболее удаленными друг от друга точками составляет: " << maxDistance << endl;
}

void maxPointsInRadius(int radius, int pointsNum) {

    point 
        radiusPoint,
        pointsArray[10];

    int
        num = pointsNum, //Кол-во заданных точек 
        maxPoint = 0,
        maxPointIncount = 0,
        pointInCount; // Считаем кол-во точек в радиусе проверяемой точки 

    double
        step = 0,
        RadiusDistance; //Тут храним расстояние между исходной точкой и точкой на радиусе
   
    //Присваиваем всем точкам массива координаты с повышением на 1
    cout << "Введите координаты точек: " << endl;
    for (int i = 0; i < num; i++) {

        cin >> step;

        pointsArray[i].x = step;
        pointsArray[i].y = step;
        pointsArray[i].z = step;
    }

    cout << endl;

    for (int i = 0; i < num; i++) {

        radiusPoint.x = pointsArray[i].x + radius;
        radiusPoint.y = pointsArray[i].y + radius;
        radiusPoint.z = pointsArray[i].z + radius;

        RadiusDistance = dlina(pointsArray[i], radiusPoint); 
        
        cout << "Координаты точки №" << i+1 << ": " << pointsArray[i].x << endl;
        cout << "Координаты точки радиуса: " << radiusPoint.x << endl;
        cout << "Расстояние от центра до радиуса исходной точки: " << RadiusDistance << endl;

        cout << endl;

        //Сравниваем радиус точки с расстояением от между другими точками
        for (int j = 0, pointInCount = 0; j < num; j++) {

            cout << "Расстояние от точки №" << i+1 << " до точки №" << j+1 << ": " << dlina(pointsArray[i], pointsArray[j]) << " - ";
            
            //Если расстояение до другой точки меньше радиуса значит точка лежит в нем и мы инкременируем счетчик точек.
            if (dlina(pointsArray[i], pointsArray[j]) <= RadiusDistance && i != j) {
                pointInCount++;
                cout << "Добавил счетчик! - " << pointInCount << endl; 
            }
            
            else if(dlina(pointsArray[i], pointsArray[j]) == 0) {
                cout << "Одна и та же точка" << endl;
                continue;
            } 

            else {
                cout << "Точка вне радиуса!";
            }
            
            if (pointInCount > maxPointIncount) {
                maxPointIncount = pointInCount;
                maxPoint = i+1;

                cout << "\nКол-во точек в радиусе: " << pointInCount << endl;
                cout << "Обновил макс. кол-во точек: " << maxPointIncount << endl;
            }

            cout << endl;
        }

        cout << "След. точка!\n______________________________________________________________\n" << endl;
        //Если кол-во точек в радиусе заданной точки больше максимального, присваиваем значение и записываем номер этой точки.
        
    }

    cout << "Номер точки с наибольшим кол-вом точек в своем радиусе это " << maxPoint << endl;
    cout << "Максимальное кол-во точек в заданном радиусе " << maxPointIncount << endl;
}


// Выводим результаты функций
int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    timer st;
    
    cout << "________________________PointsInRadius________________________" << endl;
    //PointsInRadius(0, 1.5, 3);
    cout << "\n" << endl;

    cout << "________________________deleteBook________________________" << endl;
    //deleteBook();
    cout << endl;

    cout << "________________________DistancePoint________________________" << endl;
    //DistancePoint(5, 6);
    cout << endl;

    cout << "________________________MaxDistanceBetween________________________" << endl;
    //MaxDistanceBetween(5);
    cout << endl;

    cout << "________________________MaxDistanceBetween________________________" << endl;
    maxPointsInRadius(2, 5);
    cout << endl;
    
}