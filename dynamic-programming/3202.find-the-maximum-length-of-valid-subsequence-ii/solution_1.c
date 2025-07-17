/*
 * @lc app=leetcode id=3202 lang=c
 *
 * [3202] Find the Maximum Length of Valid Subsequence II
 */

// @lc code=start
int maximumLength(int* nums, int numsSize, int k) {
    // Different from previous problem, the modulus is change to arbitrary number k within range [1, 1e3]
    // Let dp[i] is the maximum length of possible subsequence that end with element y, such that y % k = i
    // To append a new element z to the subsequence [..., x, y], (y + z) % k = (x + y) % k = r
    // y = ((r - z) % k + k) % k (prevent negative value)
    // Update dp[z] -> dp[z] + 1
    int dp[k];
    int result = 0;

    for (int r = 0; r < k; r++) {
        for (int i = 0; i < k; i++) {dp[i] = 0;}
        for (int i = 0; i < numsSize; i++) {
            int z = nums[i];
            int y = ((r - z) % k + k) % k;
            
            dp[z%k] = dp[y] + 1;
            if (dp[z%k] > result) {result = dp[z%k];}
        }

    }

    return result;
}
// @lc code=end

