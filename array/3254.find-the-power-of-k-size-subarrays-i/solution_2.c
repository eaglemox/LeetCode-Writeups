/*
 * @lc app=leetcode id=3254 lang=c
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    // Count the number of consecutive numbers, when at least k 
    // consecutive numbers the power of subarray is nums[i]
    // Time: O(N), Space: O(N)
    *returnSize = numsSize - k + 1;
    int *result = malloc(*returnSize * sizeof(int));
    if (k == 1) {
        for (int i = 0; i < numsSize; i++) {
            result[i] = nums[i];
        }
        return result;
    }
    
    int consecutiveCount = 1;
    for (int i = 1; i < numsSize; i++) {
        consecutiveCount = (nums[i] == nums[i-1] + 1) ? consecutiveCount + 1 : 1;
        if (i >= k - 1) {
            result[i-k+1] = (consecutiveCount >= k) ? nums[i] : -1;
        }
    }
    return result;
}
// @lc code=end

