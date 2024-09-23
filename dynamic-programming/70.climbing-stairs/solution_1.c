/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */

// @lc code=start
int climbStairs(int n) {
    // dynamic programming - tabulation
    if (n < 2) {return n;}
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        // methods sum of 1 step + ... and 2 step + ...
        dp[i] = dp[i-1] + dp[i-2];
    }    
    
    return dp[n];
}
// @lc code=end

