/*
 * @lc app=leetcode id=916 lang=c
 *
 * [916] Word Subsets
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max(a, b) ((a > b) ? a : b)

bool isUniversal(const int* freq1, const int* freq2) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] < freq2[i]) {return false;}
    }
    return true;
}

char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    // Time: O(M*N), Space: O(1), M: wordsLength, N: wordsSize
    int maxFreq[26] = {0};
    for (int i = 0; i < words2Size; i++) {
        int freq[26] = {0}, len = strlen(words2[i]);
        for (int j = 0; j < len; j++) {
            int current = words2[i][j] - 'a';
            maxFreq[current] = max(maxFreq[current], ++freq[current]);
        }
    }
    *returnSize = 0;
    char **result = malloc(words1Size * sizeof(char *));
    for (int i = 0; i < words1Size; i++) {
        int freq[26] = {0}, len = strlen(words1[i]);
        for (int j = 0; j < len; j++) {
            freq[words1[i][j]-'a']++;
        }
        if (isUniversal(&freq, &maxFreq)) {
            result[(*returnSize)++] = words1[i];
        }
    }
    return result;
}
// @lc code=end

