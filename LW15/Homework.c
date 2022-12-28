#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define TYPES 5
#define PLAYERS 20
#define MIN 0
#define MAX 10

/* 
3. В двумерном массиве хранится информация о баллах, полученных спортсменами-пятиборцами в каждом из пяти видов спорта 
(в первой строке — информация о баллах первого спортсмена, во второй — второго и т. д.). 
Общее число спортсменов равно 20. Определить общую сумму баллов, набранных третьим спортсменом.
Значения элементов генерируются случайным образом из контекста условия
*/

void add_val(double sport[][TYPES], int players, int types);
double third_sum(double sport[][TYPES], int players, int types);

void main()
{
	setlocale(LC_ALL, "RUS"); 
	srand((unsigned)time(NULL) / 2);
	double sport[PLAYERS][TYPES];
	double sum;
	add_val(sport, PLAYERS, TYPES);
	sum = third_sum(sport, PLAYERS, TYPES);
	printf("\nСумма баллов третьего спортсмена: %.3lg", sum);
}

void add_val(double sport[][TYPES], int players, int types)
{
	for (int i = 0; i < players; i++)
	{
		printf("Спортсмен %2d:   ", i + 1);
		for (int j = 0; j < types; j++)
		{
			sport[i][j] = MIN + 1.f * (MAX - MIN) * rand() / RAND_MAX;
			printf("%3.3lf    ", sport[i][j]);
		}
		printf("\n");
	}
}

double third_sum(double sport[][TYPES], int players, int types)
{
	double sum = 0;
	for (int j = 0; j < types; j++)
		sum += sport[2][j];
	return sum;
}