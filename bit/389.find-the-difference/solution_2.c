/*
 * @lc app=leetcode id=389 lang=c
 *
 * [389] Find the Difference
 */

// @lc code=start
#include <string.h>

char findTheDifference(char* s, char* t) {
    // Bit manipulation (XOR) approach, compute the XOR sum of s and t
    // Time: O(N), Space: O(1)
    int xorSum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        xorSum ^= s[i];
    }
    for (int i = 0; t[i] != '\0'; i++) {
        xorSum ^= t[i];
    }
    return xorSum;
}
// @lc code=end

