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
#include <stdbool.h>

void swapStr(char** a, char** b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

char* isSubstring(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 > len2) { // make str1 the shorter string
        swapInt(&len1, &len2);
        swapStr(&str1, &str2);
    }
    int i = 0, j;
    while (i < len2 - len1 + 1) {
        j = 0;
        while (j < len1 && str1[j] == str2[i+j]) {j++;}
        if (j == len1) {return str1;}
        i++;
    }
    return NULL;
}

char** stringMatching(char** words, int wordsSize, int* returnSize) {
    // Brute force check all words if they are substring of other word
    // Time: O(M^2*N^2), Space: O(N), M: wordLength, N: wordsSize
    *returnSize = 0;
    bool visited[wordsSize];
    memset(visited, false, sizeof(visited));
    char **result = malloc(wordsSize * sizeof(char *));
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            char *subStr;
            if (subStr = isSubstring(words[i], words[j])) {
                int subIndex = (subStr == words[i]) ? i : j;
                if (visited[subIndex]) {continue;}

                int subLen = strlen(subStr) + 1;
                result[*returnSize] = malloc(subLen * sizeof(char));
                strncpy(result[(*returnSize)++], subStr, subLen);
                visited[subIndex] = true;
            }
        }
    }
    return result;
}
// @lc code=end

