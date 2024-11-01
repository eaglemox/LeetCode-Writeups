/*
 * @lc app=leetcode id=1957 lang=c
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>

char* makeFancyString(char* s) {
    // Two pointer method, overwrite character with s itself
    // Time: O(N), Space: O(1)
    int j = 2, len = strlen(s);
    for (int i = 2; i < len; i++) {
        // overwrite "fancy" part of the string
        if (s[i] != s[j-1] || s[i] != s[j-2]) {
            s[j++] = s[i];
        }
    }
    char *result = malloc((j + 1) * sizeof(char));
    strncpy(result, s, j);
    s[j] = '\0';
    return s;
}
// @lc code=end

