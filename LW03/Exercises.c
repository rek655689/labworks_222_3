#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#define D_a 2.54
#define D_i 2.32166

void main1()
{
	setlocale(LC_ALL, "RUS");

	int num1, num2;
	puts("Введите числа");
	scanf("%d%d", &num1, &num2);
	printf("Сумма: %d, разность: %d, произведение: %d, частное: %d, остаток: %d", num1 + num2, num1 - num2, num1 * num2, num1 / num2, num1 % num2);

	int dym;
	float result;
	puts("Введите данные для расчёта");
	scanf("%d", &dym);
	result = D_a * dym;
	printf("%d английских дюймов - это %.1f см", dym, result);

	puts("Введите данные для расчёта");
	scanf("%d", &dym);
	result = D_i * dym;
	printf("%d испанских дюймов - это %.1f см", dym, result);

}