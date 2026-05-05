#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int getCount(struct Node* head) {
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1 - c2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (c1 > c2) {
        for (int i = 0; i < d; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < d; i++) ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}



int main() {
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);

    struct Node* head2 = createNode(15);

    struct Node* common = createNode(40);
    common->next = createNode(50);

    head1->next->next->next = common;
    head2->next = common;

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection) {
        printf("Intersection at node with data: %d\n", intersection->data);
    } else {
        printf("No intersection found.\n");
    }

    return 0;
}