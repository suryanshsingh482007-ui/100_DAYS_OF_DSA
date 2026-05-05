#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertTerm(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);
    if (head == NULL || head->exp < e) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->exp > e)
        temp = temp->next;
    if (temp->next != NULL && temp->next->exp == e) {
        temp->next->coeff += c;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;
    int n, c, e;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        poly = insertTerm(poly, c, e);
    }

    display(poly);

    return 0;
}