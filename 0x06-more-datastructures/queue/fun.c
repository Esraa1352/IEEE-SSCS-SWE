#include "queue.h"
#include <stdio.h>
#include <stdbool.h>  // Needed for bool

int front = -1, rear = -1;

int _enqueue(int data[max_size], int item)
{
    if (rear == max_size - 1)
    {
        printf("\nYou have reached the max size of the queue.");
        return -1;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    data[rear] = item;
    printf("\nInserted -> %d", item);

    printf("\nFull QUEUE after Insertion -> ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}

int _dequeue(int data[max_size])
{
    if (front == -1 || front > rear)
    {
        printf("\nQUEUE is Empty.");
        return -1;
    }

    printf("\nDeleted -> %d", data[front]);
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
        printf("\nQUEUE is now empty.");
    }

    printf("\nFull QUEUE After Deletion -> ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}

int _front(int data[max_size])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    printf("\nThe Element in Front is %d", data[front]);
    return data[front];  
}

bool _isEmpty(int data[max_size])
{
    bool check = (front == -1 || front > rear);
    printf("\nIs the queue empty? %s", check ? "TRUE" : "FALSE");
    return check;
}

int _size(int data[max_size])
{
    if (front == -1 || front > rear)
    {
        printf("\nNumber of elements in queue: 0");
        return 0;
    }

    int size = rear - front + 1;
    printf("\nNumber of elements in queue: %d", size);
    return size;
}

int _clear(int data[max_size])
{
    front = -1;
    rear = -1;
    printf("\nQueue has been cleared.");
    return 0;
}
