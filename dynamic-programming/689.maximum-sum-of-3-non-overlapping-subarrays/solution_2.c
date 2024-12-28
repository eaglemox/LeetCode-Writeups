/*
 * @lc app=leetcode id=689 lang=c
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    // Sliding windows to find best start index of each subarray
    // Time: O(N+k), Space: O(1)
    *returnSize = 3;
    int *result = malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        result[i] = i * k;
    }
    // Sum of each subarray, maxSum up to subarray i
    int sum[3] = {0}, max[3] = {0};
    for (int i = 0; i < k; i++) {
        sum[0] += nums[i];
        sum[1] += nums[i+k];
        sum[2] += nums[i+2*k];
    }
    max[0] = sum[0];
    max[1] = max[0] + sum[1];
    max[2] = max[1] + sum[2];
    int index1 = 0, index2_1 = 0, index2_2 = k; // Indices for maxSum of N subarrays
    for (int i = 0; i <= numsSize - 3 * k; i++) { // first subarray's start index
        if (i > 0) { // update subarray sum
            for (int j = 0; j < 3; j++) {
                int out =  i + j * k - 1, in = out + k;
                sum[j] = sum[j] - nums[out] + nums[in];
            }
        }

        if (sum[0] > max[0]) {
            max[0] = sum[0];
            index1 = i;
        }
        if (max[0] + sum[1] > max[1]) {
            max[1] = max[0] + sum[1];
            index2_1 = index1;
            index2_2 = i + k; // second subarray
        }
        if (max[1] + sum[2] > max[2]) {
            max[2] = max[1] + sum[2];
            result[0] = index2_1;
            result[1] = index2_2;
            result[2] = i + 2 * k;
        }
    }
    return result;
}
// @lc code=end

