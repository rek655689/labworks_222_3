#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>


//—оставить программу, котора€ в зависимости от пор€дкового номера мес€ца выводит на экран врем€ года.

void main(void)
{
	setlocale(LC_ALL, "RUS");
	
	int n;
	puts("¬ведите пор€дковый номер мес€ца");
	scanf("%d", &n);
	
	switch (n)
	{
	case 1:  // €нварь
		puts("Ёто зима");
		break;
	case 2: // февраль
		puts("Ёто зима");
		break;
	case 3: // март
		puts("Ёто весна");
		break;
	case 4: // апрель
		puts("Ёто весна");
		break;
	case 5: // май
		puts("Ёто весна");
		break;
	case 6: // июнь
		puts("Ёто лето");
		break;
	case 7: // июль 
		puts("Ёто лето");
		break;
	case 8: // август
		puts("Ёто лето");
		break;
	case 9: // сент€брь
		puts("Ёто осень");
		break;
	case 10: // окт€брь
		puts("Ёто осень");
		break;
	case 11: // но€брь
		puts("Ёто осень");
		break;
	case 12: //декабрь
		puts("Ёто зима");
		break;
	default:
		puts("¬ведите корректный номер мес€ца (от 1 до 12)");
	}
	
}