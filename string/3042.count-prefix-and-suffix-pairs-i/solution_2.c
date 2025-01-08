/*
 * @lc app=leetcode id=3042 lang=c
 *
 * [3042] Count Prefix and Suffix Pairs I
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool isPrefixAndSuffix(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 > len2) {return false;}
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {return false;}
        if (str1[i] != str2[len2-len1+i]) {return false;}
    }
    return true;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    // The problem is to compute number pairs of words[i] is prefix & suffix
    // of words[j], and i < j.
    // Time: O(N^2*M), Space: O(1), M: wordMaxLength, N: wordsSize
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (isPrefixAndSuffix(words[i], words[j])) {count++;}
        }
    }
    return count;
}
// @lc code=end

