/*
 * @lc app=leetcode id=796 lang=c
 *
 * [796] Rotate String
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool rotateString(char* s, char* goal) {
    // KMP algorithm
    // Time: O(N), Space: O(N)
    int len = strlen(s);
    if (strlen(goal) != len) {return false;}
    short *lps = malloc(len * sizeof(short)); // length from 1~100
    lps[0] = 0;
    // Build fail function / LPS
    for (int i = 1, pos = 0; i < len;) {
        if (goal[i] == goal[pos]) {
            lps[i++] = ++pos;
        } else if (pos != 0) {
            pos = lps[pos-1];
        } else {
            lps[i++] = 0;
        }
    }

    char *doubleString = malloc((2 * len + 1) * sizeof(char));
    strncpy(doubleString, s, len + 1);
    strncat(doubleString, s, len);
    for (int i = 0, j = 0; i < 2 * len;) {
        if (doubleString[i] == goal[j]) {
            i++;
            j++;
            if (j == len) {return true;}
        } else if (j > 0) { // next element to check
            j = lps[j-1];
        } else { // j == 0
            i++;
        }
    }
    
    return false;
}
// @lc code=end

