#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// Push: adds element at top
void push(Stack* stack, int element) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return;

    new_node->data = element;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop: removes and returns the top element
int pop(Stack* stack) {
    if (stack->top == NULL) return -1; // or error code

    Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return value;
}

// Peek: returns top without removing
int peek(Stack* stack) {
    if (stack->top == NULL) return -1; // or error code
    return stack->top->data;
}

// Check if empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Return current size
int size(Stack* stack) {
    return stack->size;
}
