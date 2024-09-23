/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */

// @lc code=start
int climbStairs(int n) {
    // recursion
    if (n < 2) {return 1;}
    return climbStairs(n - 1) + climbStairs(n - 2);
}
// @lc code=end

