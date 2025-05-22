/*
 * @lc app=leetcode id=3362 lang=c
 *
 * [3362] Zero Array Transformation III
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

// Max heap implementation for storing query end positions (ri)
typedef struct {
    int *data;
    int size;
} MaxHeap;

void heapInit(MaxHeap *h, int capacity) {
    h->data = (int *)malloc(sizeof(int) * capacity);
    h->size = 0;
}

void heapPush(MaxHeap *h, int val) {
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p] >= val) break;
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i] = val;
}

int heap_pop(MaxHeap *h) {
    int ret = h->data[0];
    int val = h->data[--h->size];
    int i = 0;
    while (i * 2 + 1 < h->size) {
        int a = i * 2 + 1, b = i * 2 + 2;
        int max = (b < h->size && h->data[b] > h->data[a]) ? b : a;
        if (h->data[max] <= val) break;
        h->data[i] = h->data[max];
        i = max;
    }
    h->data[i] = val;
    return ret;
}

int heap_top(MaxHeap *h) {
    return h->size > 0 ? h->data[0] : -1;
}

int cmp(const void *a, const void *b) {
    int *_a = *(int **)a;
    int *_b = *(int **)b;
    return _a[0] - _b[0];  // sort by li
}

int maxRemoval(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    qsort(queries, queriesSize, sizeof(int*), cmp);

    int *end = calloc(numsSize + 2, sizeof(int));
    MaxHeap heap;
    heapInit(&heap, queriesSize + 5);

    int cur = 0, j = 0;
    for (int i = 0; i < numsSize; i++) {
        cur -= end[i];

        while (j < queriesSize && queries[j][0] <= i) {
            heapPush(&heap, queries[j][1]);
            j++;
        }

        while (cur < nums[i]) {
            if (heap.size == 0 || heap_top(&heap) < i) {
                free(end);
                free(heap.data);
                return -1;
            }
            int r = heap_pop(&heap);
            end[r + 1]++;
            cur++;
        }
    }

    int result = heap.size;
    free(end);
    free(heap.data);
    return result;
}
// @lc code=end

