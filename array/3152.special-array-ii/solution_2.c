/*
 * @lc app=leetcode id=3152 lang=c
 *
 * [3152] Special Array II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>
#define max(a, b) ((a > b) ? a : b)

bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Sliding window, finding the special range of each start index
    // Time: O(M+N), Space: O(N), N: numsSize, M: queriesSize
    int *specialRange = malloc(numsSize * sizeof(int));
    for (int start = 0, end = 0; start < numsSize;) {
        end = max(end, start);
        while (end < numsSize - 1 && nums[end] % 2 != nums[end+1] % 2) {end++;}
        while (start <= end) { // the max spcial range of indices [start, end] is "end"
            specialRange[start++] = end;
        }
    }

    *returnSize = queriesSize;
    bool *result = malloc(queriesSize * sizeof(bool));
    for (int i = 0; i < queriesSize; i++) {
        result[i] = queries[i][1] <= specialRange[queries[i][0]];
    }
    return result;
}
// @lc code=end

