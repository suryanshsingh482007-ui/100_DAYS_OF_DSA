#include <stdio.h>
#include <stdlib.h>

struct Node {
    long long key;
    int count;
    struct Node* next;
};

#define TABLE_SIZE 10007

void insert(struct Node** table, long long sum) {
    int index = abs(sum % TABLE_SIZE);
    struct Node* temp = table[index];
    while (temp) {
        if (temp->key == sum) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = sum;
    newNode->count = 1;
    newNode->next = table[index];
    table[index] = newNode;
}

int getCount(struct Node** table, long long sum) {
    int index = abs(sum % TABLE_SIZE);
    struct Node* temp = table[index];
    while (temp) {
        if (temp->key == sum) return temp->count;
        temp = temp->next;
    }
    return 0;
}

int countSubarrays(int* nums, int numsSize) {
    struct Node* table[TABLE_SIZE] = {NULL};
    long long prefixSum = 0;
    int totalCount = 0;

    insert(table, 0);

    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        totalCount += getCount(table, prefixSum);
        insert(table, prefixSum);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* curr = table[i];
        while (curr) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return totalCount;
}

int main() {
    int nums[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("Total subarrays with zero sum: %d\n", countSubarrays(nums, n));
    return 0;
}