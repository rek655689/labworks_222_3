#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int delete_k(double* ptr_arr, int size, int k, int num);
void put_elements1(double* ptr_array, int n);
double* insert(double* ptr_arr, int* size, int k);

void main1()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);

	// ЗАДАНИЕ 1.  Напишите программу, которая работает с динамическим массивом
	int* ptr_array;
	int size;
	printf("Введите размер массива:\n>");
	scanf("%d", &size);
	ptr_array = (int*)malloc(size * sizeof(int));
	if (ptr_array == NULL) {
		puts("error");
		exit(-1);
	}
	for (int i = 0; i < size; i++)
	{
		ptr_array[i] = -100 + rand() % (100 - (-100) + 1);
		printf("A[%d]: %d\n", i, ptr_array[i]);
	}
	// обнуление отрицательных элементов
	printf("\nНовый массив:\n");
	for (int i = 0; i < size; i++)
	{
		if (ptr_array[i] < 0)
			ptr_array[i] = 0;
		printf("A[%d]: %d\n", i, ptr_array[i]);
	}
	free(ptr_array);

	// ЗАДАНИЕ 2. Перепишите программу так, чтобы массив хранил значения типа double, заполните его случайными числами от -1 до 1.
	double* ptr_array_d = NULL;
	int k, num;
	printf("Введите размер массива:\n>");
	scanf("%d", &size);
	ptr_array_d = malloc(size * sizeof(double));
	for (int i = 0; i < size; i++)
	{
		ptr_array_d[i] = -1 + rand() % (1 - (-1) + 1);
		printf("A[%d]: %lf\n", i, ptr_array_d[i]);
	}

	// 2.1 Выполните удаление заданного элемента массива
	printf("Введите сколько удалить элементов и с какого номера:\n>");
	scanf("%d%d", &k, &num);
	size = delete_k(ptr_array_d, size, k, num);
	put_elements1(ptr_array_d, size);

	// 2.2 Выполните вставку -999 после заданного элемента массива
	printf("Сколько раз вставить -999?\n>");
	scanf("%d", &k);
	ptr_array_d = insert(ptr_array_d, &size, k);
	put_elements(ptr_array_d, size);
	free(ptr_array_d);
}

// 3. Удаление из массива К элементов, начиная с заданного номера
int delete_k(double* ptr_arr, int size, int k, int num) {
	int n = size - k;
	for (int i = num; i < size; i++)
	{
		ptr_arr[i] = ptr_arr[i + k];
	}
	return n;
}

// печать элементов массива
void put_elements1(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
		printf("A[%d]: %lf\n", i, ptr_array[i]);
}

// 3. Вставка К элементов после минимального
double* insert(double* ptr_arr, int* size, int k)
{
	// ищем индекс минимального числа
	int min_i = 0;
	double min_val = 2;
	for (int i = 0; i < (*size); i++)
	{
		if (ptr_arr[i] <= min_val)
		{
			min_i = i;
			min_val = ptr_arr[i];
		}
		
	}

	int size_n = (*size) + k;
	if (ptr_arr == NULL) return NULL;
	double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
	if (ptr_arr_n == NULL) return ptr_arr;
	ptr_arr = ptr_arr_n;

	// сдвигаем исходные элементы
	for (int i = min_i + 1; i < (*size); i++)
		ptr_arr[i + k] = ptr_arr[i];

	// заполняем пустые места
	for (int i = min_i + 1; i < (min_i + 1 + k); i++)
		ptr_arr[i] = -999;

	*size = size_n;
	return ptr_arr;
}