#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define ROW 9
#define COL 9

void main()
{
	setlocale(LC_ALL, "RUS");
	/*
	// ЗАДАНИЕ 1.  Программа печати таблицы Пифагора
	int row, col;
	printf("\n");
	for (row = 1; row <= ROW; ++row)
	{
		for (col = 1; col <= COL; col++) printf("%5d", col * row);
		printf("\n");
	}
	puts("\n");

	// 1.2 только левый нижний треугольник
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

	// 1.3 печать 41..50 41...71 (3 вариант)
	for (row = 40; row <= 70; row = row + 10)
	{
		for (col = 1; col <= 10; col++) printf("%5d", row + col);
		printf("\n");
	}
	puts("\n");

	*/

	// ЗАДАНИЕ 2.  Программа разложения произвольного длинного числа на цифры для определения:
	char a;
	int original_x;
	puts("Введите x");
	scanf("%d", &original_x);
	a = getchar();  // убираем символ переноса строки, который влез после scanf
	printf("\n");

	while (1)
	{

		// 1) количества цифр 3 в нем
		int count_digits = 0;
		for (int x = original_x; x > 0; x /= 10)
		{
			if (x % 10 == 3) count_digits++;
		}
		printf("1. Количество цифр 3: %d\n", count_digits);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 2) числа повторений последней цифры в числе
		count_digits = 0;
		int last_digit = original_x % 10;
		for (int x = original_x; x > 0; x /= 10)
		{
			if (x % 10 == last_digit) count_digits++;
		}
		printf("2. Количество цифр %d: %d\n", last_digit, count_digits);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 3) количества четных цифр
		count_digits = 0;
		for (int x = original_x; x > 0; x /= 10)
		{
			if ((x % 10) % 2 == 0) count_digits++;
		}
		printf("3. Количество четных цифр: %d\n", count_digits);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 4) количества цифр больше 5
		count_digits = 0;
		for (int x = original_x; x > 0; x /= 10)
		{
			if ((x % 10) > 5) count_digits++;
		}
		printf("4. Количество цифр больше 5: %d\n", count_digits);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 5) суммы нечетных цифр
		int sum = 0;
		for (int x = original_x; x > 0; x /= 10)
		{
			if ((x % 10) % 2 != 0) sum += (x % 10);
		}
		printf("5. Сумма нечетных цифр: %d\n", sum);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;

		// 6) суммы цифр больше или равно 7
		sum = 0;
		for (int x = original_x; x > 0; x /= 10)
		{
			if ((x % 10) >= 7) sum += (x % 10);
		}
		printf("6. Сумма цифр, которые больше или равны 7: %d\n", sum);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 7) произведения всех цифр, исключая 0
		int product = 1;
		for (int x = original_x; x > 0; x /= 10)
		{
			if ((x % 10) != 0) product *= (x % 10);
		}
		printf("7. Произведение всех цифр, исключая 0: %d\n", product);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 8) произведения предпоследней и второй цифры числа
		product = 1, count_digits = 0;
		for (int x = original_x; x > 0; x /= 10) count_digits++;
		product = ((original_x % 100) / 10) * ((original_x / (int)pow(10, count_digits - 2)) % 10);
		printf("8. Произведение предпоследней и второй цифры числа: %d\n", product);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 9) суммы четных цифр, исключая последнюю
		sum = 0;
		for (int x = original_x / 10; x > 0; x /= 10)
		{
			if ((x % 10) % 2 == 0) sum += x % 10;
		}
		printf("9. Сумма четных цифр, исключая последнюю: %d\n", sum);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 10) рядом расположенные одинаковые цифры
		count_digits = 0;
		int last = original_x % 10;
		for (int x = original_x / 10; x > 0; x /= 10)
		{
			if ((x % 10) == last) count_digits++;
			last = x % 10;
		}
		count_digits = count_digits > 0 ? ++count_digits : count_digits; // прибавляем 1, тк считали кол-во совпадений, а не цифр
		printf("10. Кол-во рядом расположенных одинаковых цифр: %d\n", count_digits);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
		
		// 11) равна ли сумма первой и второй половины цифр числа
		count_digits = 0;
		int first_sum = 0, second_sum = 0;
		for (int x = original_x; x > 0; x /= 10) count_digits++;

		if (count_digits % 2 != 0) puts("11. Для этого задания кол-во цифр должно быть чётным");
		else {
			int x = original_x;
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
			printf("11. Равна ли сумма первой и второй половины цифр числа? %s\n", first_sum == second_sum ? "Да" : "Нет");
		}
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;

		// 12) произведение сумм цифр четных и нечетных разрядов (младший разряд - 1)
		count_digits = 0, first_sum = 0, second_sum = 0, product = 1;
		for (int x = original_x; x > 0; x /= 10) count_digits++;

		int x = original_x;
		for (int i = 1; i <= count_digits; ++i)
		{
			if (i % 2 == 0) first_sum += (x % 10);
			else second_sum += (x % 10);
			x /= 10;
		}
		product = first_sum * second_sum;
		printf("12. Произведение сумм цифр четных и нечетных разрядов: %d\n", product);
		printf("Продолжить? (Да - любая клавиша, нет - n)\n");
		if ((a = getchar()) == 'n') break;
	}

}