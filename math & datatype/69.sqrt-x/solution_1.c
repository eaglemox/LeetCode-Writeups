/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start
int mySqrt(int x) {
    // x: [0, 2^31 - 1] sqrt(x): [0, 46340.95...]
    int i = 1;
    while (((i * i) < x) && i < 46340) {i++;}
    return (i * i > x) ? i-1 : i;
}
// @lc code=end

