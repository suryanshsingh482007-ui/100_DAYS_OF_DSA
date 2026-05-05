//s
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct {
    struct Node* front;
    struct Node* rear;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->front = NULL;
    obj->rear = NULL;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (obj->rear == NULL) {
        obj->front = obj->rear = newNode;
        return;
    }
    obj->rear->next = newNode;
    obj->rear = newNode;
}

int myQueuePop(MyQueue* obj) {
    if (obj->front == NULL) return -1;
    struct Node* temp = obj->front;
    int val = temp->data;
    obj->front = obj->front->next;
    if (obj->front == NULL) obj->rear = NULL;
    free(temp);
    return val;
}

int myQueuePeek(MyQueue* obj) {
    if (obj->front == NULL) return -1;
    return obj->front->data;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->front == NULL;
}

void myQueueFree(MyQueue* obj) {
    struct Node* curr = obj->front;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}