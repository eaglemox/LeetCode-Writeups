/*
 * @lc app=leetcode id=2311 lang=c
 *
 * [2311] Longest Binary Subsequence Less Than or Equal to K
 */

// @lc code=start
#include <string.h>

int longestSubsequence(char* s, int k) {
    // We can greedily remove the leftmost '1' in s that will result in longest subsequence
    // If s.length is large enough -> Runtime error (leftshift cause val overflow)
    int bits = strlen(s);
    long long val = 0;

    for (int i = 0; i < bits; i++) {
        val <<= 1;
        val += (s[i] - '0');
    }

    while (val > k) {
        for (int i = bits; i >= 0; i--) {
            long long x = 1LL << i;
            if (val & x) {
                val -= x;
                bits--;
                break;
            }
        }
    }

    return bits;
}
// @lc code=end

