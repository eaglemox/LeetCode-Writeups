/*
 * @lc app=leetcode id=401 lang=c
 *
 * [401] Binary Watch
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

char** readBinaryWatch(int turnedOn, int* returnSize) {
    // Naive approach
    *returnSize = 0;
    char **result = malloc(128 * sizeof(char*)); // max 10 choose 5, 252 combinations
    for (int hr = 0; hr < 12; hr++) {
        for (int min = 0; min < 60; min++) {
            if (countBits(hr) + countBits(min) == turnedOn) {
                int len = (hr < 10) ? 5 : 6;
                result[*returnSize] = malloc(len * sizeof(char));
                sprintf(result[*returnSize], "%d:%02d", hr, min);
                (*returnSize)++;
            }
        }
    }
    return result;
}

int countBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
// @lc code=end

