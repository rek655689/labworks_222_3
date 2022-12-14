#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#define LEN 70
#define N 5

// Разработайте программу, которая записывает в файл поля структуры задания 3 работы 18

struct employee {
	char surname[LEN];
	char name[LEN];
	char patronymic[LEN];
	char position[LEN];
	int birthday;
	float salary;
};
typedef struct employee Employee;
void add_arr(Employee* array, int size);
void write_file(char* fname, Employee* array, int size);

void main()
{
	setlocale(LC_ALL, "RUS");
	Employee emp_array[N];
	char* fname = "employees.txt";
	printf("Введите 5 сотрудников:\n");
	add_arr(emp_array, N);
	write_file(fname, emp_array, N);
	printf("\nЗаписано в файл\n");
}

void add_arr(Employee* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Фамилия: ");
		scanf(" %s", &array[i].surname);
		printf("Имя: ");
		scanf(" %s", &array[i].name);
		printf("Отчество: ");
		scanf(" %s", &array[i].patronymic);
		printf("Должность: ");
		scanf(" %s", &array[i].position);
		printf("Дата рождения (год): ");
		scanf("%d", &array[i].birthday);
		printf("Зарплата: ");
		scanf("%f", &array[i].salary);
		printf("\n");
	}
}

void write_file(char* fname, Employee* array, int size)
{
	FILE* file;
	if ((file = fopen(fname, "wt")) == NULL)   
	{
		printf("Ошибка открытия файла для записи");
		exit(-1);
	}
	for (int i = 0; i < N; i++)
		fprintf(file, "Фамилия: %s, Имя: %s, Отчество: %s, Должность: %s, Дата рождения: %d, Зарплата: %g\n",
			array[i].surname, array[i].name, array[i].patronymic, array[i].position, array[i].birthday, array[i].salary);
	fclose(file);
}