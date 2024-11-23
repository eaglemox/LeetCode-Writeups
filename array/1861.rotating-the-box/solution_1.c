/*
 * @lc app=leetcode id=1861 lang=c
 *
 * [1861] Rotating the Box
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes){
    // Two pointer approach to fill the rotatedBox from the bottom
    // Time: O(M*N), Space: O(M*N)
    *returnSize = boxColSize[0];
    char **rotatedBox = malloc(*returnSize * sizeof(char *));
    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = boxSize;
        rotatedBox[i] = malloc(boxSize * sizeof(char));
    }

    for (int i = 0; i < boxSize; i++) {
        int j = boxColSize[i] - 1, k = boxColSize[i] - 1;
        while (j >= 0) {
            if (box[i][j] == '*') {
                while (k > j) {
                    rotatedBox[k--][boxSize-1-i] = '.';
                }
                rotatedBox[k--][boxSize-1-i] = '*';
            } else if (box[i][j] == '#') {
                rotatedBox[k--][boxSize-1-i] = '#';
            }
            j--;
        }
        while (k >= 0) { // Fill empty slots
            rotatedBox[k--][boxSize-1-i] = '.';
        }
    }

    return rotatedBox;
}
// @lc code=end

