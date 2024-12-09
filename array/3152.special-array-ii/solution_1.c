/*
 * @lc app=leetcode id=3152 lang=c
 *
 * [3152] Special Array II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>

bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Mark each special subarray with a index, if the index of start and end of a query it's a special subarray
    // Time: O(M+N), Space: O(N), N: numsSize, M: queriesSize
    int *specialIndex = malloc(numsSize * sizeof(int));
    specialIndex[0] = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] % 2 == nums[i-1] % 2) { // same parity -> new index
            specialIndex[i] = specialIndex[i-1] + 1;
        } else {
            specialIndex[i] = specialIndex[i-1];
        }
    }
    *returnSize = queriesSize;
    bool *result = malloc(queriesSize * sizeof(bool));
    for (int i = 0; i < queriesSize; i++) {
        result[i] = specialIndex[queries[i][0]] == specialIndex[queries[i][1]];
    }
    return result;
}
// @lc code=end

