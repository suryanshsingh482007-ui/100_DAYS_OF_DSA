//s
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void reverse(int* arr, int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    bool leftToRight = true;

    while (head < tail) {
        int levelSize = tail - head;
        int* currentLevel = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            currentLevel[i] = node->val;

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }

        if (!leftToRight) {
            reverse(currentLevel, levelSize);
        }

        result[(*returnSize)++] = currentLevel;
        leftToRight = !leftToRight;
    }

    free(queue);
    return result;
}