/*
 * @lc app=leetcode id=89 lang=c
 *
 * [89] Gray Code
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    // Arrange a array with 0 ~ 2^n-1, each adjacent differ by one bit
    // The number of integer with i and n-i bit set is same
    // Time: O(2^N), Space: O(2^N)
    *returnSize = (1 << n);
    int *result = malloc(*returnSize * sizeof(int));
    result[0] = 0;
    for (int i = 1; i < *returnSize; i++) {
        if (i % 2) { // even (1 start) -> toggle lsb
            result[i] = result[i-1] ^ (result[i-1] & 1);
        } else { // odd (1 start) -> toggle next bit of first setbit
            int pos = 0;
            while (!(result[i-1] & (1 << pos))) {
                pos++;
            }
            result[i] = result[i-1] ^ (result[i-1] & (1 << pos));
        }
    }
    return result;
}
// @lc code=end

