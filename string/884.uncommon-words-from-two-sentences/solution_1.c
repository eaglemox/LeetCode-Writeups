/*
 * @lc app=leetcode id=884 lang=c
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void splitWords(char* s, char** words, int* size) {
    char *token = strtok(s, " ");
    while (token != NULL) {
        words[(*size)++] = token;
        token = strtok(NULL, " ");
    }
}
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    int size1 = 0, size2 = 0;
    char *words1[200], *words2[200];
    splitWords(s1, words1, &size1);
    splitWords(s2, words2, &size2);
    
    int uncommonIdx1 = 0, uncommonIdx2 = 0;
    char *uncommonWords1[200], *uncommonWords2[200];
    // Find uncommon words
    for (int i = 0; i < size1; i++) {
        int commonFound = 0;
        for (int j = 0; j < size2; j++) {
            if (strcmp(words1[i], words2[j]) == 0) {
                // printf("in string 2: %s: %d, %d\n", words1[i], i, j);
                commonFound = 1;
                break;
            }
        }
        for (int j = 0; j < size1; j++) {
            if (strcmp(words1[i], words1[j]) == 0) {
                // printf("common: %s: %d, %d\n", words1[i], i, j);
                commonFound++;
            }
        }
        if (commonFound == 1) { // count self
            // printf("%d word is uncommon\n", i);
            uncommonWords1[uncommonIdx1++] = words1[i];
        }
    }
    for (int i = 0; i < size2; i++) {
        int commonFound = 0;
        for (int j = 0; j < size1; j++) {
            if (strcmp(words2[i], words1[j]) == 0) {
                // printf("in string 1: %s: %d, %d\n", words2[i], i, j);
                commonFound = 1;
                break;
            }
        }
        for (int j = 0; j < size2; j++) {
            if (strcmp(words2[i], words2[j]) == 0) {
                // printf("common: %s: %d, %d\n", words2[i], i, j);
                commonFound++;
            }
        }
        if (commonFound == 1) { // count self
            // printf("%d word is uncommon\n", i);
            uncommonWords2[uncommonIdx2++] = words2[i];
        }
    }
    // for (int i = 0; i < uncommonIdx1; i++) {
    //     printf("%s ", uncommonWords1[i]);
    // }printf("\n");
    // for (int i = 0; i < uncommonIdx2; i++) {
    //     printf("%s ", uncommonWords2[i]);
    // }printf("\n");

    *returnSize = uncommonIdx1 + uncommonIdx2;
    char **result = malloc((*returnSize) * sizeof(char *));
    int temp = 0;
    for (int i = 0; i < uncommonIdx1; i++) {
        result[temp++] = uncommonWords1[i];
    }
    for (int i = 0; i < uncommonIdx2; i++) {
        result[temp++] = uncommonWords2[i];
    }
    return result;
}
// @lc code=end

