/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include <stdint.h>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            char bit = (n >> i) & 1;
            result |= bit << (31 - i);
        }
        return result;
    }
};
// @lc code=end

