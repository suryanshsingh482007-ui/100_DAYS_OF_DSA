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

struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n && arr[i] != -1) {
        root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

void findMinMax(struct Node* node, int* min, int* max, int hd) {
    if (node == NULL) return;
    if (hd < *min) *min = hd;
    else if (hd > *max) *max = hd;
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

void printVerticalLine(struct Node* node, int line_no, int hd) {
    if (node == NULL) return;
    if (hd == line_no) printf("%d ", node->data);
    printVerticalLine(node->left, line_no, hd - 1);
    printVerticalLine(node->right, line_no, hd + 1);
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
    for (int line_no = min; line_no <= max; line_no++) {
        printVerticalLine(root, line_no, 0);
        printf("\n");
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = insertLevelOrder(arr, 0, n);
    verticalOrder(root);

    return 0;
}