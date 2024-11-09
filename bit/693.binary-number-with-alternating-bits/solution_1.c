/*
 * @lc app=leetcode id=693 lang=c
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
#include <stdbool.h>

bool hasAlternatingBits(int n) {
    // Time: O(logn), Space: O(1)
    while (n >= 2) { // check two bits per interation
        // check if lsb and next bit are same
        if ((n & 1) == ((n >> 1) & 1)) {return false;}
        n >>= 1;
    }
    return true;
}
// @lc code=end

