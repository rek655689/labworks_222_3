#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#define humans_count 4

float calculate_tips(int bill)
{
	int sum;
	float tips;
	sum = humans_count * bill;
	tips = sum * 0.15f;
	return tips;
}

void main(void)
{
	setlocale(LC_ALL, "RUS");

	int bill;
	float tips;

	puts("������� ������ ����� �� ������� ��������:");
	scanf("%d", &bill);

	tips = calculate_tips(bill);

	printf("������ ���������� %d ���. %d ���.", (int)tips, (int)((tips - (int)tips) * 100));
}