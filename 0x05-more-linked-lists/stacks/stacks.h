#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct Stack {
    Node* top;
    int size;
} Stack;

// Function prototypes
void push(Stack* stack, int element);
int pop(Stack* stack);
int peek(Stack* stack);
bool isEmpty(Stack* stack);
int size(Stack* stack);

#endif
