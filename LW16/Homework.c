#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#define XMIN -1000
#define XMAX 1000
/*
Сгенерировать три массива со случайными вещественными числами, количество элементов случайно в
интервале от 10 до 50. Реализовать функцию, которая возвращает новый массив. Все 4 массива вывести на экран.

3. Новый массив, чтобы чередовались положительные элементы первого массива и 
отрицательные числа массива третьего массива.
*/

double* add_arr(double* array, int size);
void print_arr(double* ptr_array, int n, char c);
double* func(int* size4, double* array1, int size1, double* array3, int size3, double* array4);

void main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);

	int size1 = 10 + rand() % (50 - 10 + 1);
	double* array1 = malloc(size1 * sizeof(double));
	array1 = add_arr(array1, size1);
	print_arr(array1, size1, 'A');
	printf("\n");

	int size2 = 10 + rand() % (50 - 10 + 1);
	double* array2 = malloc(size2 * sizeof(double));
	array2 = add_arr(array2, size2);
	print_arr(array2, size2, 'B');
	printf("\n");

	int size3 = 10 + rand() % (50 - 10 + 1);
	double* array3 = malloc(size3 * sizeof(double));
	array3 = add_arr(array3, size3);
	print_arr(array3, size3, 'C');
	printf("\n");
	
	double* array4 = malloc((size1 + size3) * sizeof(double));
	int size4;
	array4 = func(&size4, array1, size1, array3, size3, array4);
	print_arr(array4, size4, 'D');

	free(array1);
	free(array2);
	free(array3);
	free(array4);

}

// заполнение массива случайными числами
double* add_arr(double* array, int size)
{
	for (int i = 0; i < size; i++)
		array[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	return array;
}

// вывод массива
void print_arr(double* ptr_array, int n, char c)
{
	for (int i = 0; i < n; i++)
		printf("%c[%d]: %lf\n", c, i, ptr_array[i]);
}

// ЛАБУ ПРОВЕРИЛИ, ПОСОВЕТОВАЛИ ДОДЕЛАТЬ, ТЕПЕРЬ ФУНКЦИЯ НЕ РАБОТАЕТ И МНЕ ВПАДЛУ ПЕРЕДЕЛЫВАТЬ
double* func(int* size4, double* array1, int size1, double* array3, int size3, double* array4)
{
	int k_A = 0, k_C = 1;  // k - индекс в массиве
	*size4 = 0;
	for (int i = 0; i < size1; i++)
	{
		if (array1[i] > 0)
		{
			array4[k_A] = array1[i];
			k_A+=2;
			*size4 += 1;
		}
	}
	for (int i = 0; i < size3; i++)
	{
		if (array3[i] < 0)
		{
			array4[k_C] = array3[i];
			k_C+=2;
			*size4 += 1;
		}
	}
	*size4 = k_A > k_C ? k_A : k_C;
	print_arr(array4, *size4, 'D');
	if (array4 == NULL)
	{
		printf("Ошибка перераспределения памяти");
		exit(-1);
	}
	// убираем пустые ячейки, сдвигая ячейки со значениями
	for (int i = 0; i < (*size4); i++)
	{
		if (array4[i] > XMAX || array4[i] < XMIN)
		{
			for (int j = i, s = 1; j + s < (*size4); j++, s++)
			{
				array4[j] = array4[j + s];
			}
			break;
		}
	}
	array4 = (double*)realloc(array4, (*size4) * sizeof(double));
	return array4;
}