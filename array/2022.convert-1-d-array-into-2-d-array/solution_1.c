/*
 * @lc app=leetcode id=2022 lang=c
 *
 * [2022] Convert 1D Array Into 2D Array
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    // if impossible to reshape
    if (originalSize != (m * n)) {
        *returnSize = 0;
        return NULL;
    }
    // initialization
    *returnSize = m;
    int **result = malloc(m * sizeof(int *));
    *returnColumnSizes = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        result[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    for (int i = 0; i < originalSize; i++) {
        // printf("%d, %d: %d\n", row, col, original[i]);
        result[i / n][i % n] = original[i];
    }
    return result;
}
// @lc code=end

