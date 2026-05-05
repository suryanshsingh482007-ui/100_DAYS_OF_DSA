#include <stdlib.h>

typedef struct {
    int* heap;
    int size;
    int k;
} KthLargest;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int* heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void heapUp(int* heap, int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size] = val;
        obj->size++;
        heapUp(obj->heap, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        minHeapify(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }
    return obj;
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}