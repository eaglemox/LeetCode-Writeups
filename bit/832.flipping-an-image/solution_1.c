/*
 * @lc app=leetcode id=832 lang=c
 *
 * [832] Flipping an Image
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    // The image is square: n == imageSize == imageColSize[i]
    // After flip each row of the image are reversed
    *returnSize = imageSize;
    *returnColumnSizes = malloc(imageSize * sizeof(int));
    int **result = malloc(imageSize * sizeof(int *));
    
    for (int i = 0; i < imageSize; i ++) {
        (*returnColumnSizes)[i] = imageSize;
        result[i] = malloc(imageSize * sizeof(int));
        // Each column index of the row (0~imageColSize[i])
        for (int j = 0; j < imageSize; j++) {
            result[i][imageSize-1-j] = 1 ^ image[i][j]; // invert the value
        }
    }
    return result;
}
// @lc code=end

