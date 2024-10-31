/*
 * @lc app=leetcode id=338 lang=c
 *
 * [338] Counting Bits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int* countBits(int n, int* returnSize) {
    // Number of '1' bits is the sum of the '1' bits in 
    // the first k bits and the '1' bit in the LSB
    // Time: O(N), Space: O(N)
    *returnSize = n + 1; // 0 ~ n
    int *result = malloc(*returnSize * sizeof(int));
    result[0] = 0;
    for (int i = 0; i < *returnSize; i++) {
        result[i] = result[i >> 1] + (i & 1);
    }
    return result;
}
// @lc code=end

