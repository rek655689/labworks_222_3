#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void main1(void) {
	setlocale(LC_ALL, "RUS");

	// ������� 1
	int n, m, s = 0;
	puts("������� �������� m � n");
	scanf("%d%d", &m, &n);
	for (int i = n; i >= m; s += i, i--); 
	printf("��������� �1 - %d\n", s);

	// ������� 2
	s = 0;
	for (int i = n; i >= m; i--, s += i); // ���������� ��������, ������ �� ������� �� ������� ������
	printf("��������� �2 - %d\n", s);

	// ������� 3
	s = 0;
	for (int i = n; i >= m;) {
		i--;
		s += i;
	}
	printf("��������� �3 - %d\n", s);

	// ������� 4: ����� while
	s = 0;
	int i = n;
	while (i >= m) {
		i--;
		s += i;
	}
	printf("��������� �4 - %d\n", s);

	// ������� 5: ����� do-while
	s = 0;
	i = n;
	do
	{
		i--;
		s += i;
	}
	while (i >= m);
	printf("��������� �5 - %d\n", s);

}