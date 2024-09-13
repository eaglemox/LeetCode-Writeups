/*
 * @lc app=leetcode id=1310 lang=c
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // When handling query with large range, looping from left to right is time consuming -> TLE on testcase #42  
    *returnSize = queriesSize;
    int *result = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0], right = queries[i][1];
        // printf("query: %d, %d\n", arr[left], arr[right]);
        result[i] = arr[left];
        for (left = left+1; left <= right; left++) {
            result[i] = result[i] ^ arr[left];
        }
    }
    return result;
}
// @lc code=end

