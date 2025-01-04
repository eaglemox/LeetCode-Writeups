/*
 * @lc app=leetcode id=1930 lang=c
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
#include <string.h>

int countBits(int num) {
    int oneBits = 0;
    while (num) {
        if (num & 1) {oneBits++;}
        num >>= 1;
    }
    return oneBits;
}

int countPalindromicSubsequence(char* s) {
    // The palindrome of length 3 is the combination of the same start and end character 
    // and a middle character. We fixed the start and end character the contribution to the
    // total count is the unique choices between the first and last index.
    // Time: O(N+26N), Space: O(26)
    int result = 0;
    int len = strlen(s), freq[26] = {0};
    for (int i = 0; i < len; i++) {
        freq[s[i]-'a']++;
    }
    // Compute how many unique characters between the range
    for (int letter = 0; letter < 26; letter++) {
        if (freq[letter] < 2) {continue;}
        int i = 0, j = len - 1;
        while ((s[i]-'a') != letter) {i++;} // First appearance index of letter
        while ((s[j]-'a') != letter) {j--;} // Last appearance index of letter
        int letterMask = 0; // i-th bit set representing the i-th letter exist between (i,j)
        for (int k = i + 1; k < j; k++) {
            letterMask |= 1 << (s[k]-'a');
        }
        result += countBits(letterMask);
    }
    return result;
}
// @lc code=end

