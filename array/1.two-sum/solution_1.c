/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Time: O(N-1 + N-2 + ... + 1) = O(N^2) Space: O(1)
    *returnSize = 2;
    int *result = malloc(*returnSize * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++) {
        int residual = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == residual) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;    
}
// @lc code=end

