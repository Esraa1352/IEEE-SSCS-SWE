#include "deque.h"
#include <stdio.h>

int front =-1,rear=-1;

void print_queue(int data[])
{
    if (empty(data)) {
        printf("[ ]\n");
        return;
    }

    printf("[ ");
    int i = front;
    while (1)
    {
        printf("%d ", data[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("]\n");
}

int full(int data[])
{
    return (front == (rear + 1) % size);
}

int empty(int data[])
{
    return (front == -1);
}

int push_front(int data[], int element)
{
    if (full(data))
    {
        printf("the deque is full\n");
        return -1;
    }
    if (empty(data))
    {
        front = 0;
        rear = 0;
        data[front] = element; 
        printf("Pushed %d to front at index %d\n", element, front); 
        print_queue(data); 
        return 0; 
    }
    else
    {
        front = (front - 1 + size) % size;
    }
    data[front] = element;
    printf("Pushed %d to front at index %d\n", element, front);
    print_queue(data);
    return 0; 
}

int push_back(int data[], int element)
{
    if (full(data))
    {
        printf("the deque is full\n");
        return -1;
    }
    if (empty(data))
    {
        front = 0;
        rear = 0;
        data[rear] = element; 
        printf("Pushed %d to back at index %d\n", element, rear); 
        print_queue(data);
        return 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    data[rear] = element;
    printf("Pushed %d to back at index %d\n", element, rear);
    print_queue(data); 
    return 0; 
}

int pop_front(int data[])
{
    if (empty(data)) {
        printf("Deque is already empty\n");
        return -1;
    }

    int removed = data[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    printf("Popped %d from front\n", removed);
    print_queue(data);
    return removed;
}

int pop_back(int data[])
{
    if (empty(data)) {
        printf("Deque is already empty\n");
        return -1;
    }

    int removed = data[rear];

    if (front == rear)
    {
        front = rear = -1;
        printf("Deque became empty\n");
    }
    else
    {
        rear = (rear - 1 + size) % size;
    }

    printf("Popped %d from back \n", removed);
    print_queue(data);
    return removed;
}

int _front(int data[])
{
    printf("\nelement at front is %d",data[front]);
    return 0;
}

int back(int data[])
{
    return data[rear];
}

int _size(int data[])
{
    int num;
    if (empty(data))
    {
        num = 0;
        printf("\nsize of the dequeue = %d\n", num);
        return 0;
    }
    if (rear >= front)
    {
        num = rear - front + 1;
        printf("\nsize of the dequeue = %d\n", num);
        return rear - front + 1;
    }
    num = size - front + rear + 1;
    printf("\nsize of the dequeue = %d\n", num); 
    return size - front + rear + 1;
}

int clear(int data[])
{
    front = -1;
    rear = -1;
    printf("queue is cleared");
    print_queue(data);
    return 0;
}
