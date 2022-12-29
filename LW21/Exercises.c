#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define LEN 70
#define N 3

typedef struct employee {
	char surname[LEN];
	char name[LEN];
	char patronymic[LEN];
	char position[LEN];
	int birthday;
	float salary;
} Employee;

// 1
Employee* input_emps(Employee* arr, int n);
void print_emps(Employee* arr, int n);
void print_struct(Employee str);
//2
int compare_position(const void* av, const void* bv);


void main1()
{
	setlocale(LC_ALL, "RUS");
	// ЗАДАНИЕ 1. Реализуйте создание, инициализацию и вывод значений полей массива структур
	Employee emp_arr[N];
	Employee* p_arr = emp_arr;
	p_arr = input_emps(emp_arr, N);
	print_emps(emp_arr, N);

	// ЗАДАНИЕ 2. Включите функцию поиска и сортировки для заданных полей структуры
	qsort(p_arr, N, sizeof(Employee), compare_position);
	print_emps(emp_arr, N);
}
// заполнение полей массива
Employee* input_emps(Employee* array, int n)
{
	for (int i = 0; i < n; i++)
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
	return array;
}
// печать значений полей массива 
void print_emps(Employee* arr, int n)
{
	for (int i = 0; i < n; i++)
		print_struct(arr[i]);
}
// печать значений полей одной записи
void print_struct(Employee str) 
{
	printf("%s %s %s %s %d %g\n",
		str.surname, str.name, str.patronymic, 
		str.position, str.birthday, str.salary);
}
// сравнение по должности
int compare_position(const void* av, const void* bv)
{
	const Employee* a = av, * b = bv;
	return -strcmp(a->name, b->name);
}