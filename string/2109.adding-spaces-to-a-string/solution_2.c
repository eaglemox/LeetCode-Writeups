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
    int i = 0, j = 0, k = 0;
    char *result = malloc((newLength + 1) * sizeof(char));
    result[newLength] = '\0';
    // Copying string from the start
    while (i < length) {
        if (k < spacesSize && i == spaces[k]) {
            result[j++] = ' ';
            k++;
        }
        result[j++] = s[i++];
    }
    return result;
}
// @lc code=end

