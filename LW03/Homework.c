#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define g 9.8f

float calculate(float m, float h)
{
	float result;
	result = h * m * g;
	return result;
}

void main(void)
{
	setlocale(LC_ALL, "RUS");

	float m, h, result;
	puts("Введите значения массы тела и высоты падения");
	scanf("%f%f", &m, &h);
	result = calculate(m, h);
	printf("Сила тяжести составляет %g Ньютон", result);
}