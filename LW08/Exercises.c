#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

float func(float x) {
	float result = 1.8 * pow(x, 2) - sin(10 * x);
	return result;
}

void main() {
	setlocale(LC_ALL, "RUS");

	/*// ЗАДАНИЕ 0. Напечатайте 10 символов '*' с использованием цикла for
	for (int start = 1; start <= 10; start++) putchar('*');
	puts("\n");

	// + возможность ввода количества и вида символов
	int k;
	char c;
	puts("Введите символ");
	c = getchar();
	puts("Введите количество символов");
	scanf("%d", &k);
	for (int start = 1; start <= k; start++) putchar(c);
	puts("\n");

	// *) напечатайте в начале и\или в конце символ '+'
	puts("Введите символ");
	scanf("\n%c", &c);  // \n так как в буфер ввода попал перенос строки
	puts("Введите количество символов");
	scanf("%d", &k);
	printf("+");
	for (int start = 1; start <= k; start++) putchar(c);
	printf("+");
	puts("\n");

	// **) напечатайте полстроки одним символом, а вторую половину другим
	char c1;
	puts("Введите первый символ");
	scanf("\n%c", &c);
	puts("Введите второй символ");
	scanf("\n%c", &c1);
	puts("Введите количество символов");
	scanf("%d", &k);
	for (int start = 1; start <= k / 2; start++) putchar(c);
	for (int start = (k / 2) + 1; start <= k; start++) putchar(c1);
	puts("\n");

	// ***) печатайте после каждого символа восклицательный знак!
	puts("Введите символ");
	scanf("\n%c", &c);
	puts("Введите количество символов");
	scanf("%d", &k);
	for (int start = 1; start <= k; start++) printf("%c!", c);
	puts("\n");
	
	
	// ЗАДАНИЕ 1. Вычисление суммы целых чисел от m до n (включительно)
	int m, n, s = 0;
	puts("Введите целые значения m и n");
	scanf("%d%d", &m, &n);
	for (int i = n; i >= m; i--)
	{
		s += i;
		printf("выполнено %d раз\n", i + 1);
	}
	printf("Результат = %d", s);
	puts("\n");
	
	*/
	// ЗАДАНИЕ 2. Табулирование функции с произвольным шагом
	puts("f(x) = 1.8x^2 - sin10x");

	float step;
	puts("Введите значение шага табуляции");
	scanf("%f", &step);

	puts("___________________________");
	printf("| %-10s | %-10s |\n", "x", "f(x)");
	puts("|------------|------------|");
	for (float i = 0.2; i <= 2.2; i += step) {
		printf("| %10.3f | %10.3f |\n", i, func(i));
	}
	puts("|------------|------------|");
}