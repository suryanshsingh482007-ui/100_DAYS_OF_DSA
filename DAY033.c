//simran
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char stack[100];
    int top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            stack[++top] = token;
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = token;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[100];

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    return 0;
}