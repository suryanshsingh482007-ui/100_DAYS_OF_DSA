#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct node* insertFirst(struct node *head, int val) {
    struct node *newNode = createNode(val);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

struct node* insertEnd(struct node *head, int val) {
    struct node *newNode = createNode(val);
    if (head == NULL) return newNode;
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void displayForward(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward(struct node *head) {
    if (head == NULL) return;
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}



void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node *head = NULL;
    int choice, val;
    while (1) {
        printf("\n1.Head 2.End 3.Display 4.Exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            head = insertFirst(head, val);
        } else if (choice == 2) {
            scanf("%d", &val);
            head = insertEnd(head, val);
        } else if (choice == 3) {
            displayForward(head);
            displayBackward(head);
        } else if (choice == 4) {
            freeList(head);
            exit(0);
        }
    }
    return 0;
}