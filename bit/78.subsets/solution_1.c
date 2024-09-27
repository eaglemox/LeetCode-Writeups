/*
 * @lc app=leetcode id=78 lang=c
 *
 * [78] Subsets
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 1 << numsSize; // 2^n
    int **result = malloc( (*returnSize) * sizeof(int *));
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize; i++) { // chosen index 000 -> 111
        result[i] = malloc(numsSize * sizeof(int));
        (*returnColumnSizes)[i] = 0;
        for (int pos = 0; pos < numsSize; pos++) { // bit pos
            if (i & (1 << pos)) { // if the number is chosen, add to array
                result[i][(*returnColumnSizes)[i]++] = nums[pos];
            }
        }
    }

    return result;
}
// @lc code=end

