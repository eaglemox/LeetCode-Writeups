/*
 * @lc app=leetcode id=1763 lang=c
 *
 * [1763] Longest Nice Substring
 */

// @lc code=start
#include <string.h>

char* longestNiceSubstring(char* s) {
    // The ascii code of uppercase and lowercase letters are 0b01CX XXXX (C: set for lowercase, X: 1~26)
    // Search the start and length, Time: O(N^2), Space: O(1)
    int length = strlen(s);
    int start, maxLength = 0;
    for (int i = 0; i < length; i++) {
        int lowerCase = 0, upperCase = 0; // bitmask represent letter appearance
        for (int j = i; j < length; j++) {
            if (s[j] > 'Z') {
                lowerCase |= 1 << (s[j] & 31);
            } else {
                upperCase |= 1 << (s[j] & 31);
            }
            // XOR not true and length is longer
            if (!(lowerCase ^ upperCase) && (j - i + 1) > maxLength) {
                maxLength = j - i + 1;
                start = i;
            }
        }
    }
    if (maxLength == 0) {return "";}
    
    s[start+maxLength] = '\0';
    return (s + start);
}
// @lc code=end

