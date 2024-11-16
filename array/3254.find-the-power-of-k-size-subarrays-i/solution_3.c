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
#include <stdbool.h>

int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    // Brute force, check all elements in each sliding window is
    // consecutive and in ascending order
    // Time: O(Nk), Space: O(N)
    *returnSize = numsSize - k + 1;
    int *result = malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < numsSize - k + 1; i++) {
        bool isConsecutive = true;
        for (int j = i; j < i + k - 1; j++) {
            if (nums[j+1] != nums[j] + 1) {
                isConsecutive = false;
            }
        }
        result[i] = isConsecutive ? nums[i+k-1] : -1;
    }
    return result;
}
// @lc code=end