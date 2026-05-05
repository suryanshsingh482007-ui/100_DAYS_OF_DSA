#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

int countOccurrences(struct Node* head, int target) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int target = 2;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 2);

    int result = countOccurrences(head, target);
    printf("Element %d occurs %d times\n", target, result);

    freeList(head);
    return 0;
}