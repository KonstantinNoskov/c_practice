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


/*
    1.1 
    Задача:
    Разработать функцию, которая для заданного натурального числа N возвращает значение true, если число простое, и значение false, если число составное.
    
    С помощью данной функции:
    a) вывести на экран все простые числа на отрезке[а, Ь];
    b) найти количество всех простых чисел на отрезке[а, b];
    c) найти сумму всех составных чисел на отрезке[а, b];
    d) для заданного числа А вывести на экран предшествующее по отношению к нему простое число.
*/


int AllDegreeOf(int num); // Преждевременно объявляем функцию AllDegreeOf чтобы использовать её в функции AllPrimIn.

bool isPrim(int num) // Моя простая, вспомогательная функция проверки, является ли число простым или нет.
{
    int i = 2;
    bool isSimple = true;

    while (i <= sqrt(num))
    {   
        if (num % i == 0) {
            isSimple = false;
            break;    
        }
        i++;
    }    
    return isSimple;
}


void AllPrimIn(int a, int b) // Функция выводит все простые числа в диапазоне от a до b 
{   
    cout << "Исходный диапазон чисел: " << a << " - " << b << endl;
    cout << endl;
    cout << "Список простых чисел: " << endl;
   
    int 
        total = 0,
        nonPrimSum = 0;

    while (a <= b)
    {   
        
        if (isPrim(a)) {
            cout << "Число: " << a;
            cout << "\tКол-во делителей: "<< AllDegreeOf(a) << endl;
            total++;
            
        } 
        else {
            nonPrimSum += a;
        }
        
        a++;
    }

    cout << endl;
    cout << "Всего простых чисел: " << total << endl;
    cout << "Сумма всех составных чисел: " << nonPrimSum << endl;
}


int PrevPrim(int num)
{   
    cout << "Исходное число: " << num << endl;
    int p = num - 1;

    while (!isPrim(p))
    {
        --p;
    }

    return p;
}

/*  
    1.2 
    Задача:
    Разработать функцию, которая для заданного натурального числа N возвращает количество его делителей.
    
    С помощью данной функции :
    a) для каждого натурального числа на отрезке [а, b] вывести на экран количество делителей;
    b) вывести на экран только те натуральные числа отрезка [а, b], у которых количество делителей равно заданному числу;
    c) вывести на экран только те натуральные числа отрезка [а, b], у которых количество делителей максимально;
    d) для заданного числа А вывести на экран следующее по отношению к нему число, имеющее столько же делителей, сколько и число А.
*/     

int AllDegreeOf(int num) //Вспомогательная функция, которая возвращает кол-во делителей заданного числа.
{
    int
        degreeSum = 0,
        k = 1;
    
    while (k <= num)
    {
        if (num % k == 0) {
            degreeSum++;
        }
        
        k++;
    }
    return degreeSum;
}

void AllNaturalDegree(int a, int b) {

    while (a <= b) {
        cout << "Кол-во делителей числа '" << a << "' равно: " << AllDegreeOf(a) << endl;
        a++;
    }
}
// Перегруженная функция выводит только те нат.числа, кол-во делителей которых равно новому параметру SpecificDegree
void AllNaturalDegree(int a, int b, int SpecificDegree) { 

    while (a <= b) {
        if (SpecificDegree == AllDegreeOf(a)) {

            cout << "Кол-во делителей числа '" << a << "' равно: " << AllDegreeOf(a) << endl;
        }
        a++;
    }
}

void MaxNaturalDegree(int a, int b) {

    int
        p = a,
        maxDegree = 0;
    cout << "Максимальное кол-во делителей у чисел: " << endl;
    
    while (p <= b) {

        if (AllDegreeOf(p) > maxDegree) {
            maxDegree = AllDegreeOf(p);
        }
        p++;
    }

    while (a <= b) {
        if (AllDegreeOf(a) == maxDegree) {
            cout << a << endl;
        }
        a++;
    }
}


