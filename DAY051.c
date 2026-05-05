#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* lca(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (root->data > n1 && root->data > n2) {
            root = root->left;
        } else if (root->data < n1 && root->data < n2) {
            root = root->right;
        } else {
            break;
        }
    }
    return root;
}

int main() {
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct Node* t = lca(root, n1, n2);
    if (t != NULL) {
        printf("LCA of %d and %d is %d\n", n1, n2, t->data);
    }

    return 0;
}