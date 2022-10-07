#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>

// наверное надо будет ещё на функции разбивать

/* ЗАДАЧА 1
	#define a 3 
	#define b 5

void main(void)
{
	setlocale(LC_ALL, "RUS");
	int answer;
	printf("Сколько будет %d * %d?", a, b);
	scanf("%d", &answer);
	if (answer == a * b) puts("Правильно!");
	else printf("Вы ошиблись, правильный результат - %d", a * b);
}
*/
/* ЗАДАЧА 2
void main(void)
{
	setlocale(LC_ALL, "RUS");
	double x, y, z;
	puts("Введите стороны треугольника");
	scanf("%lf%lf%lf", &x, &y, &z);
	// условие проверяется по теореме Пифагора
	printf("Прямоугольник со сторонами %lg, %lg и %lg - %s", x, y, z, \
		(pow(x, 2) == pow(y, 2) + pow(z, 2)) || (pow(y, 2) == pow(x, 2) + pow(z, 2)) || (pow(z, 2) == pow(y, 2) + pow(x, 2)) \
		? "прямоугольный" : "не прямоугольный");
};
*/

// ЗАДАЧА 3
int checking(double x, double y)
{
	if (x > 0 && y > 0) return 1;
	else if (x < 0 && y > 0) return 2;
	else if (x < 0 && y < 0) return 3;
	else return 4;
};

void main(void)
{
	setlocale(LC_ALL, "RUS");
	double x, y;
	puts("Введите координаты точки A");
	scanf("%lf%lf", &x, &y);
	if (x == 0 || y == 0) printf("Точка A(%lg, %lg) лежит на оси", x, y);
	else {
		int quarter = checking(x, y);
		printf("Точка A(%lg, %lg) находится в %d четверти", x, y, quarter);
	};
}

/* ЗАДАЧА 4
void main(void)
{
	setlocale(LC_ALL, "RUS");
	double x, y;
	puts("Введите два числа");
	scanf("%lf%lf", &x, &y);
	if (x > y) printf("%lg больше %lg", x, y);
	else if (x < y) printf("%lg меньше %lg", x, y);
	else printf("%lg равно %lg", x, y);
}
*/
/* ЗАДАЧА 5
void main(void)
{
	setlocale(LC_ALL, "RUS");
	float day;
	puts("Введите номер дня недели");
	scanf("%f", &day);
	// проверка того, что введено целое число, и что оно принадлежит отрезку [1, 7]
	if (day - (int)day != 0 || day > 7 || day < 1) puts("Ошибка ввода данных");
	else {
		printf("%s", day < 6 ? "Рабочий день" : "Выходной");
	};
}
*/
/* ЗАДАЧА 6
void main(void)
{
	setlocale(LC_ALL, "RUS");
	double x;
	puts("Введите число");
	scanf("%lf", &x);
	if (x >= (int)x + 0.5) printf("Округление в большую сторону: %d", (int)x + 1);
	else printf("Округление в меньшую сторону: %d", (int)x);
}
*/
/* ЗАДАЧА 7
void main(void)
{
	setlocale(LC_ALL, "RUS");
	double c;
	puts("Введите температуру в градусах Цельсия");
	scanf("%lf", &c);
	if (c <= 0) printf("При %lg градусах вода в твёрдом состоянии", c);
	else if (c > 0 && c < 100) printf("При %lg градусах вода в жидком состоянии", c);
	else printf("При %lg градусах вода в газообразном состоянии", c);
}
*/