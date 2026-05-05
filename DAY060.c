#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
}

int countNodes(struct node* root) {
    if (root == NULL) return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isComplete(struct node* root, int index, int number_nodes) {
    if (root == NULL) return true;
    if (index >= number_nodes) return false;
    
    return (isComplete(root->left, 2 * index + 1, number_nodes) &&
            isComplete(root->right, 2 * index + 2, number_nodes));
}

bool isHeapProperty(struct node* root) {
    if (root->left == NULL && root->right == NULL) return true;

    if (root->right == NULL) {
        return root->data <= root->left->data;
    } else {
        if (root->data <= root->left->data && root->data <= root->right->data)
            return isHeapProperty(root->left) && isHeapProperty(root->right);
        else
            return false;
    }
}

bool isMinHeap(struct node* root) {
    int node_count = countNodes(root);
    if (isComplete(root, 0, node_count) && isHeapProperty(root))
        return true;
    return false;
}

int main() {
    struct node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    if (isMinHeap(root))
        printf("The tree is a Min-Heap\n");
    else
        printf("The tree is NOT a Min-Heap\n");
}