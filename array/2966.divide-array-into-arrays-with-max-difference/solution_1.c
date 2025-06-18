/*
 * @lc app=leetcode id=2966 lang=c
 *
 * [2966] Divide Array Into Arrays With Max Difference
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    // To divide the array in to arrays of size 3 with difference of each two elements less than or equal to k
    // We can take a greedily approach to choose numbers from sorted array
    // Assume a sorted array [a, b, c, d, e, f], it's guarentee that choose [a, b, c] [d, e, f] will have lower difference
    // than [a, b, d] [c, e, f]
    *returnSize = numsSize / 3;
    int **result = malloc((*returnSize) * sizeof(int*));
    (*returnColumnSizes) = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < (*returnSize); i++) {
        result[i] = malloc(3 * sizeof(int));
        (*returnColumnSizes)[i] = 3;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0, j = 0; i < numsSize && j < (*returnSize); i += 3, j++) {
        if (nums[i+2] - nums[i] > k) {
            *returnSize = 0;
            break;
        }
        result[j][0] = nums[i];
        result[j][1] = nums[i+1];
        result[j][2] = nums[i+2];
    }

    return result;
}// @lc code=end

