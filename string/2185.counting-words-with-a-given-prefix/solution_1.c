/*
 * @lc app=leetcode id=2185 lang=c
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
#include <string.h>

int prefixCount(char** words, int wordsSize, char* pref) {
    // Check all words if pref is the prefix of them
    // Time: O(M*N), Space: O(1), M: prefLength, N: wordsSize
    int count = 0, len = strlen(pref);
    for (int i = 0, j; i < wordsSize; i++) {
        for (j = 0; j < len; j++) {
            if (words[i][j] != pref[j]) {
                break;
            }
        }
        if (j == len) {count++;}
    }
    return count;
}
// @lc code=end

