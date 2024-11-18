/*
 * @lc app=leetcode id=1652 lang=c
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    // Sliding window approach, tracking the sum of each window
    // Time: O(N), Space: O(N), N: codeSize
    *returnSize = codeSize;
    int *result = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = 0;
    }
    if (k == 0) {return result;} // return 0 array
    int start, end, sum = 0;
    if (k > 0) {
        start = 1;
        end = k;
    } else {
        start = codeSize + k; // minus k 
        end = codeSize - 1;
    }
    // Initial window sum
    for (int i = start; i <= end; i++) {
        sum += code[i];
    }
    for (int i = 0; i < codeSize; i++) {
        result[i] = sum;
        // Slide the window to the right
        sum -= code[start++ % codeSize];
        sum += code[++end % codeSize];
    }

    return result;
}
// @lc code=end

