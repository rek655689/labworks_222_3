#ifndef _LIST_H
#define _LIST_H

struct node {
  int number;
 char name[80];
 struct node *next;
};
typedef struct node Node;

struct list {
	Node* head;
};
typedef struct list List;

void initlist(List *); /* ������������� ������ ������ ���������� */
void insertfront(List *, int val); /* ������� � ������ ����� ����� �� ��������� ���� number=val */
void insertback(List *, int val); /* ������� � ������ ����� ���� �� ��������� ���� number=val */
void insertfront_str(List *, char* str); /* ������� � ������ ����� ����� �� ��������� str � ���� name */
void insertback_str(List *, char* str); /* ������� � ������ ����� ����� �� ��������� str � ���� name */
_Bool isempty(List *);/* ���������, �������� �� ������ ������*/
int length(List); /* ����������� ����� ������ */
void destroyItem(List *, Node node); /* �������� ��������� ���� node �� ������ */
Node getitem(List, int n); /* ���������� ���� �� ��������� n � ���� number*/
Node getitem_str(List, char* str); /* ���������� ���� �� ��������� str � ���� name*/
#endif /* _LIST_H */