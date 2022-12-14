#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>

// к заданию 1
struct point {
	float x;
	float y;
	char name;
};
typedef struct point Point;
void put_point(Point z);
float dist(Point z, Point w);
Point middle(Point a, Point b);

// к заданию 2
struct tm* mytime;
time_t t;

void main1()
{
	setlocale(LC_ALL, "RUS");

	// ЗАДАНИЕ 1.  Напишите программу, работающую с точками на плоскости
	Point a, b;
	float d;
	a = (Point){ 1.f, 2.f, 'A' };
	b.name = 'B'; b.x = 5; b.y = -3;
	put_point(a);
	put_point(b);

	d = dist(a, b);
	printf("Декартово расстояние между точками: %g\n", d);

	Point c;
	c = middle(a, b);
	c.name = 'C';
	put_point(c);

	// ЗАДАНИЕ 2. Напишите программу, которая выводит на экран текущее время
	//		3. День (цифра) и месяц (слово)
	char str[43];
	t = time(NULL);
	mytime = localtime(&t);
	sprintf(str, " Московское время %02d:%02d:%02d, %d ",
		mytime->tm_hour, mytime->tm_min, mytime->tm_sec, mytime->tm_mday);

	switch (mytime->tm_mon)
	{
	case 0:
		strcat(str, "января ");
		break;
	case 1:
		strcat(str, "февраля ");
		break;
	case 2:
		strcat(str, "марта ");
		break;
	case 3:
		strcat(str, "апреля ");
		break;
	case 4:
		strcat(str, "мая ");
		break;
	case 5:
		strcat(str, "июня ");
		break;
	case 6:
		strcat(str, "июля ");
		break;
	case 7:
		strcat(str, "августа ");
		break;
	case 8:
		strcat(str, "сентября ");
		break;
	case 9:
		strcat(str, "октября ");
		break;
	case 10:
		strcat(str, "ноября ");
		break;
	case 11:
		strcat(str, "декабря ");
		break;
	}
	for (int i = 0; i < 120; i++)
		printf("—");
	printf("\n|");
	for (int i = 0; i < 118; i++)
		printf("*");
	printf("|\n|");
	for (int i = 0; i < (118 - strlen(str)) / 2.; i++)
		printf("*");
	printf("%s", str);
	for (int i = 0; i < (117 - strlen(str)) / 2.; i++)
		printf("*");
	printf("|\n|");
	for (int i = 0; i < 118; i++)
		printf("*");
	printf("|\n");
	for (int i = 0; i < 120; i++)
		printf("-");
}

// отображение точки 
void put_point(Point z) 
{
	printf("point %c (%.1f, %.1f)\n", z.name, z.x, z.y);
}

// вычисление декартова расстояния между двумя точками
float dist(Point a, Point b)
{
	float result;
	result = (float)sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
	return result;
}

//  получение середины отрезка между двумя точками
Point middle(Point a, Point b)
{
	Point c;
	float x, y;
	x = (a.x + b.x) / 2;
	y = (a.y + b.y) / 2;;
	c.x = x;
	c.y = y;
	return c;
}