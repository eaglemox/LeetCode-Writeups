/*
 * @lc app=leetcode id=2109 lang=c
 *
 * [2109] Adding Spaces to a String
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>

char* addSpaces(char* s, int* spaces, int spacesSize) {
    // Time: O(N), Space: O(N)
    int length = strlen(s), newLength = length + spacesSize;
    int i = length - 1, j = newLength - 1, k = spacesSize - 1;
    char *result = malloc((newLength + 1) * sizeof(char));
    result[newLength] = '\0';
    // Copying string from the end
    while (i >= 0) {
        result[j--] = s[i];
        if (k >= 0 && i == spaces[k]) {
            result[j--] = ' ';
            k--;
        }
        i--;
    }
    return result;
}
// @lc code=end

