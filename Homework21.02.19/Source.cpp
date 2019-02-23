#include<iostream>
using namespace std;

double Sqrt(double a)
{
	return pow(a, 0.5);
}

double ThirdPower(double a)
{
	return pow(a, 3);
}

double Sin(double a)
{
	return sin(a);
}

double x2(double x)
{
	double y = pow(x, 2);
	return y;
}

double x24(double x)
{
	double y = x * 2 + 4;
	return y;
}


void FuncPoints(double a, double b, double (*func)(double))
{
	double step = ((b - a) / 10);
	for (double i = a; i <= b; i += step)
	{
		cout << "x = " << i << "\t\ty = " << (*func)(i) << endl;
	}
}

void task1()
{
	/*1.	**Реализовать 3 функции каждая из которых принимает вещественное число
		и возвращает вещественное число.Первая функция вычисляет квадратный корень числа, 
		вторая – куб числа, третья – синус числа.В главной функции создайте массив из 3 - х 
		указателей на эти функции.Добавьте меню, в котором пользователь может выбрать желаемую операцию.
		Напишите программу без использования операторов if и switch.*/
	double a;
	int choice;
	double (*calc[3])(double) = { Sqrt, ThirdPower, Sin };
	do
	{
		cout << "Write any number ";
		cin >> a;
		cout << "0 - to find the root" << endl;
		cout << "1 - to find third power" << endl;
		cout << "2 - to find sinus" << endl;
		cin >> choice;
		if (choice > 2 || choice < 0)
			break;
		cout << calc[choice](a) << endl;
	} while (true);
	cout << "Invalid operation" << endl;
}

void task2()
{
	/*2.	***Напишите 2 функции, каждая из которых принимает вещественный параметр и возвращает 
	вещественное значение. Пусть первая функция вычисляет y = x2 , а вторая – y = x*2+4, 
	где x – входной параметр y – возвращаемое значение. Затем напишите функцию, которая принимает 
	указатель на одну из этих функций, а также диапазон значений (от a до b) и выводит на экран 
	10 точек (координаты x и y) для этого диапазона. Напишите меню, которое иллюстрирует работу этих функций*/
	double a, b;
	int choice;
	double(*func[2])(double) = { x2, x24 };
	do
	{
		cout << "Write the left boarder: ";
		cin >> a;
		cout << "Write the right boarder: ";
		cin >> b;
		if (a >= b)
		{
			cout << "invalid boarders" << endl;
			break;
		}
		cout << "0 - to find y = x ^ 2" << endl;
		cout << "1 - to find y = x * 2 + 4" << endl;
		cin >> choice;
		if (choice > 1 || choice < 0)
		{
			cout << "Invalid operation" << endl;
			break;
		}
		FuncPoints(a, b, *func[choice]);
	} while (true);
	
}

int main()
{
	int a, flag;
	do
	{
		cout << "Write the number of task: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			task1();
			break;
		}
		case 2:
		{
			task2();
			break;
		}
		}
		cout << "Do you want to continue? 1 / 0: ";
		cin >> flag;
	} while (flag == 1);

	system("pause");
}