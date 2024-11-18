/*
 * @lc app=leetcode id=1018 lang=c
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>

bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    // possible value [0, 2^10^5-1] but taking module can reduce the value while
    // having same result, e.g. [1,0,1,1,1] -> 1011 = 11 (mod 5 = 1), 10111 = 23 (mod 5 = 3)
    // Time: O(N), Space: O(N)
    *returnSize = numsSize;
    bool *divisible = malloc(*returnSize * sizeof(bool));
    long long current = 0;
    for (int i = 0; i < numsSize; i++) {
        divisible[i] = !(current = (current | nums[i]) % 5);
        current <<= 1;
    }

    return divisible;
}
// @lc code=end

