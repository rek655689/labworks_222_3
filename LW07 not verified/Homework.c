#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>


//��������� ���������, ������� � ����������� �� ����������� ������ ������ ������� �� ����� ����� ����.

void main(void)
{
	setlocale(LC_ALL, "RUS");
	
	int n;
	puts("������� ���������� ����� ������");
	scanf("%d", &n);
	
	switch (n)
	{
	case 1:  // ������
		puts("��� ����");
		break;
	case 2: // �������
		puts("��� ����");
		break;
	case 3: // ����
		puts("��� �����");
		break;
	case 4: // ������
		puts("��� �����");
		break;
	case 5: // ���
		puts("��� �����");
		break;
	case 6: // ����
		puts("��� ����");
		break;
	case 7: // ���� 
		puts("��� ����");
		break;
	case 8: // ������
		puts("��� ����");
		break;
	case 9: // ��������
		puts("��� �����");
		break;
	case 10: // �������
		puts("��� �����");
		break;
	case 11: // ������
		puts("��� �����");
		break;
	case 12: //�������
		puts("��� ����");
		break;
	default:
		puts("������� ���������� ����� ������ (�� 1 �� 12)");
	}
	
}