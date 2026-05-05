#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        struct Node* current = queue[head++];

        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[tail++] = current->left;
        }

        if (current->right != NULL) {
            queue[tail++] = current->right;
        }
    }
    
    free(queue);
}