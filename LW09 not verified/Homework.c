#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>


// ������������� �����������
void main()
{
	setlocale(LC_ALL, "RUS");

	char s;
	int a, b;
	puts("������� ������");
	scanf("%c", &s);
	puts("������� �������� �������");
	scanf("%d%d", &a, &b);
	puts("\n");

	int incr = ceil((double)b / a); // ���������� ��������� ��������
	int skips = ceil((double)a / b);  // �� ������� ����� �� ����������� ���-�� ��������
	int count_columns = 1;
	for (int row = 1; row <= a; row++)
	{
		for (int col = 1; (col <= count_columns) && (col <= b); col++) printf("%c", s);
		if ((row - 1) % skips == 0) count_columns += incr;
		printf("\n");
	}
}	
