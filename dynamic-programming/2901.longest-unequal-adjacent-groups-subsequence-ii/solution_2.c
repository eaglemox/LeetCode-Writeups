/*
 * @lc app=leetcode id=2901 lang=c
 *
 * [2901] Longest Unequal Adjacent Groups Subsequence II
 */

// @lc code=start
#include <string.h>

int hammingDist(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) {return -1;}
    
    int dist = 0;
    for (int i = 0; str1[i] && str2[i]; i++) {
        dist += (str1[i] != str2[i]);
    }

    return dist;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** getWordsInLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    // Using DP to find which subsequence is the longest
    int dp[wordsSize], prev[wordsSize];
    for (int i = 0; i < wordsSize; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }

    int maxIndex = 0;
    for (int i = 1; i < wordsSize; i++) { // O(N^2)
        for (int j = 0; j < i; j++) {
            if (groups[i] == groups[j] || 
                hammingDist(words[i], words[j]) != 1) {continue;}
            if (dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] >= dp[maxIndex]) {maxIndex = i;}
    }

    // result[0:dp[maxIndex]-1]
    *returnSize = dp[maxIndex];
    char **result = malloc(dp[maxIndex] * sizeof(char*));
    
    int cur = maxIndex;
    for (int i = *returnSize - 1; i >= 0; i--) {
        result[i] = words[cur];
        cur = prev[cur];
    }
    
    return result;
}
// @lc code=end

