/*
 * @lc app=leetcode id=1920 lang=c
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* buildArray(int* nums, int numsSize, int* returnSize) {
    // Copy and permute
    *returnSize = numsSize;
    if (numsSize == 1) {return nums;} // no other permutations
    int *result = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[nums[i]];
    }
    return result;
}
// @lc code=end

