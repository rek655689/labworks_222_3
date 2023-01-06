#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define LEN 70

typedef struct employee {
	char surname[LEN];
	char name[LEN];
	char patronymic[LEN];
	char position[LEN];
	int birthday;
	float salary;
} Employee;

void print_elems(Employee* arr, int n);
void print_one(Employee str);
Employee* add_f_file(FILE* file, Employee* arr, int* size);
Employee* edit_elem(Employee* arr, int size, int i);
int find_elem(Employee* arr, int size, char str[LEN]);
int sort_surname(const void* av, const void* bv);
int sort_name(const void* av, const void* bv);
int sort_patronymic(const void* av, const void* bv);
int sort_position(const void* av, const void* bv);
int sort_birthday(const void* av, const void* bv);
int sort_salary(const void* av, const void* bv);
void add_to_file(FILE* file, Employee* p_arr, int size);

void main()
{
	setlocale(LC_ALL, "RUS");
	int action = -1;
	char a;
	char fname[LEN], find_str[LEN];
	Employee* p_arr = NULL;
	int size = 0, x;
	FILE* file;
	void* func;

	printf("%50s", "Меню:\n");
	printf("	1. Ввод данных и файла\n"
		"	2. Изменение выбранной записи\n"
		"	3. Поиск записи в массиве по одному полю (surname)\n"
		"	4. Сортировка массива по выбранному полю\n"
		"	5. Сохранение измененного массива записей в новый файл\n"
		"	0. Выход из программы\n");

	while (action != 0)
	{
		printf("\nВыберите действие:\n>");
		scanf("%d", &action);
		switch (action)
		{
		case 1:
		{
			fname[0] = getchar();
			printf("Введите название текстового файла (без расширения):\n>");
			fgets(fname, LEN - 5, stdin);
			for (int i = 0; i < LEN - 6; i++)
			{
				if (fname[i] == '\n')
					fname[i] = fname[i + 1];
			}
			strcat(fname, ".txt");
			if ((file = fopen(fname, "r")) == NULL)
			{
				printf("Ошибка открытия файла %s", fname);
				exit(-1);
			}
			p_arr = add_f_file(file, p_arr, &size);
			fclose(file);
			print_elems(p_arr, size);
			break;
		}
		case 2:
		{
			printf("Запись под каким номером изменить?\n>");
			scanf("%d", &x);
			p_arr = edit_elem(p_arr, size, x - 1);
			print_elems(p_arr, size);
			break;
		}
		case 3:
		{
			a = fgetc(stdin);
			printf("Введите значение для поиска:\n>");
			fgets(find_str, LEN, stdin);
			for (int i = 0; i < LEN - 6; i++)
			{
				if (find_str[i] == '\n')
					find_str[i] = find_str[i + 1];
			}
			x = find_elem(p_arr, size, find_str);
			if (x == -1)
				printf("Нет записи с таким полем\n");
			else
				print_one(p_arr[x]);
			break;
		}
		case 4:
		{
			printf("По какому полю отсортировать массив?\n"
				"1. Фамилия\n2. Имя\n3. Отчество\n4. Должность\n5. Дата рождения\n6. Зарплата\n>");
			scanf("%d", &x);
			switch (x)
			{
			case 1:
				func = sort_surname;
				break;
			case 2:
				func = sort_name;
				break;
			case 3:
				func = sort_patronymic;
				break;
			case 4:
				func = sort_position;
				break;
			case 5:
				func = sort_birthday;
				break;
			case 6:
				func = sort_salary;
				break;
			default:
				printf("Нет такого варианта");
				exit(-1);
			}
			qsort(p_arr, size, sizeof(Employee), func);
			print_elems(p_arr, size);
			break;
		}
		case 5:
		{
			fname[0] = getchar();
			printf("Введите название нового текстового файла (без расширения):\n>");
			fgets(fname, LEN - 5, stdin);
			for (int i = 0; i < LEN - 6; i++)
			{
				if (fname[i] == '\n')
					fname[i] = fname[i + 1];
			}
			strcat(fname, ".txt");
			if ((file = fopen(fname, "w")) == NULL)
			{
				printf("Ошибка открытия файла %s", fname);
				exit(-1);
			}
			add_to_file(file, p_arr, size);
			fclose(file);
			break;
		}
		case 0:
		{
			printf("Выход из программы");
			exit(0);
			break;
		}
		default:
			printf("Нет такого действия\n");
			action = -1;
		}
	}
	free(p_arr);
}
// печать значений полей массива
void print_elems(Employee* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d.	", i + 1);
		print_one(arr[i]);
	}
}
// печать значений полей одной записи
void print_one(Employee str)
{
	printf("%s %s %s %s %d %g\n",
		str.surname, str.name, str.patronymic,
		str.position, str.birthday, str.salary);
}
// заполнение массива из файла
Employee* add_f_file(FILE* file, Employee* arr, int* size)  // !!!!
{
	int i = 0;
	char a;
	while (!feof(file))
	{
		arr = (Employee*)realloc(arr, (i + 1) * sizeof(Employee));
		fscanf(file, " %s", &arr[i].surname);
		fscanf(file, " %s", &arr[i].name);
		fscanf(file, " %s", &arr[i].patronymic);
		fscanf(file, " %s", &arr[i].position);
		fscanf(file, "%d", &arr[i].birthday);
		fscanf(file, "%f", &arr[i].salary);
		a = fgetc(file);
		i++;
	}
	*(size) = i;
	return arr;
}
// изменение записи
Employee* edit_elem(Employee* arr, int size, int i)
{
	printf("Введите новые данные:\n");
	printf("Фамилия: ");
	scanf(" %s", &arr[i].surname);
	printf("Имя: ");
	scanf(" %s", &arr[i].name);
	printf("Отчество: ");
	scanf(" %s", &arr[i].patronymic);
	printf("Должность: ");
	scanf(" %s", &arr[i].position);
	printf("Дата рождения (год): ");
	scanf("%d", &arr[i].birthday);
	printf("Зарплата: ");
	scanf("%f", &arr[i].salary);
	return arr;
}
// поиск записи по полю surname
int find_elem(Employee* arr, int size, char str[LEN])
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(arr[i].surname, str))
			return i;
	}
	return -1;
}
// сортировка по фамилии
int sort_surname(const void* av, const void* bv)
{
	const Employee* a = av, * b = bv;
	return -strcmp(a->surname, b->surname);
}
// сортировка по имени
int sort_name(const void* av, const void* bv)
{
	const Employee* a = av, * b = bv;
	return -strcmp(a->name, b->name);
}
// сортировка по отчеству
int sort_patronymic(const void* av, const void* bv)
{
	const Employee* a = av, * b = bv;
	return -strcmp(a->patronymic, b->patronymic);
}
// сортировка по должности
int sort_position(const void* av, const void* bv)
{
	const Employee* a = av, * b = bv;
	return -strcmp(a->position, b->position);
}
// сортировка по дате рождения
int sort_birthday(const void* av, const void* bv)
{
	const Employee* a = av, * b = bv;
	if (a->birthday < b->birthday) return -1;
	if (a->birthday > b->birthday) return 1;
	return 0;
}
// сортировка по зарплате
int sort_salary(const void* av, const void* bv)
{
	const Employee* a = av, * b = bv;
	if (a->salary < b->salary) return -1;
	if (a->salary > b->salary) return 1;
	return 0;
}
// вывод в файл
void add_to_file(FILE* file, Employee* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%s", arr[i].surname);
		fprintf(file, "%s", arr[i].name);
		fprintf(file, "%s", arr[i].patronymic);
		fprintf(file, "%s", arr[i].position);
		fprintf(file, "%d", arr[i].birthday);
		fprintf(file, "%f", arr[i].salary);
		fprintf(file, "\n");
	}
}