//s
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertLevelOrder(int arr[], int n) {
    if (n == 0) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* parent = queue[head++];

        if (i < n) {
            parent->left = newNode(arr[i++]);
            queue[tail++] = parent->left;
        }

        if (i < n) {
            parent->right = newNode(arr[i++]);
            queue[tail++] = parent->right;
        }
    }

    free(queue);
    return root;
}