/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = malloc(numRows * sizeof(int));
    int **pascalsTriangle = malloc(numRows * sizeof(int *));
    for (int i = 0; i < numRows; i++) {
        // *(*returnColumnSizes + i) = i+1;
        (*returnColumnSizes)[i] = i+1;
        pascalsTriangle[i] = malloc((i + 1) * sizeof(int));
        for (int j = 0; j < (i + 1); j++) {
            if (j == 0 || j == i) {
                pascalsTriangle[i][j] = 1;
            } else {
                pascalsTriangle[i][j] = pascalsTriangle[i-1][j-1] + pascalsTriangle[i-1][j]; 
            }
        }
    }
    return pascalsTriangle;
}
// @lc code=end

