/*
 * @lc app=leetcode id=3264 lang=c
 *
 * [3264] Final Array State After K Multiplication Operations I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    // Brute force find min number each multiplication
    // Time: O(k*N), Space: O(1)
    *returnSize = numsSize;
    while (k--) {
        int minIndex = 0;
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        nums[minIndex] *= multiplier;
    }
    return nums;
}
// @lc code=end

