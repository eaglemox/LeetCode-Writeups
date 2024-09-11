/*
 * @lc app=leetcode id=2220 lang=c
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
int minBitFlips(int start, int goal) {
    int xor = start ^ goal, count = 0;
    // xor will equal to 0 after all different bits are shifted right
    while (xor > 0) {
        count += xor & 1; // add 1 if least significant is 1
        xor >>= 1; // right shift 1 bit
    }

    return count;
}
// @lc code=end

