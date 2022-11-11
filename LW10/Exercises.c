#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double fa(double x) {  // к заданию 1
	double y;
	if (x <= 3) y = pow(x, 2) - 3 * x + 9;
	else y = 1 / (pow(x, 3) + 3);
	return y;

}

double fb(double x) {  // к заданию 1
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}

double factorial(double a) {   // к заданию 2
	double result = 1;
	for (int i = 1; i <= a; i++) {
		result *= i;
	}
	return result;
}

double sin_n(double x, int N) {  // к заданию 2
	double y = 0;
	for (int k = 1; k <= N; k++) {
		y += pow(-1, k - 1) * ((pow(x, 2 * k - 1)) / factorial(2 * k - 1));
	}
	return y;
}

double sin_eps(double x, double eps) {  // к заданию 2
	double y = 0;
	double element;
	int k = 0;
	do
	{
		++k;
		element = pow(-1, k - 1) * ((pow(x, 2 * k - 1)) / factorial(2 * k - 1));
		y += element;
	} while (fabs(element) > eps);
	return y;
}

void main1() {
	setlocale(LC_ALL, "RUS");

	// ЗАДАНИЕ 1.  Программа вычисления произведения, разности квадратов и удвоенной суммы значений двух функций
	double x;
	puts("Введите значение x");
	scanf("%lf", &x);
	printf("fa(x)=%lf , fb(x)=%lf\n", fa(x), fb(x));
	printf("fa * fb = %lf, fa^2 - fb^2 = %lf, 2fa + 2fb = %lf", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));
	puts("\n");


	// ЗАДАНИЕ 2.  Программа вычисления sin(x) тремя различными способами
	// x = 5, N = 25, eps = 0,000001
	puts("Введите значение x");
	scanf("%lf", &x);
	int n;
	puts("Введите значение N - число суммируемых k-х членов ряда");
	scanf("%d", &n);
	double eps;
	puts("Введите точность вычисления (например, 0,000001)");
	scanf("%lf", &eps);

	double res_1 = sin(x);
	double res_2 = sin_n(x, n);
	double res_3 = sin_eps(x, eps);

	printf("sin(x) = %lg, sin_n(x) = %lg, sin_eps(x) = %lg", res_1, res_2, res_3);
}