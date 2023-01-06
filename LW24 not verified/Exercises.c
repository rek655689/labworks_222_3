#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define NMAX 10
#define TYPE char
#define FTYPE "%3c,"

typedef struct  Stack {
	int   top;
	TYPE  data[NMAX];
} stack;
int isfull(stack* s);
int push(stack* s, TYPE a);
void display(stack* s);

struct Node {
	TYPE data;
	struct Node* next;
};
typedef struct {
	struct Node* queue;
	struct Node* front;
	struct Node* back;
} queue_list;
void enQueue(queue_list* que, TYPE element);
TYPE deQueue(queue_list* que);

void main1()
{
	setlocale(LC_ALL, "RUS");
	// ЗАДАНИЕ 1.  Реализуйте стек на массиве  в соответствии с предложенным ниже интерфейсом
	stack s;
	s.top = 0;
	char str[NMAX + 1];
	printf("Введите строку\n>");
	fgets(str, NMAX + 1, stdin);
	for (int i = 0; !isfull(&s); i++)
	{
		push(&s, str[i]);
	}
	display(&s);
	printf("\n\n");
	getc(stdin);

	// ЗАДАНИЕ 2. Реализуйте очередь на связанном списке в соответствии с предложенным ниже интерфейсом
	queue_list q;
	q.back = q.front = NULL;
	char str2[NMAX + 1];
	printf("Введите строку\n>");
	fgets(str2, NMAX + 1, stdin);
	for (int i = 0; i < NMAX && str2[i] != '\n' && str2[i]; i++)
	{
		enQueue(&q, str2[i]);
	}
	while (q.front)
	{
		printf(FTYPE, deQueue(&q));
	}
}

// проверить, если стек полон {top==NMAX-1} вернуть 1, иначе 0
int isfull(stack* s)
{
	if (s->top == NMAX)
		return 1;
	else 
		return 0;
}

//поместить элемент а в стек  {top=top+1, data[top]=a}, если стек не полон
int push(stack* s, TYPE a)
{
	s->top = s->top + 1;
	s->data[s->top] = a;
	return 0;
}

// вывод стека
void display(stack* s) {
	int i = s->top;
	while (i > 0)
		printf(FTYPE, s->data[i--]);
}

//добавить элемент в очередь
void enQueue(queue_list* que, TYPE element)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = element;
	node->next = NULL;
	if (que->back != NULL)
	{
		que->back->next = node;
		que->back = node;

	}
	else
	{
		que->back = node;
		que->front = node;
	}
}

//извлечь элемент из очереди
TYPE deQueue(queue_list* que)
{
	TYPE elem = ' ';
	if (que->front != NULL)
	{
		elem = que->front->data;
		que->front = que->front->next;
		return elem;
	}
	else
		que->back = NULL;
	return elem;
}