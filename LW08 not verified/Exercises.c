﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void main1(void) {
	setlocale(LC_ALL, "RUS");

	// задание 1
	int n, m, s = 0;
	puts("Введите значения m и n");
	scanf("%d%d", &m, &n);
	for (int i = n; i >= m; s += i, i--); 
	printf("результат №1 - %d\n", s);

	// задание 2
	s = 0;
	for (int i = n; i >= m; i--, s += i); // добавились значения, каждое из которых на единицу меньше
	printf("результат №2 - %d\n", s);

	// задание 3
	s = 0;
	for (int i = n; i >= m;) {
		i--;
		s += i;
	}
	printf("результат №3 - %d\n", s);

	// задание 4: через while
	s = 0;
	int i = n;
	while (i >= m) {
		i--;
		s += i;
	}
	printf("результат №4 - %d\n", s);

	// задание 5: через do-while
	s = 0;
	i = n;
	do
	{
		i--;
		s += i;
	}
	while (i >= m);
	printf("результат №5 - %d\n", s);

}