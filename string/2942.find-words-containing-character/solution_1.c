/*
 * @lc app=leetcode id=2942 lang=c
 *
 * [2942] Find Words Containing Character
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    *returnSize = 0;
    int *result = malloc(wordsSize * sizeof(int));

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            if (words[i][j] == x) {
                result[(*returnSize)++] = i;
                break;
            }
        }
    }
    
    return result;
}
// @lc code=end

