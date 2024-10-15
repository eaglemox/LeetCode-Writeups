/*
 * @lc app=leetcode id=2938 lang=c
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
#include <string.h>

long long minimumSteps(char* s) {
    int len = strlen(s);
    long long swapCount = 0;
    int blackCount = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            swapCount += blackCount;
        } else {
            blackCount++;
        }
    }
    return swapCount;
}
// @lc code=end

