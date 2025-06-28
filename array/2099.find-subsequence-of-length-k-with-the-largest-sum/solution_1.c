/*
 * @lc app=leetcode id=2099 lang=c
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

void inplaceReplace(int* arr, int arrSize, int old, int new) {
    // Append new element at the end of array
    int i;
    while (i < arrSize && arr[i] != old) {
        i++;
    }
    while (i < arrSize - 1) {
        arr[i] = arr[i+1];
        i++;
    }
    arr[i] = new;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    // The problem eqivalent to find k-th max elements, we iterate throght the nums array
    // then swap out the min element in the subsequence with greater element in nums
    int min = 0x3f3f3f3f;
    int *result = malloc(k * sizeof(int));
    // Initial subsequence
    for (int i = 0; i < k; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        result[i] = nums[i];
    }
    for (int i = k; i < numsSize; i++) {
        if (nums[i] > min) {
            inplaceReplace(result, k, min, nums[i]);
            // Find next min
            min = result[0];
            for (int j = 1; j < k; j++) {
                if (result[j] < min) {
                    min = result[j];
                }
            }
        }
    }

    *returnSize = k;

    return result;
}
// @lc code=end

