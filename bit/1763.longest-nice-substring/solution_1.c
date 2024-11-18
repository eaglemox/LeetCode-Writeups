/*
 * @lc app=leetcode id=1763 lang=c
 *
 * [1763] Longest Nice Substring
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

char* longestNiceSubstring(char* s) {
    // The uppercase and lowercase character count must be both zero or non-zero
    // Brute force, Time: O(N^3), Space: O(1)
    int length = strlen(s);
    for (int len = length; len >= 2; len--) {
        for (int i = 0; i <= length - len; i++) {
            int upperCount[26] = {0}, lowerCount[26] = {0};
            for (int j = 0; j < len; j++) {
                if (s[i+j] > 'Z') {
                    lowerCount[s[i+j]-'a']++;
                } else {
                    upperCount[s[i+j]-'A']++;
                }
            }
            bool isNice = true;
            for (int i = 0; i < 26; i++) {
                if ((lowerCount[i] == 0) ^ (upperCount[i] == 0)) {
                    isNice = false;
                }
            }
            if (isNice) {
                s[i+len] = '\0';
                return s + i;
            }
        }
    }
    return "";
}
// @lc code=end

