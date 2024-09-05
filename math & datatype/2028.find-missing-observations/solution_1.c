/*
 * @lc app=leetcode id=2028 lang=c
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    // m = rollsSize
    int *missings = malloc(n * sizeof(int));
    int sum = 0;
    for (int i = 0; i < rollsSize; i++) {
        sum += rolls[i];
    }
    printf("%d rolls, sum: %d\n", rollsSize, sum);
    int diff = (mean * (rollsSize + n) - sum);
    int remain = diff % n; 
    if (diff > (6 * n) || diff < n) { // mean that cannot be satisfied with six-sided dice [1, 6]
        *returnSize = 0;
        return NULL;
    } else {
        for (int i = 0; i < n; i++) {
            missings[i] = diff / n;
            if (remain > 0) {
                missings[i] += 1;
                remain--;
            }
        }
    }
    *returnSize = n;
    return missings;
}
// @lc code=end

