//s
#include <stdio.h>
#include <stdlib.h>

struct MinHeap {
    int* data;
    int size;
    int capacity;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MinHeap* heap, int index) {
    while (index > 0 && heap->data[(index - 1) / 2] > heap->data[index]) {
        swap(&heap->data[(index - 1) / 2], &heap->data[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(struct MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;
    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(struct MinHeap* heap, int val) {
    if (heap->size == heap->capacity) return;
    heap->data[heap->size] = val;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(struct MinHeap* heap) {
    if (heap->size <= 0) return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return root;
}

int getMin(struct MinHeap* heap) {
    return (heap->size > 0) ? heap->data[0] : -1;
}