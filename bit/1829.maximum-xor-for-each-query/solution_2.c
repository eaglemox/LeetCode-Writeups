/*
 * @lc app=leetcode id=1829 lang=c
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    // Return the non-negative integers k[i] < 2^maximumBit that maximize nums[0:numsSize-1-i]
    // The maximum of any nums is 2^maximumBit - 1, xorSum ^ k[i] = max -> k[i] = xorSum ^ max
    // Time: O(N), Space: O(N), N: numsSize
    *returnSize = numsSize; 
    int *result = malloc(*returnSize * sizeof(int));
    int xorSum = 0, max = (1 << maximumBit) - 1;
    for (int i = 0; i < numsSize; i++) {
        xorSum ^= nums[i];
        result[(*returnSize-1)-i] = xorSum ^ max;
    }
    return result;
}
// @lc code=end

