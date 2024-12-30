/*
 * @lc app=leetcode id=2466 lang=c
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
#define MOD 1000000007 // 1e9+7

int countGoodStrings(int low, int high, int zero, int one) {
    // Similar to the stair problem, find the possible good strings within each length up to high
    // Time: O(N), Space: O(N), N: high [1, 1e5]
    int dp[high+1]; // [0, high]
    for (int i = 0; i <= high; i++) {dp[i] = 0;}
    for (int len = 1; len <= high; len++) {
        if (len >= zero) {
            dp[len] += dp[len-zero] + 1;
        }
        if (len >= one) {
            dp[len] += dp[len-one] + 1;
        }
        dp[len] %= MOD;
    }
    int result = dp[high] - dp[low-1];
    return (result < 0) ? result + MOD : result;
    // Direct computation of the result
    // return (dp[high] < dp[low-1]) ? dp[high] - dp[low-1] + MOD : dp[high] - dp[low-1];
}
// @lc code=end

