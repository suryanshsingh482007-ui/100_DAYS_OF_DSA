#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool isMirror(struct node* root1, struct node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) && 
               isMirror(root1->right, root2->left);

    return false;
}

bool isSymmetric(struct node* root) {
    return isMirror(root, root);
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("The tree is symmetric.\n");
    else
        printf("The tree is not symmetric.\n");

    return 0;
}