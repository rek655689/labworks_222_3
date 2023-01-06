#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "list.h"

void print_list(List* list)
{
	Node* p = list->head;
	printf("Список узлов:\n");
	while (p != NULL) {
		printf("Узел %d, данные: %s\n", p->number, p->name);
		p = p->next;
	}
}

void main2()
{
	setlocale(LC_ALL, "RUS");
	// ЗАДАНИЕ 1. Реализуйте односвязный линейный список, согласно интерфейсу, представленному в заголовочном файле list.h
	List list;  // нельзя объявить как указатель, тк в след функции ругается на неинициализированную переменную
	initlist(&list);
	Node temp;
	printf("\nНачало списка\n");
	printf("Введите данные:\n>");
	scanf("%s", &temp.name);
	temp.number = 1;
	temp.next = NULL;
	list.head = &temp;
	print_list(&list);
	int num;
	char str[80];
	int action = -1;
	while (action != 0)
	{
		printf("\nВыберите действие:\n");
		printf("	1. Вставка в список перед узлом со значением поля number=val\n"
			"	2. Вставка в список после узла со значением поля number=val\n"
			"	3. Вставка в список перед узлом со значением поля name=str\n"
			"	4. Вставка в список после узла со значением поля name=str\n"
			"	5. Проверяет, является ли список пустым\n"
			"	6. Определение длины списка\n"
			"	7. Удаление заданного узла из списка\n"
			"	8. Нахождение узла со значением num в поле number\n"
			"	9. Нахождение узла со значением str в поле name\n"
			"	0. Выйти из программы\n>");
		scanf("%d", &action);
		switch (action)
		{
		case 1:
			printf("Введите значение поля number\n>");
			scanf("%d", &num);
			insertfront(&list, num);
			print_list(&list);
			break;
		case 2:
			printf("Введите значение поля number\n>");
			scanf("%d", &num);
			insertback(&list, num);
			print_list(&list);
			break;
		case 3:
			printf("Введите значение поля str\n>");
			scanf(" %s", &str);
			insertfront_str(&list, str);
			print_list(&list);
			break;
		case 4:
			printf("Введите значение поля str\n>");
			scanf(" %s", &str);
			insertback_str(&list, str);
			print_list(&list);
			break;
		case 5:
			switch (isempty(&list))
			{
			case 1:
				printf("Список не пустой\n");
				break;
			case 0:
				printf("Список пустой\n");
			}
			break;
		case 6:
			num = length(list);
			printf("Длина списка %d\n", num);
			break;
		case 7:
			printf("Введите значение поля number\n>");
			scanf("%d", &num);
			temp = getitem(list, num);
			destroyItem(&list, temp);
			print_list(&list);
			break;
		case 8:
			printf("Введите значение поля number\n>");
			scanf("%d", &num);
			temp = getitem(list, num);
			printf("Узел %d, данные: %s\n", temp.number, temp.name);
			break;
		case 9:
			printf("Введите значение поля str\n>");
			scanf(" %s", &str);
			temp = getitem_str(list, str);
			printf("Узел %d, данные: %s\n", temp.number, temp.name);
			break;
		case 0:
			printf("Выход из программы\n");
			exit(0);
		}
	}
}

/* инициализация списка пустым содержимым */
void initlist(List* list)
{
	list->head = NULL;
}

/* вставка в список перед узлом со значением поля number=val */
void insertfront(List* list, int val)
{
	Node* p_node = (Node*)malloc(sizeof(Node));
	p_node->number = val - 1;
	printf("Введите данные:\n>");
	scanf("%s", &p_node->name);
	
	// поиск узла со значением val
	Node* cursor = list->head;
	if (list->head->number == val)  // если начало списка удовлетворяет условию, пихаем перед ним узел
	{
		list->head->next = NULL;
		p_node->next = list->head;
		list->head = p_node;
	}
	else
	{
		while (cursor->next != NULL)  // ищем до тех пор, пока есть хотя бы один элемент после того, что сейчас рассматриваем
		{
			if (cursor->next->number == val)  // если в следующем элементе условие выполняется, то класс
				break;
			cursor = cursor->next;
		}

		if (cursor->next != NULL) // вставляем элемент
		{
			p_node->next = cursor->next;
			cursor->next = p_node;
		}
		else
		{
			printf("Нет такого узла\n");
		}
	}
	
}

