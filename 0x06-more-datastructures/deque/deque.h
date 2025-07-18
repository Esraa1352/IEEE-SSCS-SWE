#ifndef DEQUE_H
#define DEQUE_H
#define size 5
#include<stdio.h>

int full(int data[]);
int empty(int data[]);
int push_front(int data[],int element);
int push_back (int data[],int element);
int pop_front(int data[]);
int pop_back (int data[]);
int _front(int data[]);
int back(int data[]);
int _size(int data[]);
int clear(int data[]);
void print_queue(int data[]);

#endif