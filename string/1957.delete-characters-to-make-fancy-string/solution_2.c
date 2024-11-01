/*
 * @lc app=leetcode id=1957 lang=c
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>

char* makeFancyString(char* s) {
    // Make new string without more than two consective character
    // Time: O(N), Space: O(N)
    int j = 1, count = 0, len = strlen(s);
    char *result = malloc((len + 1) * sizeof(char));
    result[0] = s[0];
    char prev = s[0];
    for (int i = 1; i < len; i++) {
        if (s[i] == prev) {count++;}
        else {
            prev = s[i];
            count = 0;
        }
        if (count < 2) {
            result[j++] = s[i];
        }
    }
    result[j] = '\0';
    return result;
}
// @lc code=end