/* вставка в список после узла со значением поля number=val */
void insertback(List* list, int val)
{
	Node* p_node = (Node*)malloc(sizeof(Node));
	p_node->number = val + 1;
	p_node->next = NULL;
	printf("Введите данные:\n>");
	scanf("%s", &p_node->name);

	// поиск узла со значением val
	Node* cursor = list->head;
	while (cursor != NULL) 
	{
		if (cursor->number == val)
			break;
		cursor = cursor->next;
	}

	if (cursor != NULL)
	{
		if (list->head == cursor) // если условие выполняется в начале списка
		{
			p_node->next = list->head->next;
			list->head->next = p_node;

		}
		else
			cursor->next = p_node;
	}
	else
	{
		printf("Нет такого узла");
	}
}

/* вставка в список перед узлом со значением поля name=str */
void insertfront_str(List* list, char* str)
{
	Node* p_node = (Node*)malloc(sizeof(Node));
	printf("Введите данные:\n>");
	scanf("%s", &p_node->name);

	// поиск узла со значением val
	Node* cursor = list->head;
	if (!strcmp(list->head->name, str))
	{
		p_node->number = 0; // тк рассматриваем начало списка, где num=1, то предыдущий элемент должен быть 0
		list->head->next = NULL;
		p_node->next = list->head;
		list->head = p_node;
	}
	else
	{
		while (cursor->next != NULL)
		{
			if (!strcmp(cursor->next->name, str))
				break;
			cursor = cursor->next;
		}

		if (cursor->next != NULL)
		{
			p_node->number = cursor->next->number - 1;
			p_node->next = cursor->next;
			cursor->next = p_node;
		}
		else
		{
			printf("Нет такого узла\n");
		}
	}

}

/* вставка в список после узла со значением поля number=val */
void insertback_str(List* list, char* str)
{
	Node* p_node = (Node*)malloc(sizeof(Node));
	p_node->next = NULL;
	printf("Введите данные:\n>");
	scanf("%s", &p_node->name);

	// поиск узла со значением val
	Node* cursor = list->head;
	while (cursor != NULL)
	{
		if (!strcmp(cursor->name, str))
			break;
		cursor = cursor->next;
	}

	if (cursor != NULL)
	{
		if (list->head == cursor)
		{
			p_node->number = 2;
			p_node->next = list->head->next;
			list->head->next = p_node;

		}
		else
		{
			p_node->number = cursor->number + 1;
			cursor->next = p_node;
		}
	}
	else
	{
		printf("Нет такого узла");
	}
}

/* проверяет, является ли список пустым*/
_Bool isempty(List* list)
{
	if (list->head) return 1;
	else return 0;
}

/* определение длины списка */
int length(List list)
{
	Node* p_node = list.head;
	int k = 0;
	while (p_node)
	{

		p_node = p_node->next;
		k++;
	}
	return k;
}

/* удаление заданного узла node из списка */
void destroyItem(List* list, Node node)
{
	Node* cursor = list->head;
	while (cursor != NULL)
	{
		if (cursor->next->next == node.next)
		{
			cursor->next = node.next;
			break;
		}
		cursor = cursor->next;
	}
}

/* нахождение узла со значением n в поле number*/
Node getitem(List list, int n)
{
	Node* cursor = list.head;
	while (cursor != NULL)
	{
		if (cursor->number == n)
			break;
		cursor = cursor->next;
	}
	return *cursor;
}

/* нахождение узла со значением str в поле name*/
Node getitem_str(List list, char* str)
{
	Node* cursor = list.head;
	while (cursor != NULL)
	{
		if (!strcmp(cursor->name, str))
			break;
		cursor = cursor->next;
	}
	return *cursor;
}