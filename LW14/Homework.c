#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void full_elements(double* ptr_array, int n); // ф-ция берётся из файла заданий
void put_elements(double* ptr_array, int n);  // ф-ция берётся из файла заданий

int i_last_positive(double* ptr_array, int n);
double last_positive(double* ptr_array, int n);

void main()
{
	setlocale(LC_ALL, "RUS");
	int size, index;
	double elem;
	printf("Введите размер массива\n>");
	scanf("%d", &size);
	double* array = malloc(size * sizeof(double));
	full_elements(array, size);
	put_elements(array, size);

	index = i_last_positive(array, size);
	if (index != -1)
	{
		elem = last_positive(array, size);
		printf("Последний положительный элемент А[%d]: %lf\n", index, elem);
	}
	else
		printf("Нет положительных элементов\n");
	free(array);
}

// поиск индекса последнего положительного элемента
int i_last_positive(double* ptr_array, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (ptr_array[i] > 0)
			return i;
	}
	return -1;
}

// поиск значения последнего положительного элемента
double last_positive(double* ptr_array, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (ptr_array[i] > 0)
			return ptr_array[i];
	}
	return -1;
}