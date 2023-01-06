#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

float calculate(float a, float n) {
	float result = 0, d = 1;
	for (int i = 0; i <= n; i++)
	{
		d *= (a + i);
		result += 1 / d;
	}
	return result;
}

void main1() {
	setlocale(LC_ALL, "RUS");

	float a, n;
	puts("Введите значения a и n");
	scanf("%f%f", &a, &n);

	float result = calculate(a, n);
	printf("%f", result);
}
