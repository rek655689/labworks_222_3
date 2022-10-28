#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>

void main1(void)
{
	setlocale(LC_ALL, "RUS");
	
	// задание 1
	int years;
	puts("Введите год");
	scanf("%d", &years);
	printf("Год %d - %s", years, (years % 4 == 0 && years % 100 != 0) || years % 400 == 0 ? "високосный" : "не високосный");
	
	// задание 2
	// контрольные примеры: F(3.4, 2.1) = -0.255541; F(4.9, 28.6) = 1.89764
	float x, y;
	puts("Введите x и y");
	scanf("%f%f", &x, &y);
	if (x >= y) printf("F(%f, %f) = %lg", x, y, sin(x));
	else printf("F(%f, %f) = %lg", x, y, 1 + pow(cos(y), 2));
	
	// задание 3
	// контрольные примеры: F(-4) = 9; F(5) = 0.0384615
	double z; // при использовании x ошибка:  x : переопределение; различные базовые типы
	puts("Введите значение x");
	scanf("%lf", &z);
	printf("F(%lg) = %lg", x, x <= -3 ? 9 : 1 / (pow(x, 2) + 1));
}	