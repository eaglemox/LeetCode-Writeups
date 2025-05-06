/*
 * @lc app=leetcode id=1920 lang=c
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    // Store information of nums[i] and nums[nums[i]]
    // z = q * b + r, z/b = q, z%b = r, Optimize to Space: O(1)
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        nums[i] += (nums[nums[i]] % numsSize) * numsSize;
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] /= numsSize;
    }
    return nums;
}
// @lc code=end

