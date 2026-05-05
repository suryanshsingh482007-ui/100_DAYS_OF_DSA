#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* deleteKey(struct Node* head, int key) {
    struct Node *current = head;
    struct Node *prev = NULL;
    
    if (current != NULL && current->data == key) {
        head = current->next;
        free(current);
        return head;
    }
    
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return head;
    }
    
    prev->next = current->next;
    free(current);
    
    return head;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    printf("Created list: ");
    printList(head);
    
    int keyToDelete = 3;
    head = deleteKey(head, keyToDelete);
    printf("List after deleting %d: ", keyToDelete);
    printList(head);

    keyToDelete = 1;
    head = deleteKey(head, keyToDelete);
    printf("List after deleting %d: ", keyToDelete);
    printList(head);
    
    return 0;
}

