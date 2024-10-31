/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */

// @lc code=start
int missingNumber(int* nums, int numsSize) {
    // Compute XOR sum of nums and complete numbers
    // Time: O(N), Space: O(1)
    int totalSum = numsSize;
    for (int i = 0; i < numsSize; i++) {
        totalSum ^= nums[i];
        totalSum ^= i;
    }
    return totalSum;
}
// @lc code=end