void EqualDegree(int a) {

    int k = a + 1;

    while (AllDegreeOf(k) != AllDegreeOf(a)) {

        k++;
    }

    cout << "Исходное число: " << a << endl;
    cout << "Следующее число с таким же кол-вом делителей это: " << k << endl;
}


int DegreeSumOf(int num) { // Вспомогательная функция считает сумму всех делителей заданного числа
    
    int
        sum = 0,
        k = 1;
       
    while (k <= num) 
    {

        if (num % k == 0) {
            sum += k;
        }
        k++;
    }

    return sum;
}

/*
    1.3
    Задача:
    Разработать функцию, которая для заданного натурального числа N возвращает сумму его делителей. 
    
    С помощью данной функции:
    a) для каждого натурального числа на отрезке [а, b] вывести на экран сумму его делителей;
    b) вывести на экран только те натуральные числа отрезка [а, b], у которых сумма делителей равна заданному числу;
    c) вывести на экран только те натуральные числа отрезка [а, b], у которых сумма делителей максимальна.
    d) для заданного числа А вывести на экран предшествующее по отношению к нему число, сумма делителей которого равна сумме делителей числа А.
*/


void DegreeSumIn(int a, int b)
{
    cout << "Сумма делителей числа: " << endl;
    while (a <= b) {

        int sum = DegreeSumOf(a);
        cout << "  " << a << " = " << sum << endl;
        a++;
    }

}

void DegreeSumIn(int a, int b, int num)
{
    cout << "Числа сумма делителей которых равны '" << num << "': " << endl;
    while (a <= b) {
        int sum = DegreeSumOf(a);

        if (sum == num) {
            cout << "  " << a << " = " << sum << endl;
        }
        
        a++;
    }
}

void MaxDegreeSumIn(int a, int b)
{   
    

    int maxSum = 0;

    while (a <= b) {
        int sum = DegreeSumOf(a);

        if (sum > maxSum) {
            maxSum = sum;
        }

        a++;
    }

    cout << "Макс сумма делителей равна " << maxSum <<endl;
}

void EqualDegreeSum(int num) { // Находим предшествующее число с такой же суммой делителей как и у заданного числа.

    int p = num - 1;

    while (p >= 1) {

        if (DegreeSumOf(p) == DegreeSumOf(num)) {

            cout << "Предшествующее числу '" << num << "' число с таким же кол-вом делителей это '" << p << "'" << endl;
            break;
        }

        p--;
    }
}

