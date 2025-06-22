/*
 * @lc app=leetcode id=2138 lang=c
 *
 * [2138] Divide a String Into Groups of Size k
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>

char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = strlen(s), groups = len / k + (len % k > 0);

    *returnSize = groups;
    char **result = malloc(groups * sizeof(char*));

    for (int i = 0; i < groups; i++) {
        result[i] = malloc((k + 1) * sizeof(char));
        for (int j = 0; j < k; j++) {
            if (i * k + j < len) {
                result[i][j] = s[i*k+j];
            } else {
                result[i][j] = fill;
            }
        }
        result[i][k] = '\0'; // Null terminator
    }


    return result;
}
// @lc code=end

