#ifndef DOUBLY_LINKED_LIST_H
#include<stdbool.h>
#define DOUBLY_LINKED_LIST_H


typedef struct Node
{
void *data ;
struct Node *Next ;
struct Node *Prev;
}Node ;


typedef struct  
{
struct Node *head ;
int size ;
}DOUBLYLINKEDLIST;

int _add(DOUBLYLINKEDLIST *list, int index, void *element);
int _addEND(DOUBLYLINKEDLIST *list, void *element); // since C doesn't allow overloading
void *get(DOUBLYLINKEDLIST *list, int index);
int _set(DOUBLYLINKEDLIST *list, int index, void *element);
int _clear(DOUBLYLINKEDLIST *list);
bool _isEmpty(DOUBLYLINKEDLIST *list);
int _remove(DOUBLYLINKEDLIST *list, int index);
int _size(DOUBLYLINKEDLIST *list);
DOUBLYLINKEDLIST *sublist(DOUBLYLINKEDLIST *list, int start, int end);
bool _contains(DOUBLYLINKEDLIST *list, void *element);

#endif
