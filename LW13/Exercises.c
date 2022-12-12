#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 40

void main()
{
	// ЗАДАНИЕ 1.  Напишите программу, которая запрашивает имя пользователя и здоровается с ним, используя введённое имя.
	char name[20];
	char hello[N] = "Hello, ";
	printf("Enter your name: ");
	scanf("%s", &name);
	strcat(hello, name);
	printf("%s!\n\n", hello);

	// 1.2 заглавными буквами
	for (int i = 0; i < N; i++)
	{
		hello[i] = toupper(hello[i]);
	}
	printf("%s!\n\n", hello);

	// 1. 3добавьте к строке приветствия множество восклицательных знаков так, чтобы суммарная длина строки составляла 40 символов
	char s = '1';
	int len = strlen(hello);
	int k = N - len - 1; // сколько свободных ячеек осталось
	for (int i = 0; i < k; i++)
	{
		strcat(hello, "!");
	}
	printf("%s\n\n", hello);


	// ЗАДАНИЕ 2. 3) В имени две первые буквы менялись местами(без изменения регистра ввода)
	char name2[20];
	char hello2[N] = "Hello, ";
	printf("Enter your name: ");
	scanf("%s", &name2);
	char temp = name2[0];
	name2[0] = name2[1];
	name2[1] = temp;
	strcat(hello2, name2);
	printf("%s!\n\n", hello2);
}