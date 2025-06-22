/*
 * @lc app=leetcode id=2138 lang=c
 *
 * [2138] Divide a String Into Groups of Size k
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = strlen(s), groups = (len + k - 1) / k; // Ceiling

    *returnSize = groups;
    char **result = malloc(groups * sizeof(char*));

    for (int i = 0, idx = 0; i < groups; i++) {
        result[i] = malloc((k + 1) * sizeof(char));

        if (idx + k <= len) {
            snprintf(result[i], k + 1, "%s", s + idx);
        } else {
            snprintf(result[i], len - idx + 1, "%s", s + idx);
            for (int j = len - idx; j < k; j++) {
                result[i][j] = fill;
            }
            result[i][k] = '\0';
        }
        idx += k;
    }

    return result;
}
// @lc code=end

