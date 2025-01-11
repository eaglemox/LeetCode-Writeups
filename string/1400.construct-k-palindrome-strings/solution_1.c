/*
 * @lc app=leetcode id=1400 lang=c
 *
 * [1400] Construct K Palindrome Strings
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

int countBits(int num) {
    int count = 0;
    while (num) {
        count += (1 & num);
        num >>= 1;
    }
    return count;
}

bool canConstruct(char* s, int k) {
    // The palindromes are not necessarily substring of s. That is, only frequency of each character matters
    // The minimum number of palindrome is the number of odd frequency characters
    // minPalindromes <= k <= length
    // Time: O(N), Space: O(1)
    int len = strlen(s), oddMask = 0;
    if (len < k) {return false;} // more than number of characters
    for (int i = 0; i < len; i++) {
        oddMask ^= (1 << (s[i] - 'a'));
    }
    return countBits(oddMask) <= k;
}
// @lc code=end

