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
    // Optimized the subsequence creation by reusing the character pointers of the original strings, avoiding additional string allocations.
    char **result = malloc(groupsSize * sizeof(char*));
    result[0] = words[0]; // reuse words' string (char*)

    *returnSize = 1;
    for (int i = 1; i < wordsSize; i++) {
        if (groups[i] == groups[i-1]) {
            continue;
        }
        result[(*returnSize)++] = words[i];
    }

    return result;
}
// @lc code=end

