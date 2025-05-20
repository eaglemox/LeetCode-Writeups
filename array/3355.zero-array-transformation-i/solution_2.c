/*
 * @lc app=leetcode id=3355 lang=c
 *
 * [3355] Zero Array Transformation I
 */

// @lc code=start
#include <stdbool.h>

bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    // If a array is possible to be transformed into a zero array, each element must be less than the sum of queries covering its index.
    int maxDecrement = 0;
    int *range = calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        range[queries[i][0]]++;
        range[queries[i][1]+1]--; // r+1 is out of the range 
    }

    for (int i = 0; i < numsSize; i++) {
        maxDecrement += range[i];
        if (nums[i] > maxDecrement) {
            return false;
        }
    }

    return true;
}
// @lc code=end

