#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define N 10
#define XMAX 1000
#define XMIN -1000

/* С одномерным массивом из n вводимых положительных и отрицательных целых чисел высчитать:
    3. Сумму всех элементов массива, расположенных до последнего положительного элемента. */

void main()
{
    setlocale(LC_ALL, "RUS");
    int stime;
    stime = (unsigned long)time(NULL) / 2;
    srand(stime);

    // случайные целые числа (с возможностью отрицательных)
    int A[N];
    int x;
    int sum = 0, possible_sum = 0;
    for (int i = 0; i < N; i++)
    {
        x = XMIN + rand() % (XMAX - XMIN);
        A[i] = x;
        printf("%d\n", x);

        if (x > 0) {
            sum += possible_sum;
            possible_sum = 0;
        }
        possible_sum += x;
    }
    printf("Сумма элементов до последнего положительного = %d", sum);
    puts("\n");

    // случайные вещественные числа (с возможностью отрицательных)
    float B[N];
    float y;
    float fsum = 0, fpossible_sum = 0;
    for (int i = 0; i < N; i++)
    {
        y = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
        B[i] = y;
        printf("%g\n", y);

        if (y > 0) {
            fsum += fpossible_sum;
            fpossible_sum = 0;
        }
        fpossible_sum += y;
    }
    printf("Сумма элементов до последнего положительного = %g", fsum);
}