#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define K 10
#define N 100

int rand1(int mmax); // задание 2
double rand_double1(double dmin, double dmax); // задание 2
int* rand2(int n, int mmax); // задание 2
double* rand_double2(int n, double dm); // задание 2


void main1()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);

	// ЗАДАНИЕ 1.  Напишите программу генерации случайных чисел типа "Угадай число"
	int m = 1 + rand() % 10;
	int k;
	double x;
	int* array1;
	double* array2;
	printf("Введите число:\n>");
	scanf("%d", &k);
	if (k == m)
		printf("Вы угадали, было выбрано ");
	else
		printf("Неверный ответ, было выбрано ");
	printf("%d\n", m);

	m = 1 + rand() % 3;
	printf("Выберите один вариант:\n	1. камень\n	2. ножницы\n	3. бумага\n>");
	scanf("%d", &k);
	if (k == m)
		printf("Вы угадали, было выбрано: ");
	else
		printf("Неверный ответ, было выбрано: ");
	switch (m)
	{
	case 1:
		printf("камень\n");
		break;
	case 2:
		printf("ножницы\n");
		break;
	case 3:
		printf("бумага\n");
		break;
	}


	// ЗАДАНИЕ 2. Разработайте функции для генерации случайных чисел различными способами
	printf("Введите кол-во целых чисел и максимальное из них:\n>");
	scanf("%d%d", &k, &m);
	array1 = (int*)rand2(k, m);
	for (int i = 0; i < k; i++)
		printf("А[%d]: %d\n", i, array1[i]);

	printf("Введите кол-во вещественых чисел и максимальное из них:\n>");
	scanf("%d%lf", &k, &x);
	array2 = rand_double2(k, x);
	for (int i = 0; i < k; i++)
		printf("А[%d]: %lg\n", i, array2[i]);
	free(array1);
	free(array2);


	// ЗАДАНИЕ 3. Оцените генерируемую последовательность чисел путем построения гистограммы частоты выпадания значений
	int counter[K+1] = { 0, 0 };
	array1 = rand2(N, K);
	for (int i = 0; i < N; i++)
		counter[array1[i]]++;
	//определяем максимальное значение = высоту
	int max_elem = 0;
	for (int i = 1; i < K+1; i++)
		max_elem = counter[i] > max_elem ? counter[i] : max_elem;
	// печать гистограммы
	for (int row = max_elem; row > 0; row--)
	{
		printf("%3d ", row);
		for (int col = 1; col <= K; col++)
		{
			if (counter[col] >= row)
				printf("%3c", '*');
			else
				printf("%3c", ' ');
		}
		printf("\n");
	}
	printf("%6c", ' ');
	for (int i = 1; i < K + 1; i++)
		printf("%3d", i);
}

// целое число от 1 до mmax
int rand1(int mmax) 
{
	return 1 + rand() % (mmax - 1 + 1);
}

//вещественное число в заданном диапазоне
double rand_double1(double dmin, double dmax)
{
	return dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
}

// n целых чисел от 1 до mmax
int* rand2(int n, int mmax)
{
	int* array = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		array[i] = rand1(mmax);
	return array;
}

//n вещественных чисел в диапазоне от -dm до +dm
double* rand_double2(int n, double dm)
{
	double* array = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
		array[i] = rand_double1(-dm, dm);
	return array;
}