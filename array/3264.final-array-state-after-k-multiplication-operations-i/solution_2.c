/*
 * @lc app=leetcode id=3264 lang=c
 *
 * [3264] Final Array State After K Multiplication Operations I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct Array {
    int index;
    int value;
} Array;

void heapify(Array* arr, int len, int idx) {
    int min = idx, left = (idx << 1) + 1, right = left + 1;
    // swap to parent if value is lower or same value smaller index
    if (left < len && (arr[left].value < arr[min].value ||
       (arr[left].index < arr[min].index && arr[left].value == arr[min].value))) {
        min = left;
    }
    if (right < len && (arr[right].value < arr[min].value ||
       (arr[right].index < arr[min].index && arr[right].value == arr[min].value))) {
        min = right;
    }
    if (min != idx) {
        Array temp = arr[idx];
        arr[idx] = arr[min];
        arr[min] = temp;
        heapify(arr, len, min);
    }
}

void heapifyArray(Array* arr, int len) {
    for (int i = len / 2; i >= 0; i--) {
        heapify(arr, len, i);
    }
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    // Pack nums into index and value then heapify into a minHeap
    // Time: O((k+N)logN), Space: O(1)
    *returnSize = numsSize;
    Array *arr = malloc(numsSize * sizeof(Array));
    for (int i = 0; i < numsSize; i++) {
        arr[i].index = i;
        arr[i].value = nums[i];
    }
    heapifyArray(arr, numsSize);

    while (k--) {
        int minIndex = arr[0].index;
        arr[0].value *= multiplier;
        nums[minIndex] *= multiplier;
        heapify(arr, numsSize, 0);
    }
    return nums;
}
// @lc code=end

