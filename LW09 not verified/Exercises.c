#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define ROW 9
#define COL 9

void main1()
{
	setlocale(LC_ALL, "RUS");

	// ������� 1.  ��������� ������ ������� ��������
	int row, col;
	printf("\n");
	for (row = 1; row <= ROW; ++row)
	{
		for (col = 1; col <= COL; col++) printf("%5d", col * row);
		printf("\n");
	}
	puts("\n");

	// 1.2 ������ ����� ������ �����������
	int count_columns = 1;
	for (row = 1; row <= ROW; ++row)
	{
		for (col = 1; col <= COL; col++)
		{
			if (col > count_columns) continue; 
			printf("%5d", col * row);
		}
		count_columns++;
		printf("\n");
	}
	puts("\n");

	// 1.3 ������ 41..50 41...71 (3 �������)
	for (row = 40; row <= 70; row = row + 10)
	{
		for (col = 1; col <= 10; col++) printf("%5d", row + col);
		printf("\n");
	}
	puts("\n");



	// ������� 2.  ��������� ���������� ������������� �������� ����� �� ����� ��� �����������:
	char a;
	int original_x;
	puts("������� x");
	scanf("%d", &original_x);
	a = getchar();  // ������� ������ �������� ������, ������� ���� ����� scanf
	printf("\n");

	while (1)
	{

	// 1) ���������� ���� 3 � ���
		int count_digits = 0, x = original_x;
		do
		{
			if (x % 10 == 3) count_digits++;
			x /= 10;
		} while (x > 0);
		printf("1. ���������� ���� 3: %d\n", count_digits);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 2) ����� ���������� ��������� ����� � �����
		count_digits = 0, x = original_x;
		int last_digit = x % 10;
		do
		{
			if (x % 10 == last_digit) count_digits++;
			x /= 10;
		} while (x > 0);
		printf("2. ���������� ���� %d: %d\n", last_digit, count_digits);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 3) ���������� ������ ����
		count_digits = 0, x = original_x;
		do
		{
			if ((x % 10) % 2 == 0) count_digits++;
			x /= 10;
		} while (x > 0);
		printf("3. ���������� ������ ����: %d\n", count_digits);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 4) ���������� ���� ������ 5
		count_digits = 0, x = original_x;
		do
		{
			if ((x % 10) > 5) count_digits++;
			x /= 10;
		} while (x > 0);
		printf("4. ���������� ���� ������ 5: %d\n", count_digits);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 5) ����� �������� ����
		x = original_x;
		int sum = 0;
		do
		{
			if ((x % 10) % 2 != 0) sum += (x % 10);
			x /= 10;
		} while (x > 0);
		printf("5. ����� �������� ����: %d\n", sum); 
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;


	// 6) ����� ���� ������ ��� ����� 7
		sum = 0, x = original_x;
		do
		{
			if ((x % 10) >= 7) sum += (x % 10);
			x /= 10;
		} while (x > 0);
		printf("6. ����� ����, ������� ������ ��� ����� 7: %d\n", sum);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 7) ������������ ���� ����, �������� 0
		x = original_x;
		int product = 1;
		do
		{
			if ((x % 10) != 0) product *= (x % 10);
			x /= 10;
		}
		while (x > 0);
		printf("7. ������������ ���� ����, �������� 0: %d\n", product);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 8) ������������ ������������� � ������ ����� �����
		product = 1, count_digits = 0, x = original_x;
		do
		{
			count_digits++;
			x /= 10;
		} while (x > 0);
		x = original_x;
		product = ((x % 100) / 10) * ((x / (int)pow(10, count_digits - 2)) % 10);
		printf("8. ������������ ������������� � ������ ����� �����: %d\n", product);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 9) ����� ������ ����, �������� ���������
		sum = 0, x = original_x;
		x /= 10;
		do
		{
			if ((x % 10) % 2 == 0 ) sum += x % 10;
			x /= 10;
		}
		while (x > 0);
		printf("9. ����� ������ ����, �������� ���������: %d\n", sum);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 10) ����� ������������� ���������� �����
		count_digits = 0, x = original_x;
		int last;
		do
		{
			last = x % 10;
			x /= 10;
			if ((x % 10) == last) count_digits++;
		} while (x > 0);
		count_digits = count_digits > 0 ? ++count_digits : count_digits; // ���������� 1, �� ������� ���-�� ����������, � �� ����
		printf("10. ���-�� ����� ������������� ���������� ����: %d\n", count_digits);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	// 11) ����� �� ����� ������ � ������ �������� ���� �����
		count_digits = 0, x = original_x;
		int first_sum = 0, second_sum = 0;
		do
		{
			count_digits++;
			x /= 10;
		} while (x > 0);

		if (count_digits % 2 != 0) puts("��� ����� ������� ���-�� ���� ������ ���� ������");
		else {
			x = original_x;
			for (int i = 1; i <= count_digits / 2; i++)
			{
				second_sum += x % 10;
				x /= 10;
			}
			for (int i = 1; i <= count_digits / 2; i++)
			{
				first_sum += x % 10;
				x /= 10;
			}
			printf("11. ����� �� ����� ������ � ������ �������� ���� �����? %s\n", first_sum == second_sum ? "��" : "���");
		}
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;

	
	// 12) ������������ ���� ���� ������ � �������� �������� (������� ������ - 1)
		count_digits = 0, first_sum = 0, second_sum = 0, product = 1; x = original_x;
		do
		{
			count_digits++;
			x /= 10;
		} while (x > 0);

		x = original_x;
		for (int i = 1; i <= count_digits; ++i)
		{
			if (i % 2 == 0) first_sum += (x % 10);
			else second_sum += (x % 10);
			x /= 10;
		}
		product = first_sum * second_sum;
		printf("12. ������������ ���� ���� ������ � �������� ��������: %d\n", product);
		printf("����������? (�� - ����� �������, ��� - n)\n");
		if ((a = getchar()) == 'n') break;
	}
	
}