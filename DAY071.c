#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

struct HashTable {
    int* table;
    bool* occupied;
    int m;
};

struct HashTable* createTable(int m) {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->m = m;
    ht->table = (int*)malloc(sizeof(int) * m);
    ht->occupied = (bool*)malloc(sizeof(bool) * m);
    for (int i = 0; i < m; i++) {
        ht->occupied[i] = false;
    }
    return ht;
}

int hash(int key, int m) {
    return key % m;
}

void insert(struct HashTable* ht, int key) {
    int h_k = hash(key, ht->m);
    for (int i = 0; i < ht->m; i++) {
        int index = (h_k + i * i) % ht->m;
        if (!ht->occupied[index]) {
            ht->table[index] = key;
            ht->occupied[index] = true;
            return;
        }
    }
}

bool search(struct HashTable* ht, int key) {
    int h_k = hash(key, ht->m);
    for (int i = 0; i < ht->m; i++) {
        int index = (h_k + i * i) % ht->m;
        if (!ht->occupied[index]) {
            return false;
        }
        if (ht->table[index] == key) {
            return true;
        }
    }
    return false;
}

void display(struct HashTable* ht) {
    for (int i = 0; i < ht->m; i++) {
        if (ht->occupied[i]) {
            printf("[%d]: %d\n", i, ht->table[i]);
        } else {
            printf("[%d]: EMPTY\n", i);
        }
    }
}

int main() {
    struct HashTable* ht = createTable(SIZE);
    
    int keys[] = {10, 20, 30, 40, 5, 15};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(ht, keys[i]);
    }

    display(ht);

    int target = 30;
    if (search(ht, target)) {
        printf("Found %d\n", target);
    } else {
        printf("%d Not Found\n", target);
    }

    return 0;
}