//comments are mainly for me to follow up with my code not for task 
#include "doubly-linked-list.h"
#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>

int _add (DOUBLYLINKEDLIST *list , int index ,void *element)
{
   if (index<0 || index > list->size )
   {
    return -1;
   }
    Node *New =malloc(sizeof(Node));
    if (!New)
    {
        return -2 ;
    }
    New->data =element;
    New->Next=NULL;
    New->Prev=NULL;
    if (index == 0)
    {
        New->Next = list->head;
        if (list->head)
            list->head->Prev = New;
        list->head = New;
    }
    else 
    {
        Node *temp = list->head;
        for (int i=0 ; i<index-1; i++) //finding the node before the insertion place
        {
            temp = temp->Next ; //temp is the node on list[index-1]
        }
        New->Prev =temp;
        New->Next=temp->Next; //the one pushed forward is the next which was originaly at the index
        if (temp->Next != NULL)
        {
        temp->Next->Prev = New;//the node pushed forward prev will look at the new element
        }
        temp->Next = New;  //the next pointer of temp which is list[i-1] is loking at new element  
    }      
    list->size++;
    return 0;
       
}

int _addEND(DOUBLYLINKEDLIST *list ,void *element) //overloading 
{
    return _add(list ,list->size, element);
}

void *get(DOUBLYLINKEDLIST *list, int index)
{
    if (index >= list->size || index < 0)
    {
        return NULL;
    }

    Node *temp = list->head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->Next;
    }

    return temp->data;
}


int _set(DOUBLYLINKEDLIST *list ,int index ,void *element)
{
    if (index>list->size || index < 0)
    {
        return -1;
    }
    Node *temp =list->head; 
    for (int i =0;i<index;i++)
    {
        temp=temp->Next;
    }
    temp->data=element;
    return 0;

}

int _clear(DOUBLYLINKEDLIST *list)
{
    if (list == NULL)
    { 
    return -1;
    }
    Node *temp = list->head;
    for (int i =0 ; i<list->size;i++)
    {
        Node *move=temp->Next;
        free(temp);
        temp=move;
    }
    list->head=NULL;
    list->size=0;
    return 0;
}

bool _isEmpty(DOUBLYLINKEDLIST *list)
{
    Node *temp=list->head;

        if (list == NULL || list->size == 0 || list->head == NULL)
        {
            return true;
        }
        else 
        {
            return false ;
        }
    
}

int _remove(DOUBLYLINKEDLIST *list, int index)
{
    if (list == NULL || index < 0 || index >= list->size)
    {
        return -1;
    }

    Node *delete;

    if (index == 0)
    {
        delete = list->head;
        list->head = delete->Next;

        if (list->head != NULL)
        {
            list->head->Prev = NULL;
        }
        else
        free(delete);
    }
    else
    {
        Node *temp = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->Next;
        }

        delete = temp->Next;
        temp->Next = delete->Next;

        if (delete->Next != NULL)
        {
            delete->Next->Prev = temp;
        }
        free(delete);
    }

    list->size--;
    return 0;
}

int _size(DOUBLYLINKEDLIST *list)
{
    return list->size;
}

DOUBLYLINKEDLIST *sublist(DOUBLYLINKEDLIST *list , int start , int end)
{ 
    if (list == NULL || start < 0 || end >= list->size || start > end)
        return NULL;

    DOUBLYLINKEDLIST *sub = (DOUBLYLINKEDLIST *) malloc(sizeof(DOUBLYLINKEDLIST));
    if (sub == NULL)
        return NULL;

    Node *cursor = list->head;
    for (int i = 0; i < start; i++)
    {
        cursor = cursor->Next;
    }
    sub->head = cursor;
    sub->head->Prev = NULL;
    for (int i = start; i < end; i++)
    {
        cursor = cursor->Next;
    }

    sub->size = end - start + 1;
    return sub;
}

bool _contains(DOUBLYLINKEDLIST* list , void *element)
{
    Node *cursor  =list->head;
    for (int i=0; i< list->size ; i++)
    {
        if (* (int *)cursor->data==*(int *)element) // only works for int
        {
            return true;
        }   
        else
        {
            cursor = cursor->Next;
        }
    }
    return false ;

}

int main() 
{

        DOUBLYLINKEDLIST list;
        list.head = NULL;
        list.size = 0;
    
        int *a = malloc(sizeof(int)); *a = 10;
        int *b = malloc(sizeof(int)); *b = 20;
        int *c = malloc(sizeof(int)); *c = 30;
        int *d = malloc(sizeof(int)); *d = 40;
    
        // Test _add at end
        _add(&list,0, a);
        _add(&list,1, b);
        _add(&list,2, c);
    
        printf("After adding 3 elements: ");
        for (int i = 0; i < _size(&list); i++) {
            printf("%d ", *(int *)get(&list, i));
        }
        printf("\n");
    
        // Test _add at index 1
        _add(&list, 1 , d);
        printf("After inserting 40 at index 1: ");
        for (int i = 0; i < _size(&list); i++) {
            printf("%d ", *(int *)get(&list, i));
        }
        printf("\n");
    
        // Test _set
        int *e = malloc(sizeof(int)); *e = 99;
        _set(&list, 2, e);
        printf("After setting index 2 to 99: ");
        for (int i = 0; i < _size(&list); i++) {
            printf("%d ", *(int *)get(&list, i));
        }
        printf("\n");
    
        // Test _contains
        printf("Contains 99? %s\n", _contains(&list, e) ? "Yes" : "No");
    
        // Test _remove
        _remove(&list, 1);
        printf("After removing element at index 1: ");
        for (int i = 0; i < _size(&list); i++) {
            printf("%d ", *(int *)get(&list, i));
        }
        printf("\n");
    
        // Test sublist
        DOUBLYLINKEDLIST *sub = sublist(&list, 0, 1);
        printf("Sublist from index 0 to 1: ");
        for (int i = 0; i < _size(sub); i++) {
            printf("%d ", *(int *)get(sub, i));
        }
        printf("\n");
    
        // Test _clear
        _clear(&list);
        printf("After clearing list: Size = %d, isEmpty = %s\n", _size(&list), _isEmpty(&list) ? "Yes" : "No");
    
        // Free the sublist itself (not the nodes inside it — they were shallow-copied)
        free(sub);
    
        return 0;
}

