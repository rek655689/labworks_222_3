#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define LEN 70
#define N 5

/* Создать структуру для хранения указанной в индивидуальном варианте записи, организовать в программе ввод 5-10 различных
записей, из полученного массива структур найти и напечатать информацию согласно индивидуальному варианту: 

Вариант 3. Запись «Сотрудник» = { Фамилия, Имя, Отчество, Должность, Зарплата, Дата рождения}
Вывести сведения о сотрудниках, у которых зарплата выше средней и возраст менее 30-ти лет.*/

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
float middle_salary(Employee* array, int size);

void main()
{
	setlocale(LC_ALL, "RUS");
	float m_sal;
	Employee emp_array[N];

	printf("Введите 5 сотрудников:\n");
	add_arr(emp_array, N);
	m_sal = middle_salary(emp_array, N);
	printf("Искомые сотрудники:\n");
	for (int i = 0; i < N; i++)
	{
		if ((emp_array[i].salary > m_sal) && (emp_array[i].birthday > 1992))
		{
			printf("%s %s %s %s %d %g\n",
				emp_array[i].surname, emp_array[i].name, emp_array[i].patronymic, emp_array[i].position, emp_array[i].birthday, emp_array[i].salary);
		}
	}

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

float middle_salary(Employee* array, int size)
{
	float result = 0;
	for (int i = 0; i < size; i++)
		result += array[i].salary;
	result /= size;
	return result;
}