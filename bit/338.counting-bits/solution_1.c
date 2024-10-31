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
    // Time: O(NlogN), Space: O(N)
    *returnSize = n + 1; // 0 ~ n
    int *result = malloc(*returnSize * sizeof(int));

    for (int i = 0; i < *returnSize; i++) {
        int k = 0, count = 0;
        while (i >= (1 << k)) {
            if (i & (1 << k)) {count++;}
            k++;
        }
        result[i] = count;
    }
    return result;
}
// @lc code=end

