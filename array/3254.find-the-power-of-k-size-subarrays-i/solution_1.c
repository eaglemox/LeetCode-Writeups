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
    // If i-th num is not consecutive and ascending, the next k-1 power will be -1
    // My spaghetti approach, Time: O(N), Space: O(N)
    if (k == 1) {return nums;} // no need to check
    *returnSize = numsSize - k + 1;
    int *result = malloc(*returnSize * sizeof(int));
    
    int negatives = 0;
    for (int i = 1; i < numsSize; i++) {
        // Check how many '-1' we need to mark
        negatives = (nums[i] != nums[i-1] + 1) ? k - 1 : negatives;
        while (i < numsSize && negatives > 0) { // This is so bad
            if (i >= k - 1) {
                result[i-k+1] = -1;
            }
            negatives--;
            i++;
            if (i < numsSize) {
                negatives = (nums[i] != nums[i-1] + 1) ? k - 1 : negatives;
            }
        }
        // The part that satisfy the constraint
        if (i >= k - 1 && i < numsSize) {
            result[i-k+1] = nums[i];
        }
    }
    return result;
}
// @lc code=end

