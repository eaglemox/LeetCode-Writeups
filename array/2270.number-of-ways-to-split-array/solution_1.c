/*
 * @lc app=leetcode id=2270 lang=c
 *
 * [2270] Number of Ways to Split Array
 */

// @lc code=start
int waysToSplitArray(int* nums, int numsSize) {
    // Time: O(N), Space: O(1)
    long long leftSum = 0, totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    int validWays = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        leftSum += nums[i];
        if (leftSum >= (totalSum - leftSum)) {validWays++;}
    }
    return validWays;
}
// @lc code=end

