#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>


//задание 1
void main1(void)
{
	setlocale(LC_ALL, "RUS");

	char c;
	puts("Введите любой символ:");
	scanf("%c", &c);
	switch (c)
	{
	case '0':
		printf("Это цифра.\n");
		break;
	case '1':
		printf("Это цифра.\n");
		break;
	case '2':
		printf("Это цифра.\n");
		break;
	case '3':
		printf("Это цифра.\n");
		break;
	case '4':
		printf("Это цифра.\n");
		break;
	case '5':
		printf("Это цифра.\n");
		break;
	case '6':
		printf("Это цифра.\n");
		break;
	case '7':
		printf("Это цифра.\n");
		break;
	case '8':
		printf("Это цифра.\n");
		break;
	case '9':
		printf("Это цифра.\n");
		break;
	default:
		printf("Это буква.\n");
	}
	

	// задание 2
	float x, y;
	char a, ch;
	puts("Введите команду для вычисление в формате: 2*2");
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
		printf("%= %f (с отбрасыванием дробной части)\n", (int)x % (int)y);
		break;
	case '^':
		printf("= %f (с отбрасыванием дробной части)\n", pow(x, y));
		break;
	default:
		puts("Неизвестная операция");
		break;
	}
}