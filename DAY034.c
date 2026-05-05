#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i]; i++) {
        if (isspace(exp[i])) continue;

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            push(&stack, num);
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[] = "10 2 * 3 +"; 
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}