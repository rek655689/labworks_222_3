#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void main1(void)
{

	// 1. Сделайте вывод о порядке размещения байтов в текущей системе. 
	int x = 0x12345678;
	int* prt = NULL;
	unsigned char* a1 = NULL, * a2 = NULL, * a3 = NULL, * a4 = NULL;
	unsigned char* a;

	prt = &x;
	a = (unsigned char*)prt;

	a1 = a + 3;
	a2 = a + 2;
	a3 = a + 1;
	a4 = a;
	printf("%.2x\n%.2x\n%.2x\n%.2x\n", *a1, *a2, *a3, *a4);
	// 12 34 56 78, поскольку мы выводили с конца, значит на деле байты идут от больше к меньшему => little-endian
	puts("\n");


	// 2. Побайтно выводить переменные любого типа
	double y = 234.234234;   // здесь меняем тип и значение переменной
	unsigned char* b = &y;
	for (int i = 0; i < (int)sizeof(y); i++)
	{
		printf("%.2x\n", *b);
		b++;
	}


	// 3. Сравните код числа  заданного переменными типа int, float и double 
	int ch_i = 12345.0;
	unsigned char* pi = &ch_i;
	for (int i = 0; i < (int)sizeof(ch_i); i++)
	{
		printf("%.2x ", *pi);
		pi++;
	}
	printf("\n");

	float ch_f = 12345.0;
	unsigned char* pf = &ch_f;
	for (int i = 0; i < (int)sizeof(ch_f); i++)
	{
		printf("%.2x ", *pf);
		pf++;
	}
	printf("\n");

	double ch_d = 12345.0;
	unsigned char* pd = &ch_d;
	for (int i = 0; i < (int)sizeof(ch_d); i++)
	{
		printf("%.2x ", *pd);
		pd++;
	}
	printf("\n");
}