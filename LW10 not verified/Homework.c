#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

/* Программа, которая для [прямоугольника, треугольника, прямоугольного треугольника] предлагает меню выбора одной из операций:
1) рассчитать площадь;
2) вывести определение фигуры;
3) нарисовать фигуру.*/

float area_rectangle(float a, float b) {
	float result;
	result = a * b;
	return result;
}

void draw_rectangle(int a, int b) {
	for (int row = 1; row <= a; row++) {
		for (int col = 1; col <= b; ++col) printf("*");
		printf("\n");
	}
}

float area_triangle(float a, float b, float c) {
	float result, p;
	p = (a + b + c) / 2;
	result = sqrt(p * (p - a) * (p - b) * (p - c));
	return result;
}

void draw_triangle(int a) {
	int k = 1;
	for (int row = 1; row <= a; row++) {
		for (int col = 1; col <= a && col <= k; ++col) printf("*");
		printf("\n");
		k++;
	}
}

float area_r_triangle(float a, float b) {
	float result;
	result = 0.5 * a * b;
	return result;
}

void name(int a) {
	if (a == 3) puts("Треугольник");
	else puts("Прямоугольник");
}

void main() {
	setlocale(LC_ALL, "RUS");
	char c;

	while(1) {
		char figure;
		printf("Какую фигуру хотите выбрать? Введите соответствующий символ:\n\
	Прямоугольник - p;\n\
	Треугольник - t; \n\
	Прямоугольный треугольник - r.\n");
		scanf(" %c", &figure);
		if (figure != 'p' && figure != 't' && figure != 'r') { puts("Введите правильный символ\n"); continue; }
		printf("\n");

		while(1) {
			int operation;
			printf("Какую операцию произвести? Введите соответствующий символ:\n\
	Рассчитать площадь - 1;\n\
	Вывести определение фигуры - 2;\n\
	Нарисовать фигуру - 3.\n");
			scanf("%d", &operation);
			if (operation < 1 || operation > 3) { puts("Введите правильный символ\n"); continue; }
			printf("\n");

		
			switch (figure) {
			case 'p':
				switch (operation) {
				case 1: {
					float a, b;
					puts("Введите значения сторон a и b:");
					scanf("%f%f", &a, &b);
					float result = area_rectangle(a, b);
					printf("S = %f\n", result); 
					printf("\n");
					break;
				}
				case 2: {
					name(4);
					printf("\n");
					break;
				}
				case 3: {
					int a, b;
					puts("Введите значения сторон a и b:");
					scanf("%d%d", &a, &b);
					draw_rectangle(a, b);
					printf("\n");
					break;
				}
				}
				break;


			case 't':
				switch (operation) {
				case 1: {
					float a, b, c;
					puts("Введите значения сторон a, b, c:");
					scanf("%f%f%f", &a, &b, &c);
					float result = area_triangle(a, b, c);
					printf("S = %f\n", result);
					printf("\n");
					break;
				}
				case 2: {
					name(3);
					printf("\n");
					break;
				}
				case 3: {
					int a;
					puts("Введите значения стороны a (будет нарисован правильный треугольник):");
					scanf("%d", &a);
					draw_triangle(a);
					printf("\n");
					break;
				}
				}
				break;
		

			case 'r':
				switch (operation) {
				case 1: {
					float a, b;
					puts("Введите значения сторон a и b:");
					scanf("%f%f", &a, &b);
					float result = area_r_triangle(a, b);
					printf("S = %f\n", result);
					printf("\n");
					break;
				}
				case 2: {
					name(3);
					printf("\n");
					break;
				}
				case 3: {
					int a;
					puts("Введите значения стороны a (будет нарисован правильный треугольник):");
					scanf("%d", &a);
					draw_triangle(a);
					printf("\n");
					break;
				}
				}
				break;
			}
			
			puts("Сменить фигуру? (Да - y, нет - любой символ)");
			scanf(" %c", &c);
			if (c == 'y') break;
			printf("\n");
		}
		puts("Выйти из программы? (Да - y, нет - любой символ)");
		scanf(" %c", &c);
		if (c == 'y') break;
		printf("\n");
	}
}