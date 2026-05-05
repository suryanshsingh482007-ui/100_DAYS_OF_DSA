#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
    int capacity;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->front = NULL;
    obj->rear = NULL;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) return false;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    
    if (obj->size == 0) {
        obj->front = newNode;
        obj->rear = newNode;
        newNode->next = obj->front;
    } else {
        obj->rear->next = newNode;
        obj->rear = newNode;
        obj->rear->next = obj->front;
    }
    
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) return false;
    
    Node* temp = obj->front;
    if (obj->size == 1) {
        obj->front = NULL;
        obj->rear = NULL;
    } else {
        obj->front = obj->front->next;
        obj->rear->next = obj->front;
    }
    
    free(temp);
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return (obj->size == 0) ? -1 : obj->front->data;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return (obj->size == 0) ? -1 : obj->rear->data;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj->front != NULL) {
        Node* curr = obj->front;
        for (int i = 0; i < obj->size; i++) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj);
}