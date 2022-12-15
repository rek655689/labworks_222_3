#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#define XMIN -2
#define XMAX 2
/*
Сгенерировать три массива со случайными вещественными числами, количество элементов случайно в
интервале от 10 до 50. Реализовать функцию, которая возвращает новый массив. Все 4 массива вывести на экран.

7. Массив d0, d1, d2, ..., dn, каждый элемент которого составляет произведение
элементов массива b0, b1, b2 ..., b100 до первого нулевого и сумму элементов,
расположенных после него и так (произведение, сумма, произведение, сумма
...) до конца.

ВЗЯТЫ ЦЕЛЫЕ ЧИСЛА, ТАК КАК ВЕРОЯТНОСТЬ ПОЛУЧЕНИЯ НУЛЕВЫХ ЗНАЧЕНИЙ ПРИ ВЕЩЕСТВЕННЫХ ЧИСЛАХ КРАЙНЕ МАЛА
*/

int* full_elements(int* array, int size);
int put_elements(int* ptr_array, int n);
int func(int* array1, int size1, int* array4);

void main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);

	int size1 = 10 + rand() % (50 - 10 + 1);
	int size2 = 10 + rand() % (50 - 10 + 1);
	int size3 = 10 + rand() % (50 - 10 + 1);

	int* array1 = malloc(size1 * sizeof(int));
	int* array2 = malloc(size2 * sizeof(int));
	int* array3 = malloc(size3 * sizeof(int));

	array1 = full_elements(array1, size1);
	array2 = full_elements(array2, size2);
	array3 = full_elements(array3, size3);

	printf("Массив A:\n");
	put_elements(array1, size1);
	printf("\n");
	printf("Массив B:\n");
	put_elements(array2, size2);
	printf("\n");
	printf("Массив C:\n");
	put_elements(array3, size3);
	printf("\n");
	
	int* array4 = malloc(size1 * sizeof(int));
	int size4;
	size4 = func(array1, size1, array4);
	printf("Массив D:\n");
	put_elements(array4, size4);

	free(array1);
	free(array2);
	free(array3);
	free(array4);

}

// заполнение массива случайными числами
int* full_elements(int* array, int size)
{
	for (int i = 0; i < size; i++)
		array[i] = XMIN + rand() % (XMAX - XMIN + 1);
	return array;
}

// вывод массива
int put_elements(int* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
		printf("A[%d]: %d\n", i, ptr_array[i]);
	return 1;
}


int func(int* array1, int size1, int* array)
{
	int k = -1; // текущий индекс в новом массиве
	int flag = 0; // флаг, показывающий, что мы заполняем - произведение (0) или сумму (1)
	int sum = 0, prod = 1;

	for (int i = 0; i < size1; i++)
	{
		if (array1[i] == 0)
		{
			k++;
			switch (flag)
			{
			case 0:
				flag = 1;
				array[k] = prod;
				prod = 1;
				break;
			case 1:
				flag = 0;
				array[k] = sum;
				sum = 0;
				break;
			}
		}
		else
		{
			switch (flag)
			{
			case 0:
				prod *= array1[i];
				break;
			case 1:
				sum += array1[i];
				break;
			}
		}
	}
	k++;
	switch (flag)
	{
	case 0:
		array[k] = prod;
		break;
	case 1:
		array[k] = sum;
		break;
	}
	array = (int*)realloc(array, (k + 1) * sizeof(int));
	return k + 1;
}