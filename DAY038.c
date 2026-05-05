//s
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Deque {
    struct Node *front, *rear;
};

struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

bool isEmpty(struct Deque* dq) {
    return (dq->front == NULL);
}

void insertFront(struct Deque* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq)) dq->rear = newNode;
    else dq->front->prev = newNode;

    dq->front = newNode;
}

void insertRear(struct Deque* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (isEmpty(dq)) dq->front = newNode;
    else dq->rear->next = newNode;

    dq->rear = newNode;
}

int deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) return -1;
    struct Node* temp = dq->front;
    int data = temp->data;
    dq->front = dq->front->next;

    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;

    free(temp);
    return data;
}

int deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) return -1;
    struct Node* temp = dq->rear;
    int data = temp->data;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;

    free(temp);
    return data;
}

int getFront(struct Deque* dq) {
    return isEmpty(dq) ? -1 : dq->front->data;
}

int getRear(struct Deque* dq) {
    return isEmpty(dq) ? -1 : dq->rear->data;
}