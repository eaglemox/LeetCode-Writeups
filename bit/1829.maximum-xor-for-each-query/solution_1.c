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
    // Find complement of xorSum of current array, nums[i] = [0, 2^maximumBit]
    // Time: O(N*M), Space: O(N), N: numsSize, M: maximumBit
    *returnSize = numsSize; 
    int *result = calloc(*returnSize, sizeof(int));
    int xorSum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorSum ^= nums[i];
        for (int bit = 0; bit < maximumBit; bit++) {
            // directly complement will result negative number
            result[(*returnSize-1)-i] |= (~xorSum & (1 << bit));
        }
    }
    return result;
}
// @lc code=end

