// LR-2-14 Выполнил:Тиханёнок Илья
/*Задача 14. Даны действительные числа a, b, c, x, y. Выяснить, пройдёт ли 
кирпич с ребрами a, b, c в прямоугольное отверстие со стороны x и y. 
просовывать кирпич в отверстие разрешается только так, чтобы каждое из его 
было параллельно или перпендикулярно каждый из сторон отверстия.*/


#include <iostream>

using namespace std;

int main()
{
    int a, b, c, x, y;
    setlocale(LC_ALL, "Rus");

    cout << "Программа помогает определить : пройдёт ли кирпич ( c заданнами пользователем параметрами) в прямоугольное отверстие.\nВведите параметры кирпича(a-высота,b-длина основания,с-ширина основания).\nВведите a:";
    cin >> a;
    cout << "\n" << "Введите b:";
    cin >> b;
    cout << "\n" << "Введите c:";
    cin >> c;
    cout << "\nА теперь введём 'параметры' прямоугольного отверстия в которое нам нужно просунуть кирпич.\nВведите x(ширина прямоугольника):";
    cin >> x;
    cout << "\nВведите y(длина прямоугольника):";
    cin >> y;

    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
        cout << "'Параметр' не может быть отрицательным либо равным нулю.Попробуйте еще раз,но только с положительным числом.";
    }
    else if(x <= a && y <= c) {
        cout << "Кирпич проходит (возможно боком) в наше отверстие.";
    }
    else if(x <= a && y <= b) {
        cout << "Кирпич проходит в наше отверстие.";
    }
    else if (x>a||y>b||y>c) {
        cout << "Наш кирпич не прошел в нужное нам отверстие.\nПопробуйте подобрать другое отверстие для нашего кирпича.";
    }

    return 0;

}
    

