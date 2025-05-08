/*
 * @lc app=leetcode id=3370 lang=c
 *
 * [3370] Smallest Number With All Set Bits
 */

// @lc code=start
int smallestNumber(int n) {
    // The problem can be translated to: 
    // set all bits no greater than MSB of `n`
    // Time: O(sizeof(int)), Space: O(1)
    int mask = 1, result = n;
    while (mask < result) {
        result |= mask;
        mask <<= 1;
    }
    return result;
}
// @lc code=end

