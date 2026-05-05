//s
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (!isFull(s)) {
        s->items[++(s->top)] = val;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1;
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("New top: %d\n", peek(&s));

    return 0;
}