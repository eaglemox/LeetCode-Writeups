/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */

// @lc code=start
int missingNumber(int* nums, int numsSize) {
    // Compare sum of complete numbers and sun of nums
    // Time: O(N), Space: O(1)
    int totalSum = numsSize * (numsSize + 1) / 2;
    for (int i = 0; i < numsSize; i++) {
        totalSum -= nums[i];
    }
    return totalSum;
}
// @lc code=end

