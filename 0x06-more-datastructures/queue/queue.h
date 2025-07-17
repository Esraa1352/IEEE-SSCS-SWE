#ifndef QUEUE_H
#define QUEUE_H
#include<stdbool.h>
#define max_size 100

int _enqueue(int data[],int item);
int _dequeue();
int _front(int data[]);
bool _isEmpty(int data[]);
int _size(int data[]);
int _clear(int data[]); 
#endif
