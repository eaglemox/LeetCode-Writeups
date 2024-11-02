/*
 * @lc app=leetcode id=342 lang=c
 *
 * [342] Power of Four
 */

// @lc code=start
#include <stdbool.h>

bool isPowerOfFour(int n) {
    // Check if n is the power of some number and it's multiple of 4
    // Time: O(1), Space: O(1)
    return n > 0 && !(n & n - 1) && !((n - 1) % 3);
}
// @lc code=end

