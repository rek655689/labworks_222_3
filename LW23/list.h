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

void initlist(List *); /* инициализация списка пустым содержимым */
void insertfront(List *, int val); /* вставка в список перед узлом со значением поля number=val */
void insertback(List *, int val); /* вставка в список после узла со значением поля number=val */
void insertfront_str(List *, char* str); /* вставка в список перед узлом со значением str в поле name */
void insertback_str(List *, char* str); /* вставка в список перед узлом со значением str в поле name */
_Bool isempty(List *);/* проверяет, является ли список пустым*/
int length(List); /* определение длины списка */
void destroyItem(List *, Node node); /* удаление заданного узла node из списка */
Node getitem(List, int n); /* нахождение узла со значением n в поле number*/
Node getitem_str(List, char* str); /* нахождение узла со значением str в поле name*/
#endif /* _LIST_H */