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
    for (int i = 0; i < *returnSize; i++) {
        // right shift pass the carry info of i to right bit
        result[i] = i ^ (i >> 1);
    }
    return result;
}
// @lc code=end