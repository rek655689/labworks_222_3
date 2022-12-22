#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define N 30

void main1()
{
	setlocale(LC_ALL, "RUS");

	// ЗАДАНИЕ 1. Напишите программу, которая вычисляет среднее арифметическое целых чисел, содержащихся в файле
	FILE* file;
	float a, sum = 0, n = 0, av;
	if ((file = fopen("temp.txt", "rt")) == NULL)
	{
		printf("Ошибка открытия файла");
		exit(-1);
	}
	while (!feof(file))
	{
		fscanf(file, "%f", &a);
		sum += a;
		n++;
	}
	av = (float)sum / n;
	printf("Среднее арифметическое: %g\n\n", av);
	fclose(file);

	// ЗАДАНИЕ 2. Программа, которая открывает указанный пользователем файл, выполняет преобразование над числами, записывает результат в файл с дополненным названием
	//			  3. Уменьшить все положительные числа в 4 раза.
	FILE *new_file;
	char name[N+4], new_name[N+12];
	printf("Введите название текстового файла (без расширения):\n>");
	fgets(name, N, stdin);
	for (int i = 0; i < N - 1; i++)
	{
		if (name[i] == '\n')
			name[i] = name[i + 1];
	}
	strcpy(new_name, name);
	strcat(name, ".txt");
	if ((file = fopen(name, "rt")) == NULL)
	{
		printf("Ошибка открытия файла %s", name);
		exit(-1);
	}
	strcat(new_name, "_reduce.txt");
	if ((new_file = fopen(new_name, "wt")) == NULL)
	{
		printf("Ошибка открытия файла %s", name);
		exit(-1);
	}
	while (!feof(file))
	{
		fscanf(file, "%f", &a);
		a = a > 0 ? a / 4 : a;
		fprintf(new_file, "%f\n", a);
	}
	fclose(file);
	fclose(new_file);
	printf("Задача 2 завершена");

}