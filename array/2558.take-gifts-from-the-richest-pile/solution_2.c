/*
 * @lc app=leetcode id=2558 lang=c
 *
 * [2558] Take Gifts From the Richest Pile
 */

// @lc code=start
#include <math.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int len, int idx) {
    // parent i, child l: 2i+1, r: 2i+2
    int largest = idx, left = (idx << 1) + 1, right = left + 1;
    if (left < len && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < len && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != idx) {
        swap(&arr[idx], &arr[largest]);
        heapify(arr, len, largest);
    }
}

void heapifyArray(int* arr, int len) {
    for (int i = len / 2; i >= 0; i--) {
        heapify(arr, len, i);
    }
}

long long pickGifts(int* gifts, int giftsSize, int k) {
    // Create and maintain heap for finding richest pile
    // Time: O(NlogN), Space: O(1)
    heapifyArray(gifts, giftsSize);
    while (k > 0) {
        int maxGifts = gifts[0]; // top of maxHeap
        if (maxGifts == 1) {break;} // sqrt(1) == 1, sum of gifts won't changed
        gifts[0] = sqrt(maxGifts);
        heapify(gifts, giftsSize, 0); // maintain the heap structure
        k--;
    }
    // Summing the remaining gifts
    long long result = 0;
    for (int i = 0; i < giftsSize; i++) {
        result += gifts[i];
    }
    return result;
}
// @lc code=end

