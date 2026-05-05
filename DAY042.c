#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *array;
    int front, rear, size, capacity;
};

struct Stack {
    int *array;
    int top, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

void reverseQueue(struct Queue* queue) {
    struct Stack* stack = createStack(queue->size);

    while (queue->size > 0) {
        push(stack, dequeue(queue));
    }

    while (stack->top != -1) {
        enqueue(queue, pop(stack));
    }

    free(stack->array);
    free(stack);
}

void printQueue(struct Queue* queue) {
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(10);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    reverseQueue(queue);

    printQueue(queue);

    return 0;
}