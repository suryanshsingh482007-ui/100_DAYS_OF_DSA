#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void deleteSpecific(int target) {
    if (top == -1) {
        return;
    }

    int temp = pop();

    if (temp == target) {
        return;
    }

    deleteSpecific(target);
    push(temp);
}

void display() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    deleteSpecific(30);

    display();

    return 0;
}