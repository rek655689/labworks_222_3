#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define XMIN -1000
#define XMAX 1000
#define N 100

double* full_elements(double* ptr_array, int n); // 1 задание
double* put_elements(double* ptr_array, int n); // 1 задание
double* calc_elements(double* ptr_array, int n); // 1 задание
double sum_elements(double* ptr_array, int begin, int end); // 2 задание
int find_element(double* ptr_array, int n, double element); // 2 задание

void main1()
{
	setlocale(LC_ALL, "RUS");
	int stime = (unsigned)time(NULL) / 2;
	srand(stime);

	// ЗАДАНИЕ 1. Напишите программу работы с массивом, где все операции (создание, обработка, поиск, печать) вынесены в отдельные функции.
	int size, start, end, index;
	double sum, elem;
	double* array[N];
	double* p_array = array;
	printf("Введите размер массива\n>");
	scanf("%d", &size);
	p_array = full_elements(p_array, size);
	p_array = put_elements(p_array, size);
	p_array = calc_elements(p_array, size);
	p_array = put_elements(p_array, size);

	// ЗАДАНИЕ 2. Разработайте дополнительные собственные функции обработки массива.
	printf("Введите начальный и конечный индексы отрезка, где произойдёт суммирование\n>");
	scanf("%d%d", &start, &end);
	sum = sum_elements(p_array, start, end);
	printf("Сумма элементов: %lg\n", sum);
	printf("Какой элемент найти?\n>");
	scanf("%lf", &elem);
	index = find_element(p_array, size, elem);
	if (index != -1)
		printf("Это элемент с индексом %d\n", index);
	else
		printf("Такого элемента в массиве нет\n");
	free(p_array);
}

// заполнение массива случайными значениями
double* full_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
		ptr_array[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	return ptr_array;
}

// печать элементов массива
double* put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
		printf("A[%d]: %lf\n", i, ptr_array[i]);
	return ptr_array;
}

// обработка элементов массива (обнулить отрицательные элементы массива)
double* calc_elements(double* ptr_array, int n)
{
	printf("Обработка..\n");
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] < 0)
			ptr_array[i] = 0;
	}
	return ptr_array;
}

// вычислениe суммы элементов массива от индекса begin до индекса end включительно
double sum_elements(double* ptr_array, int begin, int end)
{
	double sum = 0;
	for (int i = begin; i <= end; i++)
		sum += ptr_array[i];
	return sum;
}

// поиск элемента равного element
int find_element(double* ptr_array, int n, double element)
{
	// поскольку числа вещественные и при выводе обрезаются, ф-ция будет работать только с нулями
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element)
			return i;
	}
	return -1;
}