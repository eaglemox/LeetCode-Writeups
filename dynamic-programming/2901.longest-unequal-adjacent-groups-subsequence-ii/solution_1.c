/*
 * @lc app=leetcode id=2901 lang=c
 *
 * [2901] Longest Unequal Adjacent Groups Subsequence II
 */

// @lc code=start
#include <string.h>
#define max(a, b) ((a > b) ? a : b)

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
    int dp[wordsSize];
    for (int i = 0; i < wordsSize; i++) {
        dp[i] = 1;
    }

    int maxIndex = 0;
    for (int i = 1; i < wordsSize; i++) { // O(N^2)
        for (int j = i - 1; j >= 0; j--) {
            if (groups[i] == groups[j] || 
                hammingDist(words[i], words[j]) != 1) {continue;}
            dp[i] = max(dp[i], dp[j] + 1);
        }
        if (dp[i] >= dp[maxIndex]) {maxIndex = i;}
    }

    // result[0:dp[maxIndex]-1]
    *returnSize = dp[maxIndex];
    char **result = malloc(dp[maxIndex] * sizeof(char*));
    
    result[dp[maxIndex]-1] = words[maxIndex];
    for (int i = maxIndex - 1, j = dp[maxIndex] - 2, prev = maxIndex; i >= 0 && j >= 0; i--) { // trace backward
        if (dp[i] + 1 != dp[prev] ||
            groups[i] == groups[prev] ||
            hammingDist(words[i], words[prev]) != 1) {continue;}
        result[j--] = words[i];
        prev = i;
    }
    
    return result;
}
// @lc code=end

