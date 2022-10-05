#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

/*  Задача:

    Сложить все цифры заданного числа. Если полученная сумма не является однозначным числом,
    то цифры числа снова складываются и так до тех пор, 
    пока не будет получено однозначное число.
*/


unsigned long F(unsigned long num) 
{   
    unsigned long
        sum = 0; // Сумма всех цифр числа

    while (num > 0) // Повторяем итерации пока не сложим все цифры
    {   
        sum += num % 10; // Берем самую правую цифру и плюсуем её к сумме
       
        cout << "Сумма итерации: " << sum << endl;
        
        num /= 10; // Отбрасываем число, которое только что плюсовали
    }

    while (sum > 9) // Получившийся выше результат суммы снова плюсуем той же функцией пока результат - не однозначное число.
    {
        return F(sum);
    } 
    return sum;
}


int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << F(288) << endl;
   
}


