#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "list.h"

void print_l(List* list)
{
	Node* p = list->head;
	printf("Список узлов:\n");
	while (p != NULL) {
		printf("Узел %d\n", p->number);
		p = p->next;
	}
}

Node find_elem(List list)
{
	Node* cursor = list.head;
	while (cursor != NULL)
	{
		if (cursor->number > 0)
			break;
		cursor = cursor->next;
	}
	return *cursor->next;
}

void delete_elem(List* list, Node node)
{
	Node* cursor = list->head;
	while (cursor != NULL)
	{
		if (cursor->next->number == node.number)
		{
			cursor->next = node.next;
			break;
		}
		cursor = cursor->next;
	}
}

void main1()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);
	// Создать линейный однонаправленный список из 10 целых чисел. Удалить из списка элемент после первого элемента с положительным значением.
	List list;
	Node temp, *cur;
	temp.number = 1;
	temp.next = NULL;
	list.head = &temp;
	cur = &temp;
	for (int i = 2; i <= 10; i++)
	{
		Node* p_node = (Node*)malloc(sizeof(Node));
		p_node->number = -100 + rand() % (100 - (-100) + 1);
		p_node->next = NULL;
		cur->next = p_node;
		cur = p_node;
	}
	print_l(&list);
	printf("\n");
	Node elem = find_elem(list);
	delete_elem(&list, elem);
	print_l(&list);
}