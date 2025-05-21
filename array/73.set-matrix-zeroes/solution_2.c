/*
 * @lc app=leetcode id=73 lang=c
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    // With O(1) constant space
    int m = matrixSize, n = matrixColSize[0];
    
    int col0Zero = 0; // to distinguish zero is contributed by row or col
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {col0Zero = 1;}
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // start of row
                matrix[0][j] = 0; // start of col
            }
        }
    }

    // bc. we use row/col start as indicator, we must update the matrix backward
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if (col0Zero) {matrix[i][0] = 0;}
    }
}
// @lc code=end

