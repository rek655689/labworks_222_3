#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

// ������� �� ������ ����������

void main1(void)
{
	setlocale(LC_ALL, "RUS");
	
	// ������� 1
	float gr, r;
	puts("������� �������");
	scanf("%f", &gr);
	r = gr * M_PI / 180;
	printf("%g ���� = %.6f", gr, sin(r));
	
	// ������� 2
	int k1 = 8, k2 = 16, k3 = 32, k4 = 64, k5 = 128;
	printf("��� k = 8: %lg\n", pow(2.f, k1));
	printf("��� k = 16: %lg\n", pow(2.f, k2));
	printf("��� k = 32: %lg\n", pow(2.f, k3));
	printf("��� k = 64: %lg\n", pow(2.f, k4));
	printf("��� k = 128: %lg\n", pow(2.f, k5));
	
	// ������� 3 
	double x;
	puts("������� �������� x");
	scanf("%lf", &x);
	float p = 0.5;
	double a = log(pow(p, 2) + pow(x, 3));
	double b = exp(sqrt(fabs(x)));
	double y = pow(a, 3) / pow(b, 2);
	printf("x = %lg, y = %.4lf", x, y);
}