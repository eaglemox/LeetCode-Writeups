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

void picknumber(int** subsets, int* subset, int idx, int len, int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // subsets[(*returnSize)++] = subset;
    for (int i = idx; i < numsSize; i++) {
        printf("current set #%d\n", *returnSize);
        subset[len] = nums[i];
        subsets[*returnSize] = malloc((len+1) * sizeof(int));
        memcpy(subsets[*returnSize], subset, (len + 1) * sizeof(int));
        // for (int j = 0; j < len+1; j++) {
        //     printf("%d ", subsets[*returnSize][j]);
        // }
        // printf("\n");
        (*returnColumnSizes)[*returnSize] = len + 1;
        (*returnSize)++;
        picknumber(subsets, subset, i + 1, len + 1, nums, numsSize, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Recursion approach
    *returnSize = 0; // 2^n
    int **result = malloc((1 << numsSize) * sizeof(int *));
    *returnColumnSizes = calloc((1 << numsSize), sizeof(int));
    int *subset = malloc(numsSize * sizeof(int));
    result[0] = NULL; //empty set
    (*returnColumnSizes)[(*returnSize)++] = 0;
    picknumber(result, subset, 0, 0, nums, numsSize, returnSize, returnColumnSizes);

    return result;
}
// @lc code=end

