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

int search(int arr[], int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return i;
}

struct Node* buildTree(int in[], int pre[], int inStrt, int inEnd, int* preIndex) {
    if (inStrt > inEnd)
        return NULL;

    struct Node* tNode = newNode(pre[(*preIndex)++]);

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

void printPostorder(struct Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int *pre = (int*)malloc(n * sizeof(int));
    int *in = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int preIndex = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIndex);

    printf("Postorder traversal of the constructed tree is: \n");
    printPostorder(root);

    return 0;
}