//git
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createnewnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) return createnewnode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void getRightView(struct node* root, int level, int* max_level) {
    if (root == NULL) return;

    if (*max_level < level) {
        printf("%d ", root->data);
        *max_level = level;
    }

    getRightView(root->right, level + 1, max_level);
    getRightView(root->left, level + 1, max_level);
}

int main() {
    struct node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    int max_level = 0;
    printf("Right Side View: ");
    getRightView(root, 1, &max_level);
    printf("\n");

    return 0;
}