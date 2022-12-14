#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#define N 10
#define XMAX 1000
#define XMIN -1000

/*
Реализовать функцию calculate (TFun prtf, double *x, int n), которая по
заданной указателем prtf функции для значений массива х, размера n
Вычисляет произведение всех значений функции, для которых
выполняются неравенства 0 <y< 3,2.
*/
typedef double (*TFunc) (double);

double func_1(double x)
{
	double result;
	if (x <= -1) result = NAN;
	result = log(x + 1) * sin(x);
	return result;
}
double func_2(double x)
{
	double result;
	if (0 < x && x <= 5) result = sin(pow(x, 3)) - sqrt(log(fabs(sin(x))));
	else
	{
		if (5 < x && x < 10) result = ((double)3 / 4) * exp(x);
		else
		{
			if (x >= 10) result = 3 * pow(sin(x), 3) + cos(x);
			else result = NAN;
		}
	}
	return result;
}

double calculate(TFunc func, double* x, int n)
{
	double result = 1;
	double y;
	for (int i = 0; i < n; i++)
	{
		y = func(x[i]);
		if (isnan(y) || isinf(y))
			printf("| %16.5lg | %16c |\n", x[i], '-');
		else 
		{
			printf("| %16.5lg | %16.5lg |\n", x[i], y);
			if (0 < y && y < 3.2)
				result *= y;
		}
	}
	return result;
}

void main1()
{
	setlocale(LC_ALL, "RUS");
	int stime;
	stime = (unsigned long)time(NULL) / 2;
	srand(stime);

	double x[N];
	for (int i = 0; i < N; i++)
		x[i] = XMIN + (double)1 * (XMAX - XMIN) * rand() / RAND_MAX;

	int choice;
	double result;
	printf("%50s", "Выберите функцию:\n\n");
	printf("	1. Y(x) = ln(x + 1) * sin(x)						ОДЗ: x > -1\n\n"
		"	           / sin(x^3) - (ln|sin(x)|)^1/2,     при 0 < x <= 5		ОДЗ: pi/2 \n"
		"	2. V(x) = | 3/4 * e^x,                        при 5 < x < 10\n"
		"	           \\ 3 * sin(x)^3 + cos(x),           при x >= 10\n\n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("______________________________________\n");
		printf("|        x         |       f(x)       |\n");
		printf("|------------------|------------------|\n");
		result = calculate(func_1, x, N);
		printf("|------------------|------------------|\n");
		printf("Произведение: %lg\n", result);
		break;
	case 2:
		printf("______________________________________\n");
		printf("|        x         |       f(x)       |\n");
		printf("|------------------|------------------|\n");
		result = calculate(func_2, x, N);
		printf("|------------------|------------------|\n");
		printf("Произведение: %lg\n", result);
		break;
	default:
		puts("Нет такого варианта.\n");
	}


}

