/*
 * @lc app=leetcode id=476 lang=c
 *
 * [476] Number Complement
 */

// @lc code=start
int findComplement(int num) {
    // Fill in each bit with complement value of num
    // Time: O(32), Space: O(1)
    int shift = 0, complement = 0;
    while (num > 0) {
        complement |= !(num & 1) << shift;
        shift++;
        num >>= 1;
    }

    return complement;
}
// @lc code=end

