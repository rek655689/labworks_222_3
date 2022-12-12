#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 40

// подсчитывает количество слов, длина которых не превышает 3 символов

void main1()
{
	setlocale(LC_ALL, "RUS");

	char str[N];
	int count = 0;
	int temp_count = 0;
	printf("¬ведите строку: ");
	fgets(str, N, stdin);

	for (int i = 0; i < N; i++)
	{
		if ((str[i] != ' ') && (str[i] != '\n'))
		{
			temp_count++;
		}
		else
		{
			if (temp_count <= 3)
				count++;
			temp_count = 0;
		}
	}
	printf("%d", count);
}