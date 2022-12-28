#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define XMIN -1000
#define XMAX 1000

int* full_array(int* p_arr, int n);
int* print_arr(int* p_arr, int n);
int* sort_buble(int* ptrarr, int n);
int* sort_shake(int* ptrarr, int n);
int* sort_select(int* ptrarr, int n);
int* sort_insert(int* ptrarr, int n);

void main1()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);
	int n;
	int* p_arr;
	printf("Введите количество элементов в массиве:\n>");
	scanf("%d", &n);
	p_arr = (int*)malloc(n * sizeof(int));
	if (p_arr == NULL)
	{
		printf("Ошибка выделения памяти");
		exit(-1);
	}
	p_arr = full_array(p_arr, n);
	// Задание 1.  Реализовать функции сортировки массива целых чисел
	printf("Пузырьковая:\n");
	p_arr = full_array(p_arr, n);
	p_arr = sort_buble(p_arr, n);
	print_arr(p_arr, n);

	printf("Шейкерная:\n");
	p_arr = full_array(p_arr, n);
	p_arr = sort_shake(p_arr, n);
	print_arr(p_arr, n);

	printf("Простым выбором:\n");
	p_arr = full_array(p_arr, n);
	p_arr = sort_select(p_arr, n);
	print_arr(p_arr, n);

	printf("Вставками:\n");
	p_arr = full_array(p_arr, n);
	p_arr = sort_insert(p_arr, n);
	print_arr(p_arr, n);
	free(p_arr);

	// Задание 2.  Разработать программный комплекс для проведения вычислительных экспериментов по оценке эффективности алгоритмов
	clock_t t;
	double time;
	printf("\n\nВведите количество элементов в массиве:\n>");
	scanf("%d", &n);
	p_arr = (int*)malloc(n * sizeof(int));
	p_arr = full_array(p_arr, n);

	p_arr = full_array(p_arr, n);
	t = clock();
	p_arr = sort_buble(p_arr, n);
	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
	printf("Пузырьковая: %lf\n", time);

	p_arr = full_array(p_arr, n);
	t = clock();
	p_arr = sort_shake(p_arr, n);
	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
	printf("Шейкерная: %lf\n", time);

	p_arr = full_array(p_arr, n);
	t = clock();
	p_arr = sort_select(p_arr, n);
	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
	printf("Простым выбором: %lf\n", time);

	p_arr = full_array(p_arr, n);
	t = clock();
	p_arr = sort_insert(p_arr, n);
	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
	printf("Вставками: %lf\n", time);
	free(p_arr);
}

// заполнение массива
int* full_array(int* p_arr, int n)
{
	for (int i = 0; i < n; i++)
		p_arr[i] = XMIN + rand() % (XMAX - XMIN + 1);
	return p_arr;
}

// вывод массива
int* print_arr(int* p_arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("A[%d] = %d\n", i, p_arr[i]);
	return p_arr;
}

// пузырьковая
int* sort_buble(int* ptrarr, int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--) // для всех элементов после i-ого
		{
			if (ptrarr[j - 1] > ptrarr[j]) // если текущий элемент меньше предыдущего
			{
				temp = ptrarr[j - 1]; // меняем их местами
				ptrarr[j - 1] = ptrarr[j];
				ptrarr[j] = temp;
			}
		}
	}
	return ptrarr;
}

// шейкерная
int* sort_shake(int* a, int n)
{
	int iLeft = 2, iRight = n, x;
	while (iLeft <= iRight)
	{
		for (int j = iLeft; j < iRight; j++)
		{
			if (a[j] < a[j - 1])
			{
				x = a[j];
				a[j] = a[j - 1];
				a[j - 1] = x;
			}
		}
		iRight--;
		for (int j = iRight; j > iLeft; j--)
		{
			if (a[j] < a[j - 1])
			{
				x = a[j];
				a[j] = a[j - 1];
				a[j - 1] = x;
			}
		}
		iLeft++;
	}
	return a;
}

// простым выбором
int * sort_select(int* a, int n)
{
	int min, temp;
	for (int i = 0; i < n - 1; i++)
	{
		min = i; 
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	return a;
}

// вставками
int* sort_insert(int* a, int n)
{
	int temp, j;
	for (int i = 1; i < n; i++)
	{
		temp = a[i];
		j = i;
		if (a[j - 1] > temp && j >= 0)
		{
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = temp;
	}
	return a;
}