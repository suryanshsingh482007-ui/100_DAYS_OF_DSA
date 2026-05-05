//s
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int maxDepth(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    if (lDepth > rDepth) {
        return (lDepth + 1);
    } else {
        return (rDepth + 1);
    }
}