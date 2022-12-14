#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#define LEN 70

// к заданию 2
float func(float x);
void tab(char* mode, float step);


int main1()
{
	setlocale(LC_ALL, "RUS");

	// ЗАДАНИЕ 1.  Напишите программу, которая создает новый файл number.txt в текущей папке 
	//				и записывает в него произвольную цифру и закрывает файл. 
	char fname[20] = "number.txt";
	FILE* out;
	printf("Создание файла\n");
	if ( (out = fopen(fname, "at")) == NULL )   // wt изменили на at
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	fprintf(out, "%d\n", 5);
	fclose(out);

	//ЗАДАНИЕ 2. Разработайте программу, которая записывает в файл temp.txt, содержащих результат 
	//			  табулирования функции (работа 8 зад.2) вводом из stdin интервала и шага табуляции
	float step;
	char mode[3] = "wt";
	int choice;
	printf("Введите значение шага табуляции:\n>");
	scanf("%f", &step);
	printf("Выбере режим записи:\n"
	"	1. перезаписать файл или создать новый\n"
	"	2. дозаписать в файл\n>");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		break;
	case 2:
		strcpy(mode, "at");
		break;
	default:
		printf("Нет такого варианта");
		return -1;
	}
	tab(mode, step);
	return 0;
}

float func(float x) {
	float result = (float)(1.8 * pow(x, 2) - sin(10 * x));
	return result;
}

void tab(char* mode,  float step)
{
	FILE* file;
	if ((file = fopen("temp.txt", mode)) == NULL) 
	{
		printf("Ошибка открытия файла для записи");
		exit(-1);
	}
	fprintf(file, "%80s", "f(x) = 1.8x^2 - sin10x\n");

	fprintf(file, "___________________________\n");
	fprintf(file, "| %-10s | %-10s |\n", "x", "f(x)");
	fprintf(file, "|------------|------------|\n");
	for (float i = 0.2f; i <= 2.2f; i += step) {
		fprintf(file, "| %10.3f | %10.3f |\n", i, func(i));
	}
	fprintf(file, "|------------|------------|\n\n");
	fclose(file);
}