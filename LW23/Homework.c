#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LEN 70

struct emp_node {
	char surname[LEN];
	char name[LEN];
	char patronymic[LEN];
	char position[LEN];
	int birthday;
	float salary;
	struct emp_node* next;
};
typedef struct emp_node Emp_node;

struct emp_list {
	Emp_node* head;
};
typedef struct emp_list Emp_list;

void print_struct(Emp_node str);
void print_emp_list(Emp_list* list);
Emp_node* find_emp(Emp_list* list, int year);
void sort_merge(Emp_node* head);

void main()
{
	setlocale(LC_ALL, "RUS");
	Emp_list list;  
	Emp_node* tmp, *cur = NULL;
	int n;
	printf("Введите количество сотрудников:\n>");
	scanf("%d", &n);
	printf("Введите данные:\n");
	for (int i = 0; i < n; i++)
	{
		tmp = (Emp_node*)malloc(sizeof(Emp_node));
		printf("Фамилия: ");
		scanf(" %s", &tmp->surname);
		printf("Имя: ");
		scanf(" %s", &tmp->name);
		printf("Отчество: ");
		scanf(" %s", &tmp->patronymic);
		printf("Должность: ");
		scanf(" %s", &tmp->position);
		printf("Дата рождения (год): ");
		scanf("%d", &tmp->birthday);
		printf("Зарплата: ");
		scanf("%f", &tmp->salary);
		printf("\n");
		tmp->next = NULL;
		if (cur == NULL)
		{
			list.head = tmp;
			cur = tmp;
			continue;
		}
		cur->next = tmp;
		cur = tmp;
	}
	printf("Список:\n");
	print_emp_list(&list);
	printf("\nВывести сотрудника, год рождения которого равен\n>");
	scanf("%d", &n);
	cur = find_emp(&list, n);
	print_struct(*cur);
	printf("\nОтсортированный список:\n");
	sort_merge(&list.head);
	print_emp_list(&list);
}

// печать значений полей одной записи
void print_struct(Emp_node str)
{
	printf("%s %s %s %s %d %g\n",
		str.surname, str.name, str.patronymic,
		str.position, str.birthday, str.salary);
}
// вывод списка
void print_emp_list(Emp_list* list)
{
	Emp_node* p = list->head;
	while (p != NULL) {
		print_struct(*p);
		p = p->next;
	}
}

// поиск по дате рождения
Emp_node* find_emp(Emp_list* list, int year)
{
	Emp_node* p = list->head;
	while (p != NULL) {
		if (p->birthday == year)
			break;
		p = p->next;
	}
	return p;
}

// функции для сортировки слиянием
Emp_node* sortedmerge(Emp_node* a, Emp_node* b)
{
	Emp_node* temp, *root = NULL, *result = NULL;
	while (a != NULL || b != NULL) {
		if (a == NULL || (b != NULL &&
			b->salary < a->salary)) {
			temp = a; a = b; b = temp;
		}
		if (root == NULL)result = root = a;
		else root = (root->next = a);
		a = a->next;

	}
	return result;
}
void frontbacksplit(Emp_node* source, Emp_node** frontRef, Emp_node** backRef)
{
	Emp_node* fast;
	Emp_node* slow;
	slow = source;
	fast = source->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
void sort_merge(Emp_node** head)
{
	if (*head == NULL || (*head)->next == NULL) {
		return;
	}
	struct Emp_node* a;
	struct Emp_node* b;
	frontbacksplit(*head, &a, &b);
	sort_merge(&a);
	sort_merge(&b);

	*head = sortedmerge(a, b);
}
