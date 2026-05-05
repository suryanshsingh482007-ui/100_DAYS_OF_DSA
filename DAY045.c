//s
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}