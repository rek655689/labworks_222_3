#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 40

void main()
{
	// ������� 1.  �������� ���������, ������� ����������� ��� ������������ � ����������� � ���, ��������� �������� ���.
	char name[20];
	char hello[N] = "Hello, ";
	printf("Enter your name: ");
	scanf("%s", &name);
	strcat(hello, name);
	printf("%s!\n\n", hello);

	// 1.2 ���������� �������
	for (int i = 0; i < N; i++)
	{
		hello[i] = toupper(hello[i]);
	}
	printf("%s!\n\n", hello);

	// 1. 3�������� � ������ ����������� ��������� ��������������� ������ ���, ����� ��������� ����� ������ ���������� 40 ��������
	char s = '1';
	int len = strlen(hello);
	int k = N - len - 1; // ������� ��������� ����� ��������
	for (int i = 0; i < k; i++)
	{
		strcat(hello, "!");
	}
	printf("%s\n\n", hello);


	// ������� 2. 3) � ����� ��� ������ ����� �������� �������(��� ��������� �������� �����)
	char name2[20];
	char hello2[N] = "Hello, ";
	printf("Enter your name: ");
	scanf("%s", &name2);
	char temp = name2[0];
	name2[0] = name2[1];
	name2[1] = temp;
	strcat(hello2, name2);
	printf("%s!\n\n", hello2);
}