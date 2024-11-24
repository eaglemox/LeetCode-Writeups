/*
 * @lc app=leetcode id=1975 lang=c
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
#define min(a, b) ((a < b) ? a : b)

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    // If even negative numbers, all of them can be converted into positive numbers
    // If odd negative numbers, we can reduce to only 1 negative number and transfer to 
    // the number with smallest absolute value, Time: O(M*N), Space: O(1)
    int negativeCount = 0, minAbs = 100000;
    long long matrixSum = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            negativeCount += matrix[i][j] < 0;
            int absolute = (matrix[i][j] < 0) ? -matrix[i][j] : matrix[i][j];
            matrixSum += absolute;
            minAbs = min(minAbs, absolute);
        }
    }
    if (negativeCount % 2) { // odd
        matrixSum -= 2 * minAbs;
    }

    return matrixSum;
}
// @lc code=end

