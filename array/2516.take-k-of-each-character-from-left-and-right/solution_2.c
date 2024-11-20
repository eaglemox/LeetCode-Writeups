/*
 * @lc app=leetcode id=2516 lang=c
 *
 * [2516] Take K of Each Character From Left and Right
 */

// @lc code=start
#include <string.h>
#define max(a, b) ((a > b) ? a : b)

int takeCharacters(char* s, int k) {
    // Two pointer approach to track the indices of substring's start and end
    // Optimize the counting process
    // Time: O(N), Space: O(1)
    int length = strlen(s);
    int maxLength = 0;
    int count[3] = {0};

    for (int i = 0; i < length; i++) {
        count[s[i]-'a']++;
    }
    // Impossible to take any character
    for (int i = 0; i < 3; i++) {
        if (count[i] < k) {return -1;}
    }
    // Count  : aabaaaacaabc
    // Remove : aabaaaa
    // Add    : aab
    // Desired: aab    caabc
    int i = 0, j = 0; // right minus, left add
    while (j < length) {
        if (--count[s[j]-'a'] < k) {
            // Make up for removed characters
            while (count[s[j]-'a'] < k) {
                count[s[i++]-'a']++;
            }
        } else { // Update the max substring length
            maxLength = max(maxLength, j - i + 1);
        }
        j++;
    }
    return length - maxLength;
}
// @lc code=end

