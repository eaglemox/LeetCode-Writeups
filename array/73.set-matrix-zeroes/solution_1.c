/*
 * @lc app=leetcode id=73 lang=c
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    // Naive solution: find all rows, cols that contain zero, then update the matrix
    int m = matrixSize, n = matrixColSize[0];
    int zeroRows[m], zeroCols[n];
    memset(zeroRows, 0, sizeof(zeroRows));
    memset(zeroCols, 0, sizeof(zeroCols));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0 && (!zeroRows[i] || !zeroCols[j])) {
                zeroRows[i] = 1;
                zeroCols[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (zeroRows[i] || zeroCols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}
// @lc code=end