int NumDigitSum(int num) {
    
    int sum = 0;

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

/*
    1.5
    Задача:
    Разработать функцию, которая для заданных натуральных чисел N и М возвращает их наибольший общий делитель. 
    
    С помощью данной функции:
    a) сократить дробь вида а/Ъ;
    b) найти наименьшее общее кратное для двух натуральных чисел;
    c) вычислить значение выражения a/b + d/c; результат представить в виде обыкновенной дроби, выполнив сокращение;
    d) найти наибольший общий делитель для n натуральных чисел.

*/


int MaxCommonDegree(int num1, int num2) { // Вспомогательная функция находит наибольший обший делитель двух заданных чисел

    int
        k = 1,
        MaxDegree = 0;
        

    while (k <= num1) { // Находим наибольший делитель для первого числа на который можно поделить второе число.
        
        if (num1 % k == 0 && k > MaxDegree && num2 % k == 0) {
                  
            MaxDegree = k;
        }
 
        k++;
    }

    return MaxDegree;
}

int MinCommonDegree(int num1, int num2) { // Вспомогательная функция находит наибольший обший делитель двух заданных чисел

    int
        k = 2,
        MinDegree = 0;

    while (k < num1) { // Находим наибольший делитель для первого числа на который можно поделить второе число.

        if (num1 % k == 0 && num2 % k == 0) {

            MinDegree = k;
        }

        k++;
    }

    return MinDegree;
}


void DegreeAddition(int firstNum, int firstDenom, int secondNum, int secondDenom) {

    cout << "Исходные данные: " << firstNum << " / " << firstDenom << " + " << secondNum << " / " << secondDenom << endl;

    int 
        Num,
        Denom;

    // Сначала определяем являются ли знаменатели равными или нет и в зависимости от этого складываем дроби.

    if (firstDenom == secondDenom) { // Если дроби с равными знаменателями...

        Num = firstNum + secondNum;
        Denom = firstDenom;

        cout << "Дробь с одинаковыми знаменателям." << endl;
    } 
    else { // Если дроби с разными знаменателями...
        Num = firstNum * secondDenom + secondNum * firstDenom;
        Denom = firstDenom * secondDenom;

        cout << "Дроби с разными знаменталями." << endl;
        cout << "Дроби после превидения к единому знаменталю: " << Num << " / " << Denom << endl;
    }

    cout << "\nДробь после сокращения: " << Num / MaxCommonDegree(Num, Denom) << " / " << Denom / MaxCommonDegree(Num, Denom) << "\n" << endl;
    
    // Далее выводим дробь на экран в том или ином виде 

    if (Num % Denom == 0) // Если числитель и знаменатель равны значит результат сложения - целое число, его и выводим.
    {   
        cout << "Результатом сложения дробей является целое число: " << Num / Denom << endl;
    }

    else if (Num > Denom) // Если числитель больше значит результат - целое число с дробью
    {   
        cout << "Результатом сложения дробей является целое число с дробью: " <<
            Num / Denom << " целых " << (Num % Denom) / MaxCommonDegree(Num % Denom, Denom) << " / " << Denom / MaxCommonDegree(Num % Denom, Denom) << endl;
    }

    else // Если числитель меньше знаменателя значит выводим простую дробь
    {
        cout << "Результатом сложения является простая дробь: " <<
            Num / MaxCommonDegree(Num, Denom) << " / " << Denom / MaxCommonDegree(Num, Denom) << endl;
    }
}


int RecursiveFunc_1(int n)
{
    
    if (n < 0) 
    {
       return 0;
    }
    else 
    {   
        for (int i = 0; i < n; i++) 
        {   
            cout << "*";
        }
        cout << endl;

       return n - RecursiveFunc_1(n - 1);
    }
}





// Выводим результаты функций
int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int 
        num = 25,
        num2 = 15;
    
    cout << "________________________AllPrimIn________________________ " << endl;
    AllPrimIn(5, 23);
    cout << endl;

    cout << "________________________PrevPrim________________________ " << endl;
    cout << "Предшествующее простое число: " << PrevPrim(17) << endl;
    cout << endl;

    cout << "________________________AllDegreeOf________________________ " << endl;
    cout << "Кол-во делителей: " << AllDegreeOf(11) << endl;
    cout << endl;

    cout << "________________________AllNaturalDegree + Spec.Degree________________________ " << endl;
    AllNaturalDegree(2, 9, num);
    cout << endl;

    cout << "________________________MaxNaturalDegree________________________ " << endl;
    MaxNaturalDegree(2, 9);
    cout << endl;

    cout << "________________________EqualDegree________________________ " << endl;
    EqualDegree(num);
    cout << endl;

    cout << "________________________DegreeSumIn________________________ " << endl;
    DegreeSumIn(2, num);
    cout << endl;

    cout << "________________________DegreeSumIn + Spec.Degree________________________ " << endl;
    DegreeSumIn(2, 21, num);
    cout << endl;

    cout << "________________________MaxDegreeSumIn________________________ " << endl;
    MaxDegreeSumIn(2, num);
    cout << endl;

    cout << "________________________EqualDegreeSum________________________ " << endl;
    EqualDegreeSum(num);
    cout << endl;

    cout << "________________________NumDigitSum________________________ " << endl;
    cout << NumDigitSum(123);
    cout << endl;

    cout << "________________________MaxCommonDegree________________________ " << endl;
    cout << MaxCommonDegree(num, num2) << endl;
    cout << endl;

    cout << "________________________DegreeAddition________________________ " << endl;
    DegreeAddition(5, 15, 12, 24);
    cout << endl;
    
    cout << "________________________RecursiveFunc_1________________________ " << endl;
    cout << RecursiveFunc_1(7) << endl;  
}


