/*
 * @lc app=leetcode id=3442 lang=c
 *
 * [3442] Maximum Difference Between Even and Odd Frequency I
 */

// @lc code=start
#include <string.h>
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int maxDifference(char* s) {
    int len = strlen(s), maxOdd = 0, minEven = len;
    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        count[s[i]-'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] == 0) {continue;}
        if (count[i] & 1) {
            maxOdd = max(maxOdd, count[i]);
        } else { // Non-zero even count
            minEven = min(minEven, count[i]);
        }
    }

    return minEven < len ? maxOdd - minEven : maxOdd;
}
// @lc code=end

