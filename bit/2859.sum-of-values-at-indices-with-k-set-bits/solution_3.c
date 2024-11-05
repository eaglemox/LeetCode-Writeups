/*
 * @lc app=leetcode id=2859 lang=c
 *
 * [2859] Sum of Values at Indices With K Set Bits
 */

// @lc code=start
int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    // Sum with builtin function
    // Time: O(N), Space: O(1)
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (__builtin_popcount(i) == k) {
            sum += nums[i];
        }
    }
    return sum;
}
// @lc code=end

