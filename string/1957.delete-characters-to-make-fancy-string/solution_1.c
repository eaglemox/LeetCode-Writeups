/*
 * @lc app=leetcode id=1957 lang=c
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
#include <string.h>

char* makeFancyString(char* s) {
    // Count and remove duplicates from string -> TLE
    int len = strlen(s), count = 0;
    char prev = s[0];
    for (int i = 1; i < len; i++) {
        if (s[i] == prev) {count++;}
        else {
            prev = s[i];
            count = 0;
        }
        if (count == 2) {
            int j = i + 1;
            while (j < len && s[j] == prev) {
                j++;
            }
            memmove(&s[i], &s[j], len - j + 1);
            count = 0;
            len -= j - i;
            prev = s[i];
        }
    }
    return s;
}
// @lc code=end

