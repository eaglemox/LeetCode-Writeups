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
    // To divide the array into subarrays of size 3 with the maximum difference between any two elements less than or equal to k,
    // we can use a greedy approach by selecting the smallest numbers from the sorted array.
    // For example, given a sorted array [a, b, c, d, e, f], choosing [a, b, c] and [d, e, f] ensures the smallest possible differences.
    int arrSize = numsSize / 3;
    int **result = malloc(arrSize * sizeof(int*));
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (int i = 0; i < arrSize; i++) {
        int first = i * 3, second = first + 1, third = first + 2;
        if (nums[third] - nums[first] > k) {
            for (int j = 0; j < i; j++) {
                free(result[j]);
            }
            free(result);
            *returnSize = 0;
            *returnColumnSizes = NULL;
            return NULL;
        }
        result[i] = malloc(3 * sizeof(int));
        result[i][0] = nums[first];
        result[i][1] = nums[second];
        result[i][2] = nums[third];
    }

    *returnSize = arrSize;
    (*returnColumnSizes) = malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}
// @lc code=end

