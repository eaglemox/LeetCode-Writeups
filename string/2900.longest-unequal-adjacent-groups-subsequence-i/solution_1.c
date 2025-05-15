/*
 * @lc app=leetcode id=2900 lang=c
 *
 * [2900] Longest Unequal Adjacent Groups Subsequence I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>

char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    // Create a subsequence by selecting strings from each consecutive group.
    char **result = malloc(groupsSize * sizeof(char*));
    result[0] = malloc((strlen(words[0]) + 1) * sizeof(char));
    strcpy(result[0], words[0]);

    *returnSize = 1;
    for (int i = 1; i < wordsSize; i++) {
        if (groups[i] == groups[i-1]) {
            continue;
        }
        result[*returnSize] = malloc((strlen(words[i]) + 1) * sizeof(char));
        strcpy(result[*returnSize], words[i]);
        (*returnSize)++;
    }

    return result;
}
// @lc code=end

