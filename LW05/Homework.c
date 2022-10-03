#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double calculate(double x, double y, double z)
{
	double down_fraction = (2 * y) / (1 + pow(x, 2) * pow(y, 2));
	double fraction = (1 + pow(sin(x + y), 2)) / (fabs(x - down_fraction));
	return fraction * pow(x, fabs(y)) + pow(cos(atan2(1, z)), 2);
}


void main(void)
{
	setlocale(LC_ALL, "RUS");

	double x, y, z, result;
	// x = 3.74e-2, y = -0.825, z = 0.16e2;
	puts("Введите значения x, y, z");
	scanf("%lf%lf%lf", &x, &y, &z);
	result = calculate(x, y, z);
	printf("v = %.4lf", result);
}