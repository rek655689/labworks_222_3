#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 10

float func(float x)   // к заданию 2
{
    float y;
    y = 1.8f * (float)pow(x, 2) - (float)sin(10 * x);
    return y;
}

void main1()
{
	setlocale(LC_ALL, "RUS");
    
	// ЗАДАНИЕ 1. Реализуйте программу работы с массивом по плану
	float A[N];
    float temp;
    for (int i = 0; i < N; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }

    // 3. обнулить отрицательные элементы массива
    printf("\n-----------------------------------------------\n"
           "| индекс | исходное значение | новое значение |\n"
           "-----------------------------------------------\n");
    for (int i = 0; i < N; i++)
    {
        printf("| %6d | %17.4f | ", i, A[i]);
        if (A[i] < 0) A[i] = 0;
        printf("%14.4f |\n", A[i]);
    }
    printf("-----------------------------------------------\n");

    // среднее арифметическое элементов массива
    float sum = 0;
    for (int i = 0; i < N; i++) sum += A[i];
    float average = sum / N;
    printf("Среднее арифметическое массива A[%d] = %g\n", N, average);
    puts("\n");

    
    // ЗАДАНИЕ 2. Сгенерируйте массив из 100 вещ. значений, вычисленных по функции y=1.8x^2-sin10x и интервалу [0.2; 2.2] (зад.2 работа 8)
    float B[100];
    float step = (2.2f - 0.2f) / 100;   // получаем шаг, с которым нужно идти по интервалу, чтобы получить из него 100 значений
    float current_step = 0.2f;
    for (int i = 0; i < 100; i++, current_step += step) B[i] = func(current_step);

    // вычислите среднее значение всех положительных элементов массива
    float sum_positive = 0, sum_negative = 0;
    int count_positive = 0, count_negative = 0;
    for (int i = 0; i < 100; i++)
    {
        if (B[i] > 0)
        {
            sum_positive += B[i];
            count_positive++;
        }
        else
        {
            sum_negative += B[i];
            count_negative++;
        }
    }
    float average_positive = sum_positive / count_positive;
    float average_negative = sum_negative / count_negative;
    printf("Массив B[100]:\n"
           "    - положительные числа\n");
    printf("        сумма: %f\n", sum_positive);
    printf("        количество: %d\n", count_positive);
    printf("        среднее арифметическое: %f\n", average_positive);
    printf("    - отрицательные числа\n");
    printf("        сумма: %f\n", sum_negative);
    printf("        количество: %d\n", count_negative);
    printf("        среднее арифметическое: %f\n", average_negative);
}