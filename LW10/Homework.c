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
	result = (float)sqrt(p * (p - a) * (p - b) * (p - c));
	return result;
}

void draw_triangle(int a) {
	int k = 1;
	for (int row = 1; row <= a; row++) {
		for (int col = 1; col <= a && col <= k; ++col) printf("*");
		printf("\n");
		k++;
	}

}void draw_r_triangle(int a, int b) {
	int incr = (int)ceil((double)b / a); // приращение выводимых символов
	int skips = (int)ceil((double)a / b);  // по сколько строк не увеличивать кол-во символов
	int count_columns = 1;
	for (int row = 1; row <= a; row++)
	{
		for (int col = 1; (col <= count_columns) && (col <= b); col++) printf("%c", '*');
		if ((row - 1) % skips == 0) count_columns += incr;
		printf("\n");
	}
}

float area_r_triangle(float a, float b) {
	float result;
	result = 0.5f * a * b;
	return result;
}


void main() {
	setlocale(LC_ALL, "RUS");
	char c = 'a';  // чтобы не ругался на сравнение с неинициализированной переменной

	while (c != 'y') {
		char figure;
		printf("Какую фигуру хотите выбрать? Введите соответствующий символ:\n\
	Прямоугольник - p;\n\
	Треугольник - t; \n\
	Прямоугольный треугольник - r.\n");
		scanf(" %c", &figure);
		printf("\n");

		while (c != 'y') {
			int operation;
			printf("Какую операцию произвести? Введите соответствующий символ:\n\
	Рассчитать площадь - 1;\n\
	Вывести определение фигуры - 2;\n\
	Нарисовать фигуру - 3.\n");
			scanf("%d", &operation);
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
					puts("Прямоугольник");
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
				default:
					puts("Введите правильный символ\n");
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
					puts("Треугольник");
					printf("\n");
					break;
				}
				case 3: {
					int a;
					puts("Введите значения стороны a:");
					scanf("%d", &a);
					draw_triangle(a);
					printf("\n");
					break;
				}
				default:
					puts("Введите правильный символ\n");
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
					puts("Треугольник");
					printf("\n");
					break;
				}
				case 3: {
					int a, b;
					puts("Введите значения сторон a и b:");
					scanf("%d%d", &a, &b);
					draw_r_triangle(a, b);
					printf("\n");
					break;
				}
				default:
					puts("Введите правильный символ\n");
				}
				break;

			default:
				puts("Введите правильный символ\n");
			}

			puts("Сменить фигуру? (Да - y, нет - любой символ)");
			scanf(" %c", &c);
			printf("\n");
		}
		puts("Выйти из программы? (Да - y, нет - любой символ)");
		scanf(" %c", &c);
		printf("\n");
	}
}