/*
 * @lc app=leetcode id=476 lang=c
 *
 * [476] Number Complement
 */

// @lc code=start
int findComplement(int num) {
    // Using mask and AND to find effective complement bits of num
    // Time: O(32), Space: O(1)
    unsigned int mask = 0xFFFFFFFF;
    while (mask & num) {mask <<= 1;}
    return ~mask & ~num;
}
// @lc code=end

