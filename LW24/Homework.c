#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define LEN 80

// 3. Напечатать текстовый файл, расположив слова в строках в обратном порядке.

typedef struct Stack
{
	char* data;
	struct Stack* next;
} fstack;
typedef struct {
	fstack* stack;
	fstack* top;
} stack_list;
int add(stack_list* s, char* a);
void print_stack(stack_list* s);

void main()
{
	setlocale(LC_ALL, "RUS");
	FILE* file;
	stack_list s;
	s.top = NULL;
	char str[LEN];
	char* word = malloc(1);
	int c = 0;
	if ((file = fopen("text.txt", "r")) == NULL)
	{
		printf("Ошибка открытия файла");
		exit(-1);
	}
	while (!feof(file))  // идём до конца файла
	{
		fgets(str, LEN, file);  // считываем строку
		for (int i = 0; i < LEN - 1 && str[i] != '\0'; i++)  // идём по символам строки, накапливая слово, где 'c' показывает индекс последнего заплненной ячейки
		{
			if (str[i] != ' ' && str[i] != '\n')
			{
				word = (char*)realloc(word, (c + 1) * sizeof(char));
				word[c] = str[i];
				c++;
				continue;
			}
			word[c] = '\0';
			add(&s, word);
			word = malloc(1);
			c = 0;
		}
		print_stack(&s);
		s.top = NULL;
	}
	free(word);
}

//поместить элемент а в стек  {top=top+1, data[top]=a}, если стек не полон
int add(stack_list* s, char* a)
{
	fstack* node = malloc(sizeof(fstack));
	node->data = a;
	if (s->top == NULL)
	{
		node->next = NULL;
		s->top = node;
	}
	else
	{
		node->next = s->top;
		s->top = node;
	}	
	return 1;
}

// вывод стека
void print_stack(stack_list* s) {
	fstack* p;
	p = s->top;
	while (p != NULL)
	{
		printf(" %s ", p->data);
		p = p->next;
	}
	printf("\n");
}