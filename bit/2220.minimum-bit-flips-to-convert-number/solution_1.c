/*
 * @lc app=leetcode id=2220 lang=c
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
// #include <stdio.h>
int minBitFlips(int start, int goal) {
    int count = 0;
    for (int i = 31; i >= 0; i--) { // int: 32-bit, 4 byte
        if (((start >> i) & 1) != ((goal >> i) & 1)) {
            count++;
        }
    }
    // for (int i = 31; i >= 0; i--) {
    //     printf("%u ", (start >> i) & 1);
    // }printf("\n");
    // for (int i = 31; i >= 0; i--) {
    //     printf("%u ", (goal >> i) & 1);
    // }printf("\n");
    return count;
}
// @lc code=end

