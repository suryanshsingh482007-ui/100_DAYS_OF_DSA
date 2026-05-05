#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void traverseInorder(struct TreeNode* root, int* arr, int* pos) {
    if (!root) return;
    traverseInorder(root->left, arr, pos);
    arr[(*pos)++] = root->val;
    traverseInorder(root->right, arr, pos);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = countNodes(root);
    *returnSize = size;
    int* res = (int*)malloc(size * sizeof(int));
    int pos = 0;
    traverseInorder(root, res, &pos);
    return res;
}

void traversePreorder(struct TreeNode* root, int* arr, int* pos) {
    if (!root) return;
    arr[(*pos)++] = root->val;
    traversePreorder(root->left, arr, pos);
    traversePreorder(root->right, arr, pos);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = countNodes(root);
    *returnSize = size;
    int* res = (int*)malloc(size * sizeof(int));
    int pos = 0;
    traversePreorder(root, res, &pos);
    return res;
}

void traversePostorder(struct TreeNode* root, int* arr, int* pos) {
    if (!root) return;
    traversePostorder(root->left, arr, pos);
    traversePostorder(root->right, arr, pos);
    arr[(*pos)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = countNodes(root);
    *returnSize = size;
    int* res = (int*)malloc(size * sizeof(int));
    int pos = 0;
    traversePostorder(root, res, &pos);
    return res;
}