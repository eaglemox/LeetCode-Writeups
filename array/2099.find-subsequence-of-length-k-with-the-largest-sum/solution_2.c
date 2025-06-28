/*
 * @lc app=leetcode id=2099 lang=c
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Node;

void heapifyUp(Node* heap, int idx) {
    while (idx > 0) {
        int pidx = (idx - 1) / 2;
        if (heap[pidx].val > heap[idx].val) {
            // Swap current node with parent node
            Node tmp = heap[pidx];
            heap[pidx] = heap[idx];
            heap[idx] = tmp;

            // Move to parent index
            idx = pidx;
        } else {
            break;
        }
    }
}

void heapifyDown(Node* heap, int heapSize, int idx) {
    int smallest = idx, left = idx * 2 + 1, right = left + 1;

    // If left or right node is smaller than current node move to that node
    if (left < heapSize && heap[left].val < heap[smallest].val) {
        smallest = left;
    }
    if (right < heapSize && heap[right].val < heap[smallest].val) {
        smallest = right;
    }

    if (smallest != idx) {
        // Swap current node with smallest node
        Node tmp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = tmp;

        // Recursively heapify
        heapifyDown(heap, heapSize, smallest);
    }
}

int cmpIndex(const void* a, const void* b) {
    Node *na = (Node*)a, *nb = (Node*)b;
    return na->index - nb->index;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    // Utilize heap to find min element to swap out in result
    // Time: O(NlogK), Space: O(K)
    int heapSize = 0;
    Node *heap = malloc(k * sizeof(Node));
    
    for (int i = 0; i < numsSize; i++) {
        Node new = {.val = nums[i], .index = i};

        if (heapSize < k) {
            heap[heapSize] = new;
            heapifyUp(heap, heapSize);
            heapSize++;
        } else if (new.val > heap[0].val) { // next element > min in heap
            heap[0] = new;
            heapifyDown(heap, heapSize, 0);
        }
    }

    *returnSize = k;
    int *result = malloc(k * sizeof(int));

    qsort(heap, heapSize, sizeof(heap), cmpIndex);

    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }

    free(heap);
    return result;
}
// @lc code=end

