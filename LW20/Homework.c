#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define N 30

/* Считать текстовый файл winter.txt и выполнить над текстом преобразование, полученный вариант текст записать
 вновый файл с именем, указанным пользователем
	3. Заменить пробелами все буквы о, а буквы o на пробелы */

void main()
{
	setlocale(LC_ALL, "RUS");
	FILE* file, * new_file;
	char name[N+4], str[N];
	printf("Укажите название нового текстового файла (без расширения):\n>");
	fgets(name, N, stdin);
	for (int i = 0; i < N - 1; i++)
	{
		if (name[i] == '\n')
			name[i] = name[i + 1];
	}
	strcat(name, ".txt");
	if ((file = fopen("winter.txt", "rt")) == NULL)
	{
		printf("Ошибка открытия файла winter.txt");
		exit(-1);
	}
	if ((new_file = fopen(name, "wt")) == NULL)
	{
		printf("Ошибка открытия файла %s", name);
		exit(-1);
	}
	while (!feof(file))
	{
		fgets(str, N, file);
		for (int i = 0; i < N; i++)
		{
			if (str[i] == 'o')
			{
				str[i] = ' ';
				continue;
			}
			if (str[i] == ' ')
				str[i] = 'o';
		}
		fprintf(new_file, "%s", str);
	}
	fclose(file);
	fclose(new_file);
	printf("Программа завершена");
}
