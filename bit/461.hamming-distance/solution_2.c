/*
 * @lc app=leetcode id=461 lang=c
 *
 * [461] Hamming Distance
 */

// @lc code=start
int hammingDistance(int x, int y) {
    // Cheating with builtin func
    // Time: O(1), Space: O(1)
    return __builtin_popcount(x ^ y);
}
// @lc code=end

