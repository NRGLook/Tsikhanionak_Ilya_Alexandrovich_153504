// LR-3-6 Выаолнил:Тиханёнок Илья
/*Задача 6. Необходимо приближенно найти корень уравнения f(x) = 0 для функции из своего варианта.
Корень нужно найти по следующему алгоритму: перебираем значения от начала до конца интервала с некоторым шагом и ищем 
значение функции, минимальное по модулю. Аргумент, при котором оно достигается, считаем корнем уравнения. 
Программа должна запросить у пользователя, на сколько частей разделить область поиска корня, вычислить шаг, 
с которым нужно проходить значения, пройти в цикле нужные значения, найти корень и вывести его. */

#include <iostream>
#include <cmath>
#include <cstdlib>//printf-scanf

using namespace std;

long double inputInt()
{
    setlocale(LC_ALL, "Rus");
    long double p;

    cout << "Программа позволяет найти приближенный корень заданного уравнения.\nВведем число,на которое хотим разделить область поиска корня:";
    cin >> p;

    while (cin.peek() == ' ')
        cin.ignore(1, ' ');
    while (cin.fail() || cin.peek() != '\n' || p <= 0 || p != (long double)p || p!=round(p)) {
        //cin.peek - не пропускает пробелы
        cin.clear();//очищает
        cin.ignore(10000, '\n');
        cout << "Некорректный ввод.Попробуйте снова.";
        cout << "\nВведем число,на которое хотим разделить область поиска корня:";
        cin >> p;
        while (cin.peek() == ' ')
            cin.ignore(1, ' ');
    }
    return p;
}

int main()
{
    long double t, min, m=1, x;
    long double p = inputInt();
    setlocale(LC_ALL, "Rus");

    double d = 1 / p;
    for (x = -1; x < 1; x = x + d)
    {
        t = fabs(sin(x) + tan(x) - (1 / (1 + x * x)));

        //сравнивую значения для вывода минимального
        if (t <= m)
        {
            m = t;//присваиваем полученное значение другой переменной
            min = x;
        }
        else
        {
            continue;
        }
    }
    cout << min << "\n";


    return 0;
}

