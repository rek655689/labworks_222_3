#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#define N 50
#define K 7
#define MIN -10
#define MAX 10

void add(int b[][K], int row, int col);
void print_arr(int b[][K], int row, int col);
void transp(int b[][K], int row, int col);

void main1()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL) / 2);
	// ЗАДАНИЕ 1.  Создать и заполнить статический двухмерный массив, размерность которого задается пользователем
	//				элемент массива - 3) значение, целая часть которого первый индекс, дробная - второй индекс;
	float a[N][N];
	int row, col;
	printf("Введите количество строк и количество столбцов (не более 50):\n>");
	scanf("%d%d", &row, &col);
	if (row > 50 || col > 50)
		exit(-1);
	printf("     ");
	for (int i = 0; i < col; i++)
		printf("%d      ", i);
	printf("\n----------------------------------------------------------------------------------\n");
	for (int i = 0; i < row; i++)
	{
		printf("%d| ", i);
		for (int j = 0; j < col; j++)
		{
			a[i][j] = i + (j / 100.f);
			printf("%.2f   ", a[i][j]);
		}
		printf("\n");
	}
	// Отдельно вывести элемент, расположенный:  3) в правом нижнем углу массива.
	printf("\nПравый нижний угол: %.2f\n", a[row-1][col-1]);

	// Найти в) заданное значение среди элементов, лежащих на диагонали
	float x;
	int res;
	printf("Индекс какого значения найти? (должно лежать на диагонали)\n>");
	scanf("%f", &x);
	res = (int)ceil((x - (int)x)*100);
	if ((int)x != res)
	{
		printf("Значение должно лежать на диагонали\n");
	}
	else
		printf("Индекс значения %.2f: %d строка %d столбец\n", x, res, res);


	// ЗАДАНИЕ 2. Программа, которая формирует двумерный массив целых чисел от -10 до 10 (7 на 7) и транспонирует его
	int b[K][K];
	printf("Было:\n");
	add(b, K, K);
	print_arr(b, K, K);
	printf("Стало:\n");
	transp(b, K, K);

}

void add(int b[][K], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			b[i][j] = MIN + rand() % (MAX - MIN + 1);
		}
	}
}

void print_arr(int b[][K], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%3d      ", b[i][j]);
		}
		printf("\n");
	}
}

void transp(int b[][K], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%3d      ", b[j][i]);
		}
		printf("\n");
	}
}