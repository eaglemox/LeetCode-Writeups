/*
 * @lc app=leetcode id=1009 lang=c
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
int bitwiseComplement(int n) {
    // Same as 476 -> why leetcode has so many duplicate problems??
    // Time: O(32), Space: O(1)
    if (n == 0) {return 1;} // case n == 0
    unsigned int mask = 0xFFFFFFFF;
    while (mask & n) {
        mask <<= 1;
    }
    return ~mask ^ n;
}
// @lc code=end

