﻿//Лабораторная 1,задание 8.Выполнена:Тиханёнок Илья Александрович
/*На вход даны а1 и a100, первый и сотый член арифметической 
прогрессии. Необходимо вычислить:
1. Разность арифметической прогрессии;
2. Сумму первых n+10 членов арифметической прогрессии, где n - ваш 
номер в журнале.*/

#include <iostream>
#include<cmath>

using namespace std;

int main()
{
	double a1, a100, d, S;
	int n=18;
	setlocale(LC_ALL, "Rus");

	cout << "Дана арифметическая прогрессия.\nНайдем разность и сумму арифметической прогрессии ,зная первый и сотый члены последовательности соответственно.\nВведите первый член последовательности :";
	cin >> a1;

	cout <<"\nВведите сотый член последовательности : ";
	cin >> a100;

	d = (a100 - a1) /99;
	S = (2 * a1 + d*(n-1))*0.5*n;
	

	cout <<"Ответ:Разность арифметической прогресси : " << d<<".\nСумма первых восемнадцати членов последовательности : " << S;
	
	return 0;
}

