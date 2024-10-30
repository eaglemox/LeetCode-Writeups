/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

// @lc code=start
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    // Not loops, check all bits simultaneously
    // Time: O(1), Space: O(1)
    return n > 0 && !(n & n - 1);
}
// @lc code=end

