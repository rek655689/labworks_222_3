#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>


//������� 1
void main1(void)
{
	setlocale(LC_ALL, "RUS");

	char c;
	puts("������� ����� ������:");
	scanf("%c", &c);
	switch (c)
	{
	case '0':
		printf("��� �����.\n");
		break;
	case '1':
		printf("��� �����.\n");
		break;
	case '2':
		printf("��� �����.\n");
		break;
	case '3':
		printf("��� �����.\n");
		break;
	case '4':
		printf("��� �����.\n");
		break;
	case '5':
		printf("��� �����.\n");
		break;
	case '6':
		printf("��� �����.\n");
		break;
	case '7':
		printf("��� �����.\n");
		break;
	case '8':
		printf("��� �����.\n");
		break;
	case '9':
		printf("��� �����.\n");
		break;
	default:
		printf("��� �����.\n");
	}
	

	// ������� 2
	float x, y;
	char a, ch;
	puts("������� ������� ��� ���������� � �������: 2*2");
	scanf("%f%c%f", &x, &ch, &y);
	switch (ch)
	{
	case '+':
		printf("= %f\n",x + y);
		break;
	case '-':
		printf("= %f\n", x - y);
		break;
	case '*':
		printf("= %f\n", x * y);
		break;
	case ':':
		printf("= %f\n", x / y);
		break;
	case '%':
		printf("%= %f (� ������������� ������� �����)\n", (int)x % (int)y);
		break;
	case '^':
		printf("= %f (� ������������� ������� �����)\n", pow(x, y));
		break;
	default:
		puts("����������� ��������");
		break;
	}
}