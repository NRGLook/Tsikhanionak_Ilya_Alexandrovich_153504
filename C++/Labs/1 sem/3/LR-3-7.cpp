// LR-3-7 Выполнил:Тиханёнок Илья
/*Задача 7. Найти двухзначное число, обладающее тем свойством, что куб
суммы его цифр равен квадрату самого числа. */

#include <iostream>

using namespace std;

int main()
{   
	int result, a, b;
	setlocale(LC_ALL, "Rus");

	cout << "Программа находит число,такое,что куб суммы его цифр равен квадрату самого числа.";

	for (int i = 10; i < 100; i++)
	{
		a = (int)i / 10;//первый знак двухзначного числа
		b = (int)i % 10;//второй знак двухзначного числа

		if (pow(a + b, 3) == pow(i, 2))//проверка на равенство
		{
			result = i; i = 100;
			cout << "\nЧисло,удовлетворяющее условию равно:" << result;
		}
	}
	return 0;
}

