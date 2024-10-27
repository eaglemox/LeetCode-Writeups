/*
 * @lc app=leetcode id=190 lang=c
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include <stdint.h>
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (uint8_t i = 0; i < 32; i++) {
        uint32_t bit = (n >> i) & 1;
        result |= bit << (31 - i);
    }
    return result;
}
// @lc code=end

