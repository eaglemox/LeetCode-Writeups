/*
 * @lc app=leetcode id=1310 lang=c
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// #include <stdio.h>
#include <stdlib.h>
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Using prefix sum to reduce time complexity  
    *returnSize = queriesSize;
    int *result = malloc(*returnSize * sizeof(int));
    // Creating prefix XOR sum of arr
    int prefix[arrSize];
    prefix[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        prefix[i] = prefix[i-1] ^ arr[i];
    }
    // Queries
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0], right = queries[i][1];
        // printf("query: %d, %d\n", arr[left], arr[right]);
        if (left == right) {
            result[i] = arr[left];
        } else if (left < right) {
            if (left == 0) {
                result[i] = prefix[right];
            } else {
                // XOR same element will result in 0
                result[i] = prefix[right] ^ prefix[left-1];
            }
        }
    }
    return result;
}
// @lc code=end

