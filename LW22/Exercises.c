#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define SCREENW 100
#define SCREENH 60
typedef double (*TFunc) (double);
double func_v(double);
double func_y(double);
void plot(double, double, TFunc);
void tabulating(double, double, double, TFunc);

void main(void)
{
	setlocale(LC_ALL, "RUS");
	int choice = -1, func;
	double x, x1, step, result;
	char bracket1, bracket2;


	while (choice != 0)
	{
		printf("\nВыберите действие:\n");
		printf("	1. Нахождение значения функции при заданном значении аргумента.\n"
			"	2. Табулирование функции.\n"
			"	3. Построение графика функции.\n"
			"	0. Выйти их программы.\n"
			">");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			printf("Введите значение аргумента:\n"
			">");
			scanf("%lf", &x);
			printf("Выберете функцию: \n\n"
				"	1. Y(x) = ln(x + 1) * sin(x)						ОДЗ: x > -1\n\n"
				"	           / sin(x^3) - (ln|sin(x)|)^1/2,     при 0 < x <= 5		ОДЗ: pi/2 \n"
				"	2. V(x) = | 3/4 * e^x,                        при 5 < x < 10\n"
				"	           \\ 3 * sin(x)^3 + cos(x),           при x >= 10\n\n"
				">");
			scanf("%d", &func);
			switch (func)
			{
			case 1:
			{
				result = func_y(x);
				printf("Результат: %lg\n", result);
				break;
			}
			case 2:
			{
				result = func_v(x);
				printf("Результат: %lg\n", result);
				break;
			}
			default:
			{
				printf("Нет такой функции.\n");
				break;
			}
			}
			break;
		}
		case 2:
		{
			printf("Введите интервал в формате [x1, x2):\n"
				">");
			scanf(" %c%lf; %lf%c", &bracket1, &x, &x1, &bracket2);
			printf("Введите шаг:"
				">");
			scanf("%lf", &step);
			x = bracket1 == '(' ? x + step : x;
			x1 = bracket2 == ')' ? x1 - step : x1;
			printf("Выберете функцию: \n\n"
				"	1. Y(x) = ln(x + 1) * sin(x)						ОДЗ: x > -1\n\n"
				"	           / sin(x^3) - (ln|sin(x)|)^1/2,     при 0 < x <= 5		ОДЗ: pi/2 \n"
				"	2. V(x) = | 3/4 * e^x,                        при 5 < x < 10\n"
				"	           \\ 3 * sin(x)^3 + cos(x),           при x >= 10\n\n"
				">");
			scanf("%d", &func);
			switch (func)
			{
			case 1:
			{
				tabulating(x, x1, step, func_y);
				printf("\n");
				break;
			}
			case 2:
			{
				tabulating(x, x1, step, func_v);
				printf("\n");
				break;
			}
			default:
			{
				printf("Нет такой функции.\n");
				break;
			}
			}
			break;
		}
		case 3:
		{
			printf("Введите начальное и конечное значение:\n"
				">");
			scanf("%lf%lf", &x, &x1);
			printf("Выберете функцию: \n\n"
				"	1. Y(x) = ln(x + 1) * sin(x)						ОДЗ: x > -1\n\n"
				"	           / sin(x^3) - (ln|sin(x)|)^1/2,     при 0 < x <= 5		ОДЗ: pi/2 \n"
				"	2. V(x) = | 3/4 * e^x,                        при 5 < x < 10\n"
				"	           \\ 3 * sin(x)^3 + cos(x),           при x >= 10\n\n"
				">");
			scanf("%d", &func);
			switch (func)
			{
			case 1:
			{
				plot(x, x1, func_y);
				printf("\n");
				break;
			}
			case 2:
			{
				plot(x, x1, func_v);
				printf("\n");
				break;
			}
			default:
			{
				printf("Нет такой функции.\n");
				break;
			}
			}
			break;
		}
		case 0:
		{
			printf("Выход из программы.");
			break;
		}
		default:
		{
			printf("Нет такого варианта.");
			break;
		}
		}
	}
}


/* Вычисление функции Y(x) */
double func_y(double x)
{
	double result;
	if (x <= -1) result = NAN;
	result = log(x + 1) * sin(x);
	return result;
}
// --------------------------------------------
/* Вычисление функции V(x) */
double func_v(double x)
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

/* Табуляция функции */
void tabulating(double start, double end, double step, TFunc func)
{
	double result;
	printf("______________________________________\n");
	printf("|        x         |       f(x)       |\n");
	printf("|------------------|------------------|\n");
	for (double i = start; i <= end; i += step) {
		result = func(i);
		if (isnan(result) || isinf(result))
			printf("| %16.5lg | %16c |\n", i, '-');
		else printf("| %16.5lg | %16.5lg |\n", i, result);
	}
	printf("|------------------|------------------|\n");
}
// --------------------------------------------
/* Рисование графика функции */
void plot(double x0, double x1, TFunc f)
{
	char screen[SCREENW][SCREENH];
	double x, y[SCREENW];
	double ymin = 0, ymax = 0;
	double hx, hy;
	int i, j;
	int xz, yz;
	hx = (x1 - x0) / (SCREENW - 1);
	for (i = 0, x = x0; i < SCREENW; ++i, x += hx) {
		y[i] = f(x); //расчет значений функции для каждой точки поля вывода графика
		if (isnan(y[i])) y[i] = 0;
		if (y[i] < ymin) ymin = y[i];
		if (y[i] > ymax) ymax = y[i];
	}
	hy = (ymax - ymin) / (SCREENH - 1);
	yz = (int)floor(ymax / hy + 0.5);
	xz = (int)floor((0. - x0) / hx + 0.5);
	//построение осей и заполнение массива отображения пробелами
	for (j = 0; j < SCREENH; ++j)
		for (i = 0; i < SCREENW; ++i) {
			if (j == yz && i == xz) screen[i][j] = '+';
			else if (j == yz) screen[i][j] = '-';
			else if (i == xz) screen[i][j] = '|';
			else screen[i][j] = ' ';
		}
	//определение положения значения функции на поле вывода
	for (i = 0; i < SCREENW; ++i) {
		j = (int)floor((ymax - y[i]) / hy + 0.5);
		if (y[i] != 0) screen[i][j] = '*';
	}
	//печать массива символов
	for (j = 0; j < SCREENH; ++j) {
		for (i = 0; i < SCREENW; ++i)  putchar(screen[i][j]);
		putchar('\n');
	}
}