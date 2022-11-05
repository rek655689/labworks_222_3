#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 10

/* С одномерным массивом из n вводимых положительных и отрицательных целых чисел высчитать:
	3. Сумму всех элементов массива, расположенных до последнего положительного элемента. */

void main()
{
	setlocale(LC_ALL, "RUS");
	
    int A[N];
    int x;
    int sum = 0, possible_sum = 0;
    for (int i = 0; i < N; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &x);
        A[i] = x;


        if (x > 0) {
            sum += possible_sum;
            possible_sum = 0;
        }
        possible_sum += x;
    }
    printf("Сумма элементов до последнего положительного = %d", sum);
}