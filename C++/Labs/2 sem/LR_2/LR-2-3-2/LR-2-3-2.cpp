﻿// LR-2-3-2 Выполнил:Тиханёнок Илья
/*Задача 3.Написать программу нахождения максимального из двух
вещественных чисел X и Y с использованием тернарной операции. Написать
два варианта программы. С использованием переменной логического типа для
определения условия и без неё.*/

#include <iostream>

using namespace std;

int main()
{
    float x, y;
    setlocale(LC_ALL, "Rus");

    cout << "Введите x:";
    cin >> x;
    cout << "\n" << "Введите y:";
    cin >> y;

    bool max = x > y;
    max ? (cout << "\n х больше у") : x == y ? (cout << "y равен x ") : (cout << "y больше x ");

    return 0;

}
