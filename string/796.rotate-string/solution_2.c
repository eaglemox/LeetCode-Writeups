/*
 * @lc app=leetcode id=796 lang=c
 *
 * [796] Rotate String
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool rotateString(char* s, char* goal) {
    // Sliding goal on the concatenated s+s string
    // Time: O(N), Space: O(N)
    int len = strlen(s);
    if (strlen(goal) != len) {return false;}
    char *doubleString = malloc((2 * len + 1) * sizeof(char));
    strncpy(doubleString, s, len + 1);
    strncat(doubleString, s, len);

    for (int i = 0; i < 2*len; i++) {
        bool sameOrder = true;
        for (int j = 0; j < len; j++) {
            if (doubleString[i+j] != goal[j]) {
                sameOrder = false;
                break;
            }
        }
        if (sameOrder) {return true;}
    }
    return false;
}
// @lc code=end

