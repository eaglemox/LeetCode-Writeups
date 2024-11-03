/*
 * @lc app=leetcode id=796 lang=c
 *
 * [796] Rotate String
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool rotateString(char* s, char* goal) {
    // Rotate s and compare
    // Time: O(N^2), Space: O(1)
    int i = 0, len = strlen(s);
    while (i < len) {
        bool sameOrder = true;
        for (int k = 0; k < len; k++) {
            if (s[(i+k) % len] != goal[k]) {
                sameOrder = false;
                i++;
                break;
            }
        }
        if (sameOrder) {return true;}
    }
    return false;
}
// @lc code=end

