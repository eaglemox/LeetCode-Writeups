/*
 * @lc app=leetcode id=1408 lang=c
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

char** stringMatching(char** words, int wordsSize, int* returnSize) {
    // Find substrings using STL function
    // Time: O(M*N^2), Space: O(N), M: wordLength, N: wordsSize
    *returnSize = 0;
    char **result = malloc(wordsSize * sizeof(char *));
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (!words[i] || !words[j]) {continue;}
            int len1 = strlen(words[i]), len2 = strlen(words[j]); 
            if (len1 > len2 && strstr(words[i], words[j])) {
                result[(*returnSize)++] = words[j];
                words[j] = NULL; // Prevent repeat substrings
            } else if (strstr(words[j], words[i])) {
                result[(*returnSize)++] = words[i];
                words[i] = NULL; // Prevent repeat substrings
            }
        }
    }
    return result;
}
// @lc code=end

