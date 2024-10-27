/*
 * @lc app=leetcode id=191 lang=c
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
int hammingWeight(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
// @lc code=end

