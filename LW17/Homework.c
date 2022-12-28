#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
/*
Задание 3.  Проведите вычислительный эксперимент:
сравнение быстрых сортировок (Шелла, быстрая Хоара и слиянием) с функцией стандартной библиотеки sort()
для различных размеров выборок  1000, 10000 целочисленных значений
*/
int* full_array(int* p_arr, int n);
int* sort_shell(int* p_arr, int n);
int* sort_hoar(int* ptrarr, int first1, int last1);
int* sort_merge(int* a, int n);

void main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);
    int* p_arr;
    clock_t t;
    double time;

    // сортировка с кол-вом от 1000 до 9999
    int size1 = 1000 + rand() % (9999 - 1000 + 1);
    printf("Кол-во значений: %d\n", size1);
    int* array1 = (int*)malloc(size1 * sizeof(int));

    p_arr = full_array(array1, size1);
    t = clock();
    p_arr = sort_shell(p_arr, size1);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Шелла: %lf\n", time);

    p_arr = full_array(array1, size1);
    t = clock();
    p_arr = sort_hoar(p_arr, 0, size1-1);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Быстрая Хоара: %lf\n", time);

    p_arr = full_array(array1, size1);
    t = clock();
    p_arr = sort_merge(p_arr, size1);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Слиянием: %lf\n", time);


    // сортировка с кол-вом от 50000 до 100000
    int size2 = 50000 + rand() % (100000 - 50000 + 1);
    printf("\nКол-во значений: %d\n", size2);
    array1 = (int*)realloc(array1, size2 * sizeof(int));

    p_arr = full_array(array1, size1);
    t = clock();
    p_arr = sort_shell(p_arr, size1);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Шелла: %lf\n", time);

    p_arr = full_array(array1, size1);
    t = clock();
    p_arr = sort_hoar(p_arr, 0, size1 - 1);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Быстрая Хоара: %lf\n", time);

    p_arr = full_array(array1, size1);
    t = clock();
    p_arr = sort_merge(p_arr, size1);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Слиянием: %lf\n", time);
    
    free(array1);
}

int* sort_shell(int* p_arr, int n)
{
    int i, j, step, temp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            temp = p_arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (temp < p_arr[j - step])
                    p_arr[j] = p_arr[j - step];
                else
                    break;
            }
            p_arr[j] = temp;
        }
    return p_arr;
}

int* sort_hoar(int* p_arr, int first1, int last1) {
    int mid = (first1 + last1) / 2;
    int temp, base = p_arr[mid];
    int first = first1, last = last1;
    while (first < last)
    {

        while (p_arr[first] < base) first++;
        while (p_arr[last] > base) last--;
        if (first <= last) {

            temp = p_arr[first];
            p_arr[first] = p_arr[last];
            p_arr[last] = temp;
            first++;
            last--;
        }

    }
    if (first1 < last) sort_hoar(p_arr, first1, last);
    if (last1 > first) sort_hoar(p_arr, first, last1);
    return p_arr;
}


int* sort_merge(int* p_arr, int n)
{
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int* c = (int*)malloc(n * sizeof(int));
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
              // заполняем следующий элемент формируемой последовательности
              // меньшим из двух просматриваемых
                if (p_arr[i] < p_arr[j])
                {
                    c[k] = p_arr[i];
                    i++; k++;
                }
                else {
                    c[k] = p_arr[j];
                    j++; k++;
                }
            }
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = p_arr[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = p_arr[j];
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i < n; i++)
            p_arr[i] = c[i];
    }
    return p_arr;
}