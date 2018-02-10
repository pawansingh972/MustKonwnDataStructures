#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, capacity;
    int *arr;
};

// Function to create a stack of given size
struct Queue* createQueue (int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = -1; 
    queue->rear = - 1;  // This is important, see the enqueue
    queue->arr = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull (struct Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

int isEmpty (struct Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue (struct Queue* queue, int data) {
    if ( isFull(queue) ) {
        return;
    }
    queue->arr[++queue->rear] = data;
}

int dequeue (struct Queue* queue) {
    if ( isEmpty(queue) ) {
        return;
    }
    return queue->arr[++queue->front];    
}

int main(int argc, char const *argv[]) {
    struct Queue* queue = createQueue(10);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    return 0;
}