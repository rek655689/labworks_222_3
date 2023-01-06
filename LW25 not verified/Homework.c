// ЛАБУ ЗАСЧИТАЛИ КАК ЧАСТЬ КУРСАЧА, ОСОБО НЕ ПРОВЕРЯЛИ 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Перестановка местами соседних элементов на четных и нечетных позициях

void main1()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);

	int count, max_val, temp, flag = 0;
	printf("Введите количество элементов и максимальное значение:\n>");
	scanf("%d%d", &count, &max_val);

	// заполняем массив
	int* array = malloc(count * sizeof(int));
	for (int i = 0; i < count; i++)
	{
		array[i] = 1 + rand() % max_val;
		printf("A[%d]: %d\n", i, array[i]);
	}

	// если кол-во элементов нечётное, последний не трогаем
	if (count % 2 != 0)
	{
		count -= 1;
		flag = 1;
	}

	// меняем местами
	printf("\nНовый массив:\n");
	for (int i = 0; i < count - 1; i += 2)
	{
		temp = array[i];
		array[i] = array[i + 1];
		array[i + 1] = temp;
		printf("A[%d]: %d\nA[%d]: %d\n", i, array[i], i + 1, array[i + 1]);
	}
	// если кол-во было нечётное, выводим последний элемент
	if (flag)
		printf("A[%d]: %d", count, array[count]);
	free(array);
}