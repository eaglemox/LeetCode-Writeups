/*
 * @lc app=leetcode id=2559 lang=c
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>
#define max(a, b) ((a > b) ? a : b)

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u');
}

int isValid(char *s) {
    if (!isVowel(*s)) {return 0;}
    while (*++s); // Increment then de-reference
    return isVowel(*(s - 1)); // Last char before NULL
}

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Create a prefixSum of number of strings that start and end with vowel
    // For query [l,r] the return value is prefix[r+1] - prefix[l]
    // Time: O(M+N), Space: O(N), M: queriesSize, N: wordsSize
    int prefix[wordsSize+1];
    prefix[0] = 0;
    for (int i = 0; i < wordsSize; i++) {
        prefix[i+1] = prefix[i] + isValid(words[i]);
    }
    *returnSize = queriesSize;
    int *result = malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        result[i] = prefix[queries[i][1]+1] - prefix[queries[i][0]];
    }
    return result;
}
// @lc code=end

