/*
 * @lc app=leetcode id=2825 lang=c
 *
 * [2825] Make String a Subsequence Using Cyclic Increments
 */

// @lc code=start
#include <stdbool.h>

bool canMakeSubsequence(char* str1, char* str2) {
    // Two pointer cheching if str1 can match str2
    // Time: O(N), Space: O(1)
    char nextChar;
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        nextChar = (str1[i] == 'z') ? 'a' : str1[i] + 1;
        if (str1[i] == str2[j] || nextChar == str2[j]) {j++;}
        if (str2[j] == '\0') {return true;}
        i++;
    }
    return false;
}
// @lc code=end

