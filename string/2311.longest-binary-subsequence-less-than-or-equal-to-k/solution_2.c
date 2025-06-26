/*
 * @lc app=leetcode id=2311 lang=c
 *
 * [2311] Longest Binary Subsequence Less Than or Equal to K
 */

// @lc code=start
#include <string.h>

int longestSubsequence(char* s, int k) {
    // We construct the result of sol.1 from LSB to MSB and bacause k is within [1, 1e9] overflow will not happen
    int i, n = strlen(s), bit = 1, val = 0, size = 0;

    for (i = n - 1; i >= 0 && val + bit <= k; i--) {
        if (s[i] == '1') {
            val += bit;
        }
        size++;
        bit <<= 1;
    }

    while (i >= 0) {
        if (s[i] == '0') size++;
        i--;
    }

    return size;
}
// @lc code=end

