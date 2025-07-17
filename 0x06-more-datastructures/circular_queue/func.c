#include "circular_queue.h"

int front = -1, rear = -1;

int _Full(int data[]) {
    return (front == (rear + 1) % size);
}

int _isEmpty(int data[]) {
    return (front == -1);
}

int _enque(int data[], int element) {
    if (_Full(data)) {
        printf("Queue is full\n");
        return -1;
    }

    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    data[rear] = element;

    printf("Queue after insertion-> ");
    int i = front;
    while (1) {
        printf("%d ", data[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
    return 0;
}

int _deque(int data[]) {
    if (_isEmpty(data)) {
        printf("Queue is empty\n");
        return -1;
    }

    int deleted = data[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    printf("%d got deleted from the queue\n", deleted);
    return deleted;
}


